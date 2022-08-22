// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "GraphicsOptionPanel.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API UGraphicsOptionPanel : public UCanvasPanel
{
	GENERATED_BODY()
public:
	void OnQualityPresetComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);

	void OnGraphicsAutoDetectButtonClicked();

	void OnResolutionQualityComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);
	void OnViewDistanceComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);
	void OnAntiAliasingComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);
	void OnShadowQualityComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);
	void OnGlobalIlluminationComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);
	void OnReflectionQualityComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);
	void OnPostProcessQualityComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);
	void OnTextureQualityComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);
	void OnEffectsQualityComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);
	void OnFoliageQualityComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);
	void OnShadingQualityComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);

	void OnGraphicsApplyButtonClicked();
	void OnGraphicsResetButtonClicked();
};
