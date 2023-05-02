// Fill out your copyright notice in the Description page of Project Settings.


#include "ClueNote.h"

// Sets default values
AClueNote::AClueNote()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AClueNote::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClueNote::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AClueNote::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void AClueNote::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

