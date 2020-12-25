// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TcpSocketConnection.h"
#include "ClientTcpSocketConnection.generated.h"

/**
 * 
 */
UCLASS()
class SEED_API AClientTcpSocketConnection : public ATcpSocketConnection
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnConnected(int32 ConnectionId);

	UFUNCTION()
	void OnDisconnected(int32 ConId);

	UFUNCTION()
	void OnMessageReceived(int32 ConId, TArray<uint8>& Message);

	UFUNCTION(BlueprintCallable)
	void ConnectToGameServer();

	UPROPERTY()
	int32 connectionIdGameServer;
};
