// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floater.generated.h"

UCLASS()
class SIMPLEGAME_API AFloater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloater();

	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere,  Category = "ActorMeshComponents");
	UStaticMeshComponent* StaticMesh;

	//Location used by SetActorLocation() when BeginPlay() is called
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Floater Variables");
	FVector initialLocation;

	// Location of the actor when dragged in from the editor
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Floater Variables");
	FVector placedLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Floater Variables")
	bool bInitializeFloaterLocations;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Floater Variables");
	FVector worldOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables");
	FVector initialForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables");
	bool bShouldFloat;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Floater Variables");
	FRotator initialRotation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float runningTime;
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables");
	float Amplitude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables");
	float Period;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables");
	float PhaseShift;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floater Variables");
	float VerticalShift;
};
