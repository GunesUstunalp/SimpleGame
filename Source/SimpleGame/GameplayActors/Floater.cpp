// Fill out your copyright notice in the Description page of Project Settings.
#include "Floater.h"

// Sets default values
AFloater::AFloater()
{
	runningTime = 0.f;
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));

	RootComponent = StaticMesh;

	initialLocation = FVector(0.0f, 0.0f, 0.0f);
	placedLocation = FVector(0.0f, 0.0f, 0.0f);
	worldOrigin = FVector(0.0f, 0.0f, 0.0f);

	initialForce = FVector(0.0f, 0.0f, 0.0f);
	initialRotation = FRotator(0.0f, 0.0f, 0.0f);

	bInitializeFloaterLocations = false;
	bShouldFloat = false;

	//Amplitude, Period, PhaseShift, VerticalShift = 0.f;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	initialLocation = FVector(FMath::FRandRange(-500.f,500.f), FMath::FRandRange(-500.f,500.f), FMath::FRandRange(20.f,500.f));

	if (bInitializeFloaterLocations) {
		SetActorLocation(initialLocation);
	}
	
	/*if (bShouldFloat) {
		StaticMesh->AddForce(initialForce);
		StaticMesh->AddTorqueInRadians(initialForce);
	}*/

	placedLocation = GetActorLocation();

}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	runningTime += DeltaTime;

	if (bShouldFloat) {
		FVector NewLocation = GetActorLocation();

		NewLocation.Z = placedLocation.Z + Amplitude * FMath::Sin(Period * runningTime - PhaseShift) + VerticalShift;

		UE_LOG(LogTemp, Warning, TEXT("amp is %f"), Amplitude);

		SetActorLocation(NewLocation);
	}
}

