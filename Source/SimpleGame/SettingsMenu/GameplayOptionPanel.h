// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "SimpleGame/UserSettingsProfile.h"
#include "GameplayOptionPanel.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API UGameplayOptionPanel : public UCanvasPanel
{
	GENERATED_BODY()
public:
	// UPROPERTY()
	UUserSettingsProfile* UserSettingsProfile; // Reference to the user settings profile, to be used to change it inside the input functions

	UFUNCTION(BlueprintCallable)
	void OnLanguageComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType);

	UFUNCTION(BlueprintCallable)
	void OnSubtitlesCheckBoxSelectionChanged(bool Selection);

	UFUNCTION(BlueprintCallable)
	void OnBloodCheckBoxSelectionChanged(bool Selection);

	UFUNCTION(BlueprintCallable)
	void OnGoreCheckBoxSelectionChanged(bool Selection);

	UFUNCTION(BlueprintCallable)
	void OnInsectsCheckBoxSelectionChanged(bool Selection);

	UFUNCTION(BlueprintCallable)
	void OnGameplayApplyButtonClicked();

	UFUNCTION(BlueprintCallable)
	void OnGameplayResetButtonClicked();

	UFUNCTION(BlueprintCallable)
	void RealizeGameplayOptions(UUserSettingsProfile* UserSettingsProfile);
};
