// Copyright Epic Games, Inc. All Rights Reserved.


#include "SeedGameModeBase.h"
#include "PbFiles/Test.pb.h"


ASeedGameModeBase::ASeedGameModeBase()
{
	SearchRequest Request;

	Request.set_query("test");
	Request.set_page_number(1);
	Request.set_result_per_page(2);

	const std::string Message = Request.SerializeAsString();

	UE_LOG(LogTemp, Display, TEXT("Test protobuf, Request size[%d]."), Message.size());
}
