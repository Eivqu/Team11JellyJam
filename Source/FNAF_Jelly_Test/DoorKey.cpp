// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorKey.h"
#include "PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModeBase.h"
#include "Game42LabJellyGameModeBase.h"

// Sets default values
ADoorKey::ADoorKey()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Box Collision and door meshes
	CollisionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionVolume"));
	RootComponent = CollisionVolume;
	
	DoorRotate = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorRotateMesh"));
	DoorRotate->SetupAttachment(RootComponent);

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(DoorRotate);
}

// Called when the game starts or when spawned
void ADoorKey::BeginPlay()
{
	Super::BeginPlay();
	
	// Create Overlap Functions and curve float timeline
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &ADoorKey::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &ADoorKey::OnOverlapEnd);

	if (CurveFloat)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindDynamic(this, &ADoorKey::OpenDoor);
		Timeline.AddInterpFloat(CurveFloat, TimelineProgress);	
	}
}

// Called every frame
void ADoorKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timeline.TickTimeline(DeltaTime);

}
// Called when on enter overlap collision
void ADoorKey::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ActivateDoor();
}

// Called when on exit overlap collision
void ADoorKey::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

// Open door
void ADoorKey::OpenDoor(float Value)
{

	
	FRotator Rot = FRotator(0.f, DoorRotateAngle * Value, 0.f);

	DoorRotate->SetRelativeRotation(Rot);

}

// On when player try to use door
void ADoorKey::ActivateDoor()
{
	AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode->HasKey1 == true)
	{
		// If key has been obtained, open door
		if (bIsDoorClosed)
		{
			Timeline.Play();
			GameMode->HasKey1 = false;
		}
		else
		{
			Timeline.Reverse();
		}

		bIsDoorClosed = !bIsDoorClosed;
	}

}






