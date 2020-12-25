// Fill out your copyright notice in the Description page of Project Settings.


#include "CheatManager/SeedCheatManager.h"
#include "GameInstance/SeedGameInstance.h"
#include "Network/Connection/ClientTcpSocketConnection.h"
#include "PbFiles/Test.pb.h"


void USeedCheatManager::TestSendProtobufMsgToServer()
{
	if (UWorld* World = GetWorld())
	{
		if(UGameInstance* GameInstance = World->GetGameInstance())
		{
			if (USeedGameInstance* SeedGameInstance = Cast<USeedGameInstance>(GameInstance))
			{
				if (SeedGameInstance->ClientTcpSocketConnection)
				{
					SearchRequest Request;

					Request.set_query("test");
					Request.set_page_number(1);
					Request.set_result_per_page(2);

					int32 length = Request.ByteSize();
					TArray<uint8> Buf;
					Buf.Init(0, length);
					Request.SerializeToArray(Buf.GetData(), length);

					SeedGameInstance->ClientTcpSocketConnection->SendData(0, Buf);
				}
			}
		}
	}
}
