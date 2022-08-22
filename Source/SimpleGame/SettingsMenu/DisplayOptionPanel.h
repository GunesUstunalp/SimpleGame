// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "DisplayOptionPanel.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API UDisplayOptionPanel : public UCanvasPanel
{
	GENERATED_BODY()
public:
	void OnWindowModeComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);
	void OnResolutionComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);

	void OnVSyncCheckBoxSelectionChanged(bool Selection);
	
	void OnBrightnessSliderValueChanged(float Value);
	void OnGammaSliderValueChanged(float Value);

	void OnDisplayApplyButtonClicked();
	void OnDisplayResetButtonClicked();
};
