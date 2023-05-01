// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyItem2.h"
#include "PlayerCharacter.h"
#include "Components/SphereComponent.h"
#include "Game42LabJellyGameModeBase.h"

// Sets default values
AKeyItem2::AKeyItem2()
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
void AKeyItem2::BeginPlay()
{
	Super::BeginPlay();

	// Create Overlap Functions
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AKeyItem2::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &AKeyItem2::OnOverlapEnd);
	
}

// Called every frame
void AKeyItem2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());

	if (GameMode->HasKey3 == true)
	{
		Destroy();
	}

}

// Called when on enter overlap collision
void AKeyItem2::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		APlayerCharacter* Char = Cast<APlayerCharacter>(OtherActor);
		AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
		if (Char)
		{
			GameMode->KeyActive3 = true;
		}

	}
}

// Called when on exit overlap collision
void AKeyItem2::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		APlayerCharacter* Char = Cast<APlayerCharacter>(OtherActor);
		AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
		if (Char)
		{
			GameMode->KeyActive3 = false;
		}

	}
}

