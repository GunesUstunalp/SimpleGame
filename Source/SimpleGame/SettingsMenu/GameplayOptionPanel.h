// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "GameplayOptionPanel.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API UGameplayOptionPanel : public UCanvasPanel
{
	GENERATED_BODY()
public:
	void OnLanguageComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);

	void OnSubtitlesCheckBoxSelectionChanged(bool Selection);
	void OnBloodCheckBoxSelectionChanged(bool Selection);
	void OnGoreCheckBoxSelectionChanged(bool Selection);
	void OnInsectsCheckBoxSelectionChanged(bool Selection);

	void OnGameplayApplyButtonClicked();
	void OnGameplayResetButtonClicked();
};
