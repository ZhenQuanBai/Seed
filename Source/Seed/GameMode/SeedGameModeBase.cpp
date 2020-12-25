// Copyright Epic Games, Inc. All Rights Reserved.


#include "GameMode/SeedGameModeBase.h"
#include "PlayerController/SeedPlayerControllerBase.h"


ASeedGameModeBase::ASeedGameModeBase()
{
	PlayerControllerClass = ASeedPlayerControllerBase::StaticClass();
}
