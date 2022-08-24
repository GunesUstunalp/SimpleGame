// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "SimpleGame/UserSettingsProfile.h"
#include "ControlsOptionPanel.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API UControlsOptionPanel : public UCanvasPanel
{
	GENERATED_BODY()
public:
	// UPROPERTY()
	UUserSettingsProfile* UserSettingsProfile; // Reference to the user settings profile, to be used to change it inside the input functions

	UFUNCTION(BlueprintCallable)
	void OnMouseSensitivitySliderValueChanged(float Value);

	UFUNCTION(BlueprintCallable)
	void OnControlsApplyButtonClicked();

	UFUNCTION(BlueprintCallable)
	void OnControlsResetButtonClicked();

	UFUNCTION(BlueprintCallable)
	static void RealizeControlsOptions(UUserSettingsProfile* UserSettingsProfile);
};
