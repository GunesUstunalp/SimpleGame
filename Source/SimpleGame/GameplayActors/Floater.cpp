// Fill out your copyright notice in the Description page of Project Settings.
#include "Floater.h"

// Sets default values
AFloater::AFloater()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));

	RootComponent = StaticMesh;

	initialLocation = FVector(0.0f, 0.0f, 0.0f);
	placedLocation = FVector(0.0f, 0.0f, 0.0f);
	worldOrigin = FVector(0.0f, 0.0f, 0.0f);

	initialDirection = FVector(0.0f, 0.0f, 0.0f);
	initialRotation = FRotator(0.0f, 0.0f, 0.0f);

	bInitializeFloaterLocations = false;
	bShouldFloat = false;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();
	
	placedLocation = GetActorLocation();

	if (bInitializeFloaterLocations) {
		SetActorLocation(initialLocation);
	}

	FHitResult HitResult;
	FVector LocalOffset = FVector(200.f, 0.0f, 0.0f);
	AddActorLocalOffset(LocalOffset, true, &HitResult);
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat) {
		FHitResult HitResult;
		AddActorLocalOffset(initialDirection, true, &HitResult);

		FVector HitLocation = HitResult.Location;

		UE_LOG(LogTemp, Warning, TEXT("Hit Location: X = %f, Y = %f, Z = %f"), HitLocation.X, HitLocation.Y, HitLocation.Z);
	}

	AddActorWorldRotation(initialRotation);
}

