// Fill out your copyright notice in the Description page of Project Settings.


#include "GraphicsOptionPanel.h"

void UGraphicsOptionPanel::OnQualityPresetComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->QualityPreset = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnGraphicsAutoDetectButtonClicked()
{
	
}

void UGraphicsOptionPanel::OnResolutionQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->ResolutionQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnViewDistanceComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->ViewDistanceQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnAntiAliasingComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->AntiAliasingQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnShadowQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->ShadowQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnGlobalIlluminationComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->GlobalIlluminationQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnReflectionQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->ReflectionQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnPostProcessQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->PostProcessQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnTextureQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->TextureQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnEffectsQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->EffectsQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnFoliageQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->FoliageQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnShadingQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->ShadingQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnGraphicsApplyButtonClicked()
{
	CurrentSettingsProfile->Print();
}

void UGraphicsOptionPanel::OnGraphicsResetButtonClicked()
{
	CurrentSettingsProfile->SetQualityPresetIndex(4);
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::RealizeGraphicsOptions(UUserSettingsProfile* UserSettingsProfile)
{
}
