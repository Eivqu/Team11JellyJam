// Fill out your copyright notice in the Description page of Project Settings.


#include "Keypad7.h"
#include "PlayerCharacter.h"
#include "Components/SphereComponent.h"
#include "Game42LabJellyGameModeBase.h"

// Sets default values
AKeypad7::AKeypad7()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Sphere Collision
	CollisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionVolume"));

	RootComponent = CollisionVolume;

	// Create Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AKeypad7::BeginPlay()
{
	Super::BeginPlay();

	// Create Overlap Functions
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AKeypad7::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &AKeypad7::OnOverlapEnd);
}

// Called every frame
void AKeypad7::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called when on enter overlap collision
void AKeypad7::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
		APlayerCharacter* Char = Cast<APlayerCharacter>(OtherActor);
		if (Char)
		{
			GameMode->DoorButtonActive7 = true;
		}
	}
}

// Called when on exit overlap collision
void AKeypad7::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
		APlayerCharacter* Char = Cast<APlayerCharacter>(OtherActor);
		if (Char)
		{
			GameMode->DoorButtonActive7 = false;
		}
	}
}
