// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USoundBase;

UCLASS()
class FNAF_JELLY_TEST_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	// Camera component
	UPROPERTY()
	class UCameraComponent* PlayerCamera;
	
	// Sets default values for this character's properties
	APlayerCharacter();

	// Collision component
	UPROPERTY()
	class UCapsuleComponent* CapsuleCollision;

	// Player jumped
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Jump Mechanics")
	bool PlayerJumped;

	// Player start jump cooldown
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Jump Mechanics")
	bool PlayerStartJumpCooldown;

	// Player jump cooldown timer
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Jump Mechanics")
	int JumpCooldownTimer;

	// Player jump height
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Jump Mechanics")
	float JumpHeightVelocity;

	// Player running
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Run Mechanics")
	bool PlayerRunning;

	// Player run energy
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Run Mechanics")
	float RunEnergy;

	// Music
	UPROPERTY(EditDefaultsOnly, Category = "Sound Effects")
	USoundBase* SB_Music;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Player jump
	UFUNCTION()
	void PlayerJump();

	// Player use object
	UFUNCTION()
	void UseObject();

	// Player move forward or backward
	UFUNCTION()
	void MoveForwardBackward(float InputAxis);

	// Player move right or left
	UFUNCTION()
	void MoveRightLeft(float InputAxis);

	// Player stop using object
	UFUNCTION()
	void StopUsingObject();

	// Player jump cooldown
	UFUNCTION()
	void StartJumpCooldown();

	// Player start running
	UFUNCTION()
	void PlayerStartRunning();

	// Player stop running
	UFUNCTION()
	void PlayerStopRunning();

	// Play Game Music
	void PlayMusic();


};
