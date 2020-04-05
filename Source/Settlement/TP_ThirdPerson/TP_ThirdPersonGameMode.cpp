// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TP_ThirdPersonGameMode.h"
#include "TP_ThirdPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"




ATP_ThirdPersonGameMode::ATP_ThirdPersonGameMode()
{



	//*
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn>PlayerPawnBPClass(TEXT( "/Game/ThirdPersonCPP/Blueprints/TP" ));

	static UClass *PlayerPawnBPClass = ATP_ThirdPersonCharacter::StaticClass();

	//UClass::Find

	//static ConstructorHelpers::F

	//if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass;
	}
	//*/
}
