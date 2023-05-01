// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorPressure1.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModeBase.h"
#include "Game42LabJellyGameModeBase.h"

// Sets default values
ADoorPressure1::ADoorPressure1()
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
void ADoorPressure1::BeginPlay()
{
	Super::BeginPlay();
	
	// Create Overlap Functions and curve float timeline
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &ADoorPressure1::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &ADoorPressure1::OnOverlapEnd);

	if (CurveFloat)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindDynamic(this, &ADoorPressure1::OpenDoor);
		Timeline.AddInterpFloat(CurveFloat, TimelineProgress);
	}
}

// Called every frame
void ADoorPressure1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode->PressureCounter2 == 3 && DoorOpened == false)
	{
		ActivateDoor();
		DoorOpened = true;
	}

}

// Called when on enter overlap collision
void ADoorPressure1::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

// Called when on exit overlap collision
void ADoorPressure1::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

// Open door
void ADoorPressure1::OpenDoor(float Value)
{
	FRotator Rot = FRotator(0.f, DoorRotateAngle * Value, 0.f);

	DoorRotate->SetRelativeRotation(Rot);
}

// On when player try to use door
void ADoorPressure1::ActivateDoor()
{
	AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode->PressureCounter2 == 3)
	{
		if (bIsDoorClosed)
		{
			Timeline.Play();
		}
		else
		{
			Timeline.Reverse();
		}

		bIsDoorClosed = !bIsDoorClosed;
	}
}

