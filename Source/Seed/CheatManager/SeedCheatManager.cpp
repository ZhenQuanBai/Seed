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
					TArray<uint8> RequestData;
					RequestData.Init(0, length);
					Request.SerializeToArray(RequestData.GetData(), length);
					int64 PreambleCode = 0x00F0F0F0F0F0F0F8;
					int32 MsgID = 0;

					TArray<uint8> FmtData;
					FmtData.Init(0, 16);
					FMemory::Memcpy(FmtData.GetData(), &PreambleCode, 8);
					FMemory::Memcpy(FmtData.GetData() + 8, &length, 4);
					FMemory::Memcpy(FmtData.GetData() + 12, &MsgID, 4);
					FmtData.Append(RequestData.GetData(), length);
					SeedGameInstance->ClientTcpSocketConnection->SendData(0, FmtData);
				}
			}
		}
	}
}
