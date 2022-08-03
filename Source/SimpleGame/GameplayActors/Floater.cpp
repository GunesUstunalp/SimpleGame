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
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat) {
		FHitResult HitResult;
		AddActorLocalOffset(initialDirection, false, &HitResult);
	}
}

