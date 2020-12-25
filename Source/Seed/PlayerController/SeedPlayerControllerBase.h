// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SeedPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class SEED_API ASeedPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	ASeedPlayerControllerBase(const FObjectInitializer& ObjectInitializer);
};
