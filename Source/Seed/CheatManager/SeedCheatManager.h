// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "SeedCheatManager.generated.h"

/**
 * 
 */
UCLASS()
class SEED_API USeedCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void TestSendProtobufMsgToServer();
};
