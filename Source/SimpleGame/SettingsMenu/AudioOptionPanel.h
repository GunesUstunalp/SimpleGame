// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/Slider.h"
#include "SimpleGame/UserSettingsProfile.h"
#include "AudioOptionPanel.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API UAudioOptionPanel : public UCanvasPanel
{
	GENERATED_BODY()

public:
	// UPROPERTY()
	UUserSettingsProfile* UserSettingsProfile; // Reference to the user settings profile, to be used to change it inside the input functions
	
	UFUNCTION(BlueprintCallable)
	void OnMasterSliderValueChanged(float Value);

	UFUNCTION(BlueprintCallable)
	void OnSFXSliderValueChanged(float Value);

	UFUNCTION(BlueprintCallable)
	void OnAmbianceSliderValueChanged(float Value);

	UFUNCTION(BlueprintCallable)
	void OnMusicSliderValueChanged(float Value);

	UFUNCTION(BlueprintCallable)
	void OnVoiceSliderValueChanged(float Value);

	UFUNCTION(BlueprintCallable)
	void OnAudioApplyButtonClicked();
	
	UFUNCTION(BlueprintCallable)
	void OnAudioResetButtonClicked();

	UFUNCTION(BlueprintCallable)
	static void RealizeAudioOptions(UUserSettingsProfile* UserSettingsProfile);
};
