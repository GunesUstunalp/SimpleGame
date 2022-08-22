// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/Slider.h"
#include "AudioOptionPanel.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API UAudioOptionPanel : public UCanvasPanel
{
	GENERATED_BODY()

public:
	void OnMasterSliderValueChanged(float Value);
	void OnSFXSliderValueChanged(float Value);
	void OnAmbianceSliderValueChanged(float Value);
	void OnMusicSliderValueChanged(float Value);
	void OnVoiceSliderValueChanged(float Value);

	void OnAudioApplyButtonClicked();
	void OnAudioResetButtonClicked();
};
