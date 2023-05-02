// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "DoorKey1.generated.h"

UCLASS()
class FNAF_JELLY_TEST_API ADoorKey1 : public AActor
{
	GENERATED_BODY()
	
public:

	// Mesh Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* DoorRotate;

	// Door Mesh Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* DoorMesh;

	// Collision Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* CollisionVolume;

	// Sets default values for this actor's properties
	ADoorKey1();

	// Timeline to rotate the open toward open or close
	UPROPERTY(EditAnywhere)
	FTimeline Timeline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveFloat* CurveFloat;

	// Is door closed?
	bool bIsDoorClosed = true;

	// Initial door rotation angle
	float DoorRotateAngle = 90.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Collision Functions
	UFUNCTION()
	virtual void OnOverlapBegin(class UPrimitiveComponent* newComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Open door functions
	UFUNCTION()
	void OpenDoor(float Value);

	// On use to open door
	UFUNCTION()
	void ActivateDoor();

};
