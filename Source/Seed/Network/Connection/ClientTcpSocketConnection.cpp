// Fill out your copyright notice in the Description page of Project Settings.


#include "Network/Connection/ClientTcpSocketConnection.h"

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
	UE_LOG(LogTemp, Log, TEXT("Log: Received message."));
	// In this example, we always encode messages a certain way:
	// The first 4 bytes contain the length of the rest of the message.
	while (Message.Num() != 0) {
		// read expected length
		int32 msgLength = Message_ReadInt(Message);
		if (msgLength == -1) // when we can't read 4 bytes, the method returns -1
			return;
		TArray<uint8> yourMessage;
		// read the message itself
		if (!Message_ReadBytes(msgLength, Message, yourMessage)) {
			// If it couldn't read expected number of bytes, something went wrong.
			// Print a UE_LOG here, while your project is in development.
			continue;
		}
		// If the message was read, then treat "yourMessage" here!
		// ...
		// And then we go back to the "while", because we may have received multiple messages in a frame, 
		// so they all have to be read.
	}
}