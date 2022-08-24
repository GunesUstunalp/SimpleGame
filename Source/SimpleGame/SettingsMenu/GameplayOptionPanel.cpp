// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayOptionPanel.h"

void UGameplayOptionPanel::OnLanguageComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType)
{
	UserSettingsProfile->Language = Selection;
}

void UGameplayOptionPanel::OnSubtitlesCheckBoxSelectionChanged(bool Selection)
{
	UserSettingsProfile->IsSubtitleEnabled = Selection;
}

void UGameplayOptionPanel::OnBloodCheckBoxSelectionChanged(bool Selection)
{
	UserSettingsProfile->IsBloodEnabled = Selection;
}

void UGameplayOptionPanel::OnGoreCheckBoxSelectionChanged(bool Selection)
{
	UserSettingsProfile->IsGoreEnabled = Selection;
}

void UGameplayOptionPanel::OnInsectsCheckBoxSelectionChanged(bool Selection)
{
	UserSettingsProfile->IsInsectsEnabled = Selection;
}

void UGameplayOptionPanel::OnGameplayApplyButtonClicked()
{
	UserSettingsProfile->Print();
}

void UGameplayOptionPanel::OnGameplayResetButtonClicked()
{
}

void UGameplayOptionPanel::RealizeGameplayOptions(UUserSettingsProfile* UserSettingsProfile)
{
}
