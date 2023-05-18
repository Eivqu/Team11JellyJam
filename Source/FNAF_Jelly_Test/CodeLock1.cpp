// Fill out your copyright notice in the Description page of Project Settings.


#include "CodeLock1.h"
#include "PlayerCharacter.h"
#include "Components/SphereComponent.h"
#include "Game42LabJellyGameModeBase.h"

// Sets default values
ACodeLock1::ACodeLock1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Sphere Collision
	CollisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionVolume"));

	RootComponent = CollisionVolume;

	// Create Mesh
	RotateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RotateMesh"));
	RotateMesh->SetupAttachment(RootComponent);

	FaceMesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FaceMesh1"));
	FaceMesh1->SetupAttachment(RotateMesh);

	FaceMesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FaceMesh2"));
	FaceMesh2->SetupAttachment(RotateMesh);

	FaceMesh3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FaceMesh3"));
	FaceMesh3->SetupAttachment(RotateMesh);

	FaceMesh4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FaceMesh4"));
	FaceMesh4->SetupAttachment(RotateMesh);
}

// Called when the game starts or when spawned
void ACodeLock1::BeginPlay()
{
	Super::BeginPlay();
	
	// Create Overlap Functions
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &ACodeLock1::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &ACodeLock1::OnOverlapEnd);
}

// Called every frame
void ACodeLock1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called when on enter overlap collision
void ACodeLock1::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
		APlayerCharacter* Char = Cast<APlayerCharacter>(OtherActor);
		if (Char)
		{
			GameMode->PassCodeButton1 = true;
		}
	}
}

// Called when on exit overlap collision
void ACodeLock1::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor)
	{
		AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
		APlayerCharacter* Char = Cast<APlayerCharacter>(OtherActor);
		if (Char)
		{
			GameMode->PassCodeButton1 = false;
		}
	}
}

void ACodeLock1::RotateObject()
{
	FRotator Rot = FRotator(0.f, 90.f, 0.f);
	RotateMesh->AddLocalRotation(Rot);
}

