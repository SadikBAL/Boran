// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoranGameMode.h"

#include "BoranCharacter.h"
#include "BoranGameState.h"
#include "BoranHUD.h"
#include "BoranPlayerController.h"
#include "BoranPlayerState.h"
#include "BoranSpectatorPawn.h"

ABoranGameMode::ABoranGameMode()
{
	DefaultPawnClass = ABoranCharacter::StaticClass();
	PlayerControllerClass = ABoranPlayerController::StaticClass();
	PlayerStateClass = ABoranPlayerState::StaticClass();
	GameStateClass = ABoranGameState::StaticClass();
	HUDClass = ABoranHUD::StaticClass();
	SpectatorClass = ABoranSpectatorPawn::StaticClass();
}
