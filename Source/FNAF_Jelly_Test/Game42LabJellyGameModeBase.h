// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Game42LabJellyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FNAF_JELLY_TEST_API AGame42LabJellyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	// Has key item
	bool HasKey{ false };

	// Key is active
	bool KeyActive{ false };

	// Pressure activated
	int PressureCounter{ 0 };

	// Can press door button 
	bool DoorButtonActive{ false };

	// Initial door button state
	bool DoorActive{ false };

};
