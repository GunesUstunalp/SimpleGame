// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API UMainAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category )
	float MovementSpeed;
	
};
