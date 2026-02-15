// Copyright (c) 2026 [Sadik Bal / Barbaros Games]. All Rights Reserved.This code and its modular components are the sole property of the developer. Unauthorized copying of this file, via any medium, is strictly prohibited.


#include "Pawn/BoranPawn.h"

// Sets default values
ABoranPawn::ABoranPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoranPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoranPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABoranPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

