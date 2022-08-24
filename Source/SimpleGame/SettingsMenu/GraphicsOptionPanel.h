// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "SimpleGame/UserSettingsProfile.h"
#include "GraphicsOptionPanel.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API UGraphicsOptionPanel : public UCanvasPanel
{
	GENERATED_BODY()
public:
	// UPROPERTY()
	UUserSettingsProfile* UserSettingsProfile; // Reference to the user settings profile, to be used to change it inside the input functions

	UFUNCTION(BlueprintCallable)
	void OnQualityPresetComboBoxSelectionChanged(int SelectedIndex);
	
	UFUNCTION(BlueprintCallable)
	void OnGraphicsAutoDetectButtonClicked();

	UFUNCTION(BlueprintCallable)
	void OnResolutionQualityComboBoxSelectionChanged(int SelectedIndex);

	UFUNCTION(BlueprintCallable)
	void OnViewDistanceComboBoxSelectionChanged(int SelectedIndex);

	UFUNCTION(BlueprintCallable)
	void OnAntiAliasingComboBoxSelectionChanged(int SelectedIndex);

	UFUNCTION(BlueprintCallable)
	void OnShadowQualityComboBoxSelectionChanged(int SelectedIndex);

	UFUNCTION(BlueprintCallable)
	void OnGlobalIlluminationComboBoxSelectionChanged(int SelectedIndex);

	UFUNCTION(BlueprintCallable)
	void OnReflectionQualityComboBoxSelectionChanged(int SelectedIndex);

	UFUNCTION(BlueprintCallable)
	void OnPostProcessQualityComboBoxSelectionChanged(int SelectedIndex);

	UFUNCTION(BlueprintCallable)
	void OnTextureQualityComboBoxSelectionChanged(int SelectedIndex);

	UFUNCTION(BlueprintCallable)
	void OnEffectsQualityComboBoxSelectionChanged(int SelectedIndex);
	
	UFUNCTION(BlueprintCallable)
	void OnFoliageQualityComboBoxSelectionChanged(int SelectedIndex);

	UFUNCTION(BlueprintCallable)
	void OnShadingQualityComboBoxSelectionChanged(int SelectedIndex);

	UFUNCTION(BlueprintCallable)
	void OnGraphicsApplyButtonClicked();

	UFUNCTION(BlueprintCallable)
	void OnGraphicsResetButtonClicked();

	UFUNCTION(BlueprintCallable)
	void RealizeAudioOptions(UUserSettingsProfile* UserSettingsProfile);
};
