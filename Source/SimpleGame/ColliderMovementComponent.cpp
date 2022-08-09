// Fill out your copyright notice in the Description page of Project Settings.


#include "ColliderMovementComponent.h"

void UColliderMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime)) {
		return;
	}

	FVector OldDesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f);
	
	FVector DesiredMovementThisFrame = OldDesiredMovementThisFrame * DeltaTime * 3000.f;
	//UE_LOG(LogTemp, Warning, TEXT("DeltaTime = %f, DesiredMovementThisFrame was %f, now is %f"), DeltaTime, OldDesiredMovementThisFrame.X, DesiredMovementThisFrame.X);

	if (!DesiredMovementThisFrame.IsNearlyZero()) {

		FHitResult Hit;
		SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);

		//if we bump into something, slide along the side of it
		if (Hit.IsValidBlockingHit()) {
			SlideAlongSurface(DesiredMovementThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);
			UE_LOG(LogTemp, Warning, TEXT("Valid Blocking Hit!"));
		}
	}


}