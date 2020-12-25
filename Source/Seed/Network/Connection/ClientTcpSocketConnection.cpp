// Fill out your copyright notice in the Description page of Project Settings.


#include "Network/Connection/ClientTcpSocketConnection.h"

#include "PbFiles/Test.pb.h"

void AClientTcpSocketConnection::ConnectToGameServer() {
	if (isConnected(connectionIdGameServer))
	{
		return;
	}
	FTcpSocketDisconnectDelegate disconnectDelegate;
	disconnectDelegate.BindDynamic(this, &AClientTcpSocketConnection::OnDisconnected);
	FTcpSocketConnectDelegate connectDelegate;
	connectDelegate.BindDynamic(this, &AClientTcpSocketConnection::OnConnected);
	FTcpSocketReceivedMessageDelegate receivedDelegate;
	receivedDelegate.BindDynamic(this, &AClientTcpSocketConnection::OnMessageReceived);
	Connect("127.0.0.1", 5000, disconnectDelegate, connectDelegate, receivedDelegate, connectionIdGameServer);
}

void AClientTcpSocketConnection::OnConnected(int32 ConId) {
	UE_LOG(LogTemp, Log, TEXT("Log: Connected to server."));
}

void AClientTcpSocketConnection::OnDisconnected(int32 ConId) {
	UE_LOG(LogTemp, Log, TEXT("Log: OnDisconnected."));
}

void AClientTcpSocketConnection::OnMessageReceived(int32 ConId, TArray<uint8>& Message) {
	UE_LOG(LogTemp, Log, TEXT("Log: Received message. "));
	// read expected length
	if(Message.Num() > 16)
	{
		int64 PreambleCode;
		int32 Length;
		int32 MsgID;
		FMemory::Memcpy(&PreambleCode, Message.GetData(), 8);
		FMemory::Memcpy(&Length, Message.GetData() + 8, 4);
		FMemory::Memcpy(&MsgID, Message.GetData() + 12, 4);
		SearchRequest Request;
		Request.ParseFromArray(Message.GetData() + 16, Length);
		UE_LOG(LogTemp, Log, TEXT("Log: Received message. %d"), MsgID);
	}
}