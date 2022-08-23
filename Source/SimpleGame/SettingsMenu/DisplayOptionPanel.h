// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "SimpleGame/UserSettingsProfile.h"
#include "DisplayOptionPanel.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API UDisplayOptionPanel : public UCanvasPanel
{
	GENERATED_BODY()
public:
	// UPROPERTY()
	UUserSettingsProfile* UserSettingsProfile; // Reference to the user settings profile, to be used to change it inside the input functions

	UFUNCTION(BlueprintCallable)
	void OnWindowModeComboBoxSelectionChanged(int SelectedIndex);

	UFUNCTION(BlueprintCallable)
	void OnResolutionComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);

	UFUNCTION(BlueprintCallable)
	void OnVSyncCheckBoxSelectionChanged(bool Selection);

	UFUNCTION(BlueprintCallable)
	void OnBrightnessSliderValueChanged(float Value);
	
	UFUNCTION(BlueprintCallable)
	void OnGammaSliderValueChanged(float Value);

	UFUNCTION(BlueprintCallable)
	void OnDisplayApplyButtonClicked();

	UFUNCTION(BlueprintCallable)
	void OnDisplayResetButtonClicked();
};
