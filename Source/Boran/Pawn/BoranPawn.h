// Copyright (c) 2026 [Sadik Bal / Barbaros Games]. All Rights Reserved.This code and its modular components are the sole property of the developer. Unauthorized copying of this file, via any medium, is strictly prohibited.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BoranPawn.generated.h"

UCLASS()
class BORAN_API ABoranPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABoranPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
