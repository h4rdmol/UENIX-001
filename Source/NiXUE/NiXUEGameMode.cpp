// Copyright Epic Games, Inc. All Rights Reserved.

#include "NiXUEGameMode.h"
#include "NiXUECharacter.h"
#include "UObject/ConstructorHelpers.h"

ANiXUEGameMode::ANiXUEGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
