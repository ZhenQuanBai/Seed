// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/SeedPlayerControllerBase.h"

#include "CheatManager/SeedCheatManager.h"


ASeedPlayerControllerBase::ASeedPlayerControllerBase(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer)
{
	CheatClass = USeedCheatManager::StaticClass();
}
