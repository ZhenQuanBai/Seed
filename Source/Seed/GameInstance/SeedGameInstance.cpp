// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance/SeedGameInstance.h"

#include "Network/Connection/ClientTcpSocketConnection.h"

void USeedGameInstance::Init()
{
	Super::Init();

	if(UWorld* const World = GetWorld()) // get a reference to the world  
	{
		if(AActor* Actor = World->SpawnActor(AClientTcpSocketConnection::StaticClass()))
		{
			ClientTcpSocketConnection = Cast<AClientTcpSocketConnection>(Actor);
			if(ClientTcpSocketConnection)
			{
				ClientTcpSocketConnection->ConnectToGameServer();
			}
		}
	}
}
