// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodeLock3.generated.h"

UCLASS()
class FNAF_JELLY_TEST_API ACodeLock3 : public AActor
{
	GENERATED_BODY()
	
public:

	// Mesh Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* RotateMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* FaceMesh1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* FaceMesh2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* FaceMesh3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* FaceMesh4;

	// Collision Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USphereComponent* CollisionVolume;

	// Sets default values for this actor's properties
	ACodeLock3();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Collision Functions
	UFUNCTION()
	virtual void OnOverlapBegin(class UPrimitiveComponent* newComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void RotateObject();
};
