// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "DoorKey.h"
#include "DoorButton.h"
#include "CodeLock1.h"
#include "CodeLock2.h"
#include "CodeLock3.h"
#include "CodeLock4.h"
#include "Game42LabJellyGameModeBase.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initial player jump height
	JumpHeightVelocity = 500.0f;

	// Intiial player jump cooldown timer
	JumpCooldownTimer = 0;

	// Initial player start jump cooldown
	PlayerStartJumpCooldown = false;

	// Initial player jumped
	PlayerJumped = false;

	// Initial run energy
	RunEnergy = 200.0f;

	// Intiial player running
	PlayerRunning = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// Set player speed
	GetCharacterMovement()->MaxWalkSpeed = 450.f;

	// Set player run energy
	RunEnergy = 200.0f;
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Jump cooldown
	if (JumpCooldownTimer == 80)
	{
		PlayerStartJumpCooldown = false;
		PlayerJumped = false;
		JumpCooldownTimer = 0;
	}
	else if (PlayerStartJumpCooldown == true)
	{
		JumpCooldownTimer += 1;
	}
	// Run energy recovery
	if (RunEnergy > 200 && PlayerRunning == false)
	{
		RunEnergy = 200;
	}
	else if (RunEnergy < 200 && PlayerRunning == false)
	{
		RunEnergy += 1.0f;
		GetCharacterMovement()->MaxWalkSpeed = 450.0f;
	}
	// Run mechanics
	if (PlayerRunning == true && RunEnergy > 0)
	{
		RunEnergy -= 1.0f;
		GetCharacterMovement()->MaxWalkSpeed = 900.0f;
	}
	else if (RunEnergy == 0)
	{
		PlayerRunning = false;
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Call on MoveForwardBackWard on input
	PlayerInputComponent->BindAxis("ForwardBackward", this, &APlayerCharacter::MoveForwardBackward);

	// Call on MoveRightLeft on input
	PlayerInputComponent->BindAxis("RightLeft", this, &APlayerCharacter::MoveRightLeft);

	// On input, make player look right or left
	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerCharacter::AddControllerYawInput);

	// On input, make player look up or down
	PlayerInputComponent->BindAxis("Vertical", this, &APlayerCharacter::AddControllerPitchInput);

	// Call on PlayerJump on input pressed
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::PlayerJump);

	// Call on StartJumpCooldown on input released
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::StartJumpCooldown);

	// Call on UseObject on input pressed
	PlayerInputComponent->BindAction("Use", IE_Pressed, this, &APlayerCharacter::UseObject);

	// Call on StopUsingObject on input released
	PlayerInputComponent->BindAction("Use", IE_Released, this, &APlayerCharacter::StopUsingObject);

	// Call on PlayerStartRunning on input pressed
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &APlayerCharacter::PlayerStartRunning);

	// Call on PlayerStopRunning on input released
	PlayerInputComponent->BindAction("Run", IE_Released, this, &APlayerCharacter::PlayerStopRunning);
}

// Press "E" to Use nearby object / collect item
void APlayerCharacter::UseObject()
{
	AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode->KeyActive1 == true)
	{
		GameMode->HasKey1 = true;
	}

	if (GameMode->KeyActive2 == true)
	{
		GameMode->HasKey2 = true;
	}

	if (GameMode->KeyActive3 == true)
	{
		GameMode->HasKey3 = true;
	}

	if (GameMode->DoorButtonActive1 == true)
	{
		GameMode->DoorActive1 = true;

	}

	if (GameMode->DoorButtonActive2 == true)
	{
		GameMode->DoorActive2 = true;

	}

	if (GameMode->DoorButtonActive3 == true)
	{
		GameMode->DoorActive3 = true;

	}

	if (GameMode->DoorButtonActive4 == true)
	{
		GameMode->DoorActive4 = true;

	}

	if (GameMode->DoorButtonActive5 == true)
	{
		GameMode->DoorActive5 = true;

	}

	if (GameMode->DoorButtonActive6 == true)
	{
		GameMode->DoorActive6 = true;

	}

	if (GameMode->DoorButtonActive7 == true)
	{
		GameMode->DoorActive7 = true;

	}

	if (GameMode->DoorButtonActive8 == true)
	{
		GameMode->DoorActive8 = true;

	}

	if (GameMode->DoorButtonActive9 == true)
	{
		GameMode->DoorActive9 = true;

	}

	if (GameMode->DoorButtonActive10 == true)
	{
		GameMode->DoorActive10 = true;

	}
	if (GameMode->PassCodeButton1 == true)
	{
		for (TObjectIterator<ACodeLock1> Itr; Itr; ++Itr)
		{
			if (Itr->IsA(ACodeLock1::StaticClass()))
			{
				ACodeLock1* CodeLock1 = *Itr;
				CodeLock1->RotateObject();
			}
		}
		GameMode->ChangePassCode1();
	}

	if (GameMode->PassCodeButton2 == true)
	{
		for (TObjectIterator<ACodeLock2> Itr; Itr; ++Itr)
		{
			if (Itr->IsA(ACodeLock2::StaticClass()))
			{
				ACodeLock2* CodeLock2 = *Itr;
				CodeLock2->RotateObject();
			}
		}
		GameMode->ChangePassCode2();
	}

	if (GameMode->PassCodeButton3 == true)
	{
		for (TObjectIterator<ACodeLock3> Itr; Itr; ++Itr)
		{
			if (Itr->IsA(ACodeLock3::StaticClass()))
			{
				ACodeLock3* CodeLock3 = *Itr;
				CodeLock3->RotateObject();
			}
		}
		GameMode->ChangePassCode3();
	}

	if (GameMode->PassCodeButton4 == true)
	{
		for (TObjectIterator<ACodeLock4> Itr; Itr; ++Itr)
		{
			if (Itr->IsA(ACodeLock4::StaticClass()))
			{
				ACodeLock4* CodeLock4 = *Itr;
				CodeLock4->RotateObject();
			}
		}
		GameMode->ChangePassCode4();
	}
}

// Move player forward with "W" or backward with "S"
void APlayerCharacter::MoveForwardBackward(float InputAxis)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, InputAxis);
}

// Move player right with "D" or left with "A"
void APlayerCharacter::MoveRightLeft(float InputAxis)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, InputAxis);
}
// On "E" key release, set UsingObject back to false
void APlayerCharacter::StopUsingObject()
{

}

// Press "Space" Make player jump
void APlayerCharacter::PlayerJump()
{
	if (PlayerJumped == false)
	{
		LaunchCharacter(FVector(0, 0, JumpHeightVelocity), false, true);
		PlayerJumped = true;
	}
}

// On "Space" released, start jump cooldown
void APlayerCharacter::StartJumpCooldown()
{
	if (PlayerJumped == true)
	{
		PlayerStartJumpCooldown = true;
	}
}

// Press "Left Shift" to make player start running. They will keep running until the input is released or the player has no energy
void APlayerCharacter::PlayerStartRunning()
{
	PlayerRunning = true;
}

// On "Left Shift" released, make player stop running and start recovery processs on energy.
void APlayerCharacter::PlayerStopRunning()
{
	PlayerRunning = false;
}



