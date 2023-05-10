// Copyright Epic Games, Inc. All Rights Reserved.


#include "Game42LabJellyGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// On pass code 1 button used, increase code by 1 up to 4. If the code try to go over 4, reset number back to 1. 
void AGame42LabJellyGameModeBase::ChangePassCode1()
{


	if (PassCode1 == 4)
	{
		PassCode1 = 1;
	}
	else if (PassCode1 < 4)
	{

		PassCode1 += 1;
	}


}

// On pass code 2 button used, increase code by 1 up to 4. If the code try to go over 4, reset number back to 1. 
void AGame42LabJellyGameModeBase::ChangePassCode2()
{


	if (PassCode2 == 4)
	{
		PassCode2 = 1;
	}
	else if (PassCode2 < 4)
	{

		PassCode2 += 1;
	}


}

// On pass code 3 button used, increase code by 1 up to 4. If the code try to go over 4, reset number back to 1. 
void AGame42LabJellyGameModeBase::ChangePassCode3()
{


	if (PassCode3 == 4)
	{
		PassCode3 = 1;
	}
	else if (PassCode3 < 4)
	{

		PassCode3 += 1;
	}

}

// On pass code 4 button used, increase code by 1 up to 4. If the code try to go over 4, reset number back to 1. 
void AGame42LabJellyGameModeBase::ChangePassCode4()
{


	if (PassCode4 == 4)
	{
		PassCode4 = 1;
	}
	else if (PassCode4 < 4)
	{

		PassCode4 += 1;
	}

}
