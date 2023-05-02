// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorButton8.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModeBase.h"
#include "Game42LabJellyGameModeBase.h"

// Sets default values
ADoorButton8::ADoorButton8()
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
void ADoorButton8::BeginPlay()
{
	Super::BeginPlay();

	// Create Overlap Functions
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &ADoorButton8::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &ADoorButton8::OnOverlapEnd);

	if (CurveFloat)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindDynamic(this, &ADoorButton8::OpenDoor);
		Timeline.AddInterpFloat(CurveFloat, TimelineProgress);
	}


}

// Called every frame
void ADoorButton8::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timeline.TickTimeline(DeltaTime);

	AGame42LabJellyGameModeBase* GameMode = Cast<AGame42LabJellyGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode->DoorActive9 == true)
	{
		ActivateDoor();
		GameMode->DoorActive9 = false;
	}
}

// Called when on enter overlap collision
void ADoorButton8::OnOverlapBegin(UPrimitiveComponent* newComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

// Called when on exit overlap collision
void ADoorButton8::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

// Open door
void ADoorButton8::OpenDoor(float Value)
{
	FRotator Rot = FRotator(0.f, DoorRotateAngle * Value, 0.f);

	DoorRotate->SetRelativeRotation(Rot);
}

// On when player try to use door
void ADoorButton8::ActivateDoor()
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

