// Fill out your copyright notice in the Description page of Project Settings.


#include "PressureButton.h"
#include "MoveableBox.h"
#include "Components/BoxComponent.h"
#include "Game42LabJellyGameModeBase.h"

// Sets default values
APressureButton::APressureButton()
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
void APressureButton::BeginPlay()
{
	Super::BeginPlay();
	
	// Create Overlap Functions
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &APressureButton::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &APressureButton::OnOverlapEnd);
}

// Called every frame
void APressureButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called when on enter overlap collision
void APressureButton::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
		AMoveableBox* Char = Cast<AMoveableBox>(OtherActor);
		if (Char)
		{
			UE_LOG(LogTemp, Warning, TEXT("Pressed"));
			GameMode->PressureCounter += 1;
		}
	}

}

// Called when on exit overlap collision
void APressureButton::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
		AMoveableBox* Char = Cast<AMoveableBox>(OtherActor);
		if (Char)
		{
			GameMode->PressureCounter -= 1;
		}
	}
}

