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

	// Has key item 1
	bool HasKey1{ false };

	// Has key item 2
	bool HasKey2{ false };

	// Has key item 3
	bool HasKey3{ false };

	// Key 1 is active
	bool KeyActive1{ false };

	// Key 2 is active
	bool KeyActive2{ false };

	// Key 3 is active
	bool KeyActive3{ false };

	// Pressure type 1 activated
	int PressureCounter1{ 0 };

	// Pressure type 2 activated
	int PressureCounter2{ 0 };

	// Pressure type 3 activated
	int PressureCounter3{ 0 };

	// Can press door button 1
	bool DoorButtonActive1{ false };

	// Initial door button 1 state
	bool DoorActive1{ false };

	// Can press door button 2
	bool DoorButtonActive2{ false };

	// Initial door button 2 state
	bool DoorActive2{ false };

	// Can press door button 3
	bool DoorButtonActive3{ false };

	// Initial door button 3 state
	bool DoorActive3{ false };

	// Can press door button 4
	bool DoorButtonActive4{ false };

	// Initial door button 4 state
	bool DoorActive4{ false };

	// Can press door button 5
	bool DoorButtonActive5{ false };

	// Initial door button 5 state
	bool DoorActive5{ false };

	// Can press door button 6
	bool DoorButtonActive6{ false };

	// Initial door button 6 state
	bool DoorActive6{ false };

	// Can press door button 7
	bool DoorButtonActive7{ false };

	// Initial door button 7 state
	bool DoorActive7{ false };

	// Can press door button 8
	bool DoorButtonActive8{ false };

	// Initial door button 8 state
	bool DoorActive8{ false };

	// Can press door button 9
	bool DoorButtonActive9{ false };

	// Initial door button 9 state
	bool DoorActive9{ false };

	// Can press door button 10
	bool DoorButtonActive10{ false };

	// Initial door button 10 state
	bool DoorActive10{ false };

	// Can press passcode button 1
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PassCodeButton1{ false };

	// Can press passcode button 2
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PassCodeButton2{ false };

	// Can press passcode button 3
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PassCodeButton3{ false };

	// Can press passcode button 4
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool PassCodeButton4{ false };

	// Initial pass code 1 number
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PassCode1{ 1 };

	// Initial pass code 2 number
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PassCode2{ 1 };

	// Initial pass code 3 number
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PassCode3{ 1 };

	// Initial pass code 4 number
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PassCode4{ 1 };

	void ChangePassCode1();

	void ChangePassCode2();

	void ChangePassCode3();

	void ChangePassCode4();

};
