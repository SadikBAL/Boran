// Copyright Epic Games, Inc. All Rights Reserved.


#include "StrategyCharacter.h"
#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SphereComponent.h"
#include "Navigation/PathFollowingComponent.h"

AStrategyCharacter::AStrategyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// ensure this unit has a valid AI controller to handle move requests
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	// create the interaction range sphere
	InteractionRange = CreateDefaultSubobject<USphereComponent>(TEXT("Interaction Range"));
	InteractionRange->SetupAttachment(RootComponent);

	InteractionRange->SetSphereRadius(100.0f);
	InteractionRange->SetCollisionProfileName(FName("OverlapAllDynamic"));

	// configure movement
	GetCharacterMovement()->GravityScale = 1.5f;
	GetCharacterMovement()->MaxAcceleration = 1000.0f;
	GetCharacterMovement()->BrakingFrictionFactor = 1.0f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.0f;
	GetCharacterMovement()->PerchRadiusThreshold = 20.0f;
	GetCharacterMovement()->bUseFlatBaseForFloorChecks = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f);
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->AvoidanceConsiderationRadius = 150.0f;
	GetCharacterMovement()->AvoidanceWeight = 1.0f;
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->SetFixedBrakingDistance(200.0f);
	GetCharacterMovement()->SetFixedBrakingDistance(true);
}

void AStrategyCharacter::NotifyControllerChanged()
{
	// validate and save a copy of the AI controller reference
	AIController = Cast<AAIController>(Controller);
	
	if (AIController)
	{
		// subscribe to the move finished handler on the path following component
		UPathFollowingComponent* PFComp = AIController->GetPathFollowingComponent();
		if (PFComp)
		{
			PFComp->OnRequestFinished.AddUObject(this, &AStrategyCharacter::OnMoveFinished);
		}
	}
}

void AStrategyCharacter::StopMoving()
{
	// use the character movement component to stop movement
	GetCharacterMovement()->StopMovementImmediately();
}

void AStrategyCharacter::UnitSelected()
{
	// pass control to BP
	BP_UnitSelected();
}

void AStrategyCharacter::UnitDeselected()
{
	// pass control to BP
	BP_UnitDeselected();
}

void AStrategyCharacter::Interact(AStrategyCharacter* Interactor)
{
	// ensure the interactor is valid
	if (IsValid(Interactor))
	{
		// rotate towards the actor we're interacting with
		SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Interactor->GetActorLocation()));

		// signal the interactor to play its interaction behavior
		Interactor->BP_InteractionBehavior(this);

		// play our own interaction behavior
		BP_InteractionBehavior(Interactor);
	}
	
}

bool AStrategyCharacter::MoveToLocation(const FVector& Location, float AcceptanceRadius)
{
	// ensure we have a valid AI Controller
	if (AIController)
	{
		// set up the AI Move Request
		FAIMoveRequest MoveReq;

		MoveReq.SetGoalLocation(Location);
		MoveReq.SetAcceptanceRadius(AcceptanceRadius);
		MoveReq.SetAllowPartialPath(true);
		MoveReq.SetUsePathfinding(true);
		MoveReq.SetProjectGoalLocation(true);
		MoveReq.SetRequireNavigableEndLocation(true);
		MoveReq.SetNavigationFilter(AIController->GetDefaultNavigationFilterClass());
		MoveReq.SetCanStrafe(false);

		// request a move to the AI Controller
		FNavPathSharedPtr FollowedPath;
		const FPathFollowingRequestResult ResultData = AIController->MoveTo(MoveReq, &FollowedPath);
		
		// check the move result
		switch (ResultData.Code)
		{
			// failed. Return false
			case EPathFollowingRequestResult::Failed:

				return false;
				break;

			// already at goal. Return true and call the move completed delegate
			case EPathFollowingRequestResult::AlreadyAtGoal:

				OnMoveCompleted.Broadcast(this);
				return true;
				break;

			// move successfully scheduled. Return true
			case EPathFollowingRequestResult::RequestSuccessful:

				return true;
				break;
		}
	}

	// the move could not be completed
	return false;
}

void AStrategyCharacter::OnMoveFinished(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	// call the delegate
	OnMoveCompleted.Broadcast(this);
}
