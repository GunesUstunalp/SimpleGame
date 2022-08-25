// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayOptionPanel.h"

void UGameplayOptionPanel::OnLanguageComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType)
{
	CurrentSettingsProfile->Language = Selection;
}

void UGameplayOptionPanel::OnSubtitlesCheckBoxSelectionChanged(bool Selection)
{
	CurrentSettingsProfile->IsSubtitleEnabled = Selection;
}

void UGameplayOptionPanel::OnBloodCheckBoxSelectionChanged(bool Selection)
{
	CurrentSettingsProfile->IsBloodEnabled = Selection;
}

void UGameplayOptionPanel::OnGoreCheckBoxSelectionChanged(bool Selection)
{
	CurrentSettingsProfile->IsGoreEnabled = Selection;
}

void UGameplayOptionPanel::OnInsectsCheckBoxSelectionChanged(bool Selection)
{
	CurrentSettingsProfile->IsInsectsEnabled = Selection;
}

void UGameplayOptionPanel::OnGameplayApplyButtonClicked()
{
	CurrentSettingsProfile->Print();
}

void UGameplayOptionPanel::OnGameplayResetButtonClicked()
{
	CurrentSettingsProfile->Language = "English";
	CurrentSettingsProfile->IsSubtitleEnabled = true;
	CurrentSettingsProfile->IsBloodEnabled = true;
	CurrentSettingsProfile->IsGoreEnabled = true;
	CurrentSettingsProfile->IsInsectsEnabled = true;
	RealizeGameplayOptions(CurrentSettingsProfile);
}

void UGameplayOptionPanel::RealizeGameplayOptions(UUserSettingsProfile* UserSettingsProfile)
{
}
