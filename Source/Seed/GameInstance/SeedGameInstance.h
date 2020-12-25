// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SeedGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SEED_API USeedGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	
	UPROPERTY()
	class AClientTcpSocketConnection* ClientTcpSocketConnection = nullptr;
};
