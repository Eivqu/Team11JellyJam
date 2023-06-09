// Fill out your copyright notice in the Description page of Project Settings.


#include "PressureButton1.h"
#include "MoveableBox.h"
#include "Components/BoxComponent.h"
#include "Game42LabJellyGameModeBase.h"

// Sets default values
APressureButton1::APressureButton1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Box Collision
	CollisionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionVolume"));

	RootComponent = CollisionVolume;

	// Create Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void APressureButton1::BeginPlay()
{
	Super::BeginPlay();

	// Create Overlap Functions
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &APressureButton1::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &APressureButton1::OnOverlapEnd);
	
}

// Called every frame
void APressureButton1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called when on enter overlap collision
void APressureButton1::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
		AMoveableBox* Char = Cast<AMoveableBox>(OtherActor);
		if (Char)
		{
			GameMode->PressureCounter2 += 1;
		}
	}
}

// Called when on exit overlap collision
void APressureButton1::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
		AMoveableBox* Char = Cast<AMoveableBox>(OtherActor);
		if (Char)
		{
			GameMode->PressureCounter2 -= 1;
		}
	}
}

