// Fill out your copyright notice in the Description page of Project Settings.


#include "GraphicsOptionPanel.h"

void UGraphicsOptionPanel::OnQualityPresetComboBoxSelectionChanged(int SelectedIndex)
{
	UserSettingsProfile->QualityPreset = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnGraphicsAutoDetectButtonClicked()
{
	
}

void UGraphicsOptionPanel::OnResolutionQualityComboBoxSelectionChanged(int SelectedIndex)
{
	UserSettingsProfile->ResolutionQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnViewDistanceComboBoxSelectionChanged(int SelectedIndex)
{
	UserSettingsProfile->ViewDistanceQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnAntiAliasingComboBoxSelectionChanged(int SelectedIndex)
{
	UserSettingsProfile->AntiAliasingQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnShadowQualityComboBoxSelectionChanged(int SelectedIndex)
{
	UserSettingsProfile->ShadowQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnGlobalIlluminationComboBoxSelectionChanged(int SelectedIndex)
{
	UserSettingsProfile->GlobalIlluminationQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnReflectionQualityComboBoxSelectionChanged(int SelectedIndex)
{
	UserSettingsProfile->ReflectionQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnPostProcessQualityComboBoxSelectionChanged(int SelectedIndex)
{
	UserSettingsProfile->PostProcessQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnTextureQualityComboBoxSelectionChanged(int SelectedIndex)
{
	UserSettingsProfile->TextureQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnEffectsQualityComboBoxSelectionChanged(int SelectedIndex)
{
	UserSettingsProfile->EffectsQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnFoliageQualityComboBoxSelectionChanged(int SelectedIndex)
{
	UserSettingsProfile->FoliageQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnShadingQualityComboBoxSelectionChanged(int SelectedIndex)
{
	UserSettingsProfile->ShadingQuality = 4 - SelectedIndex;
}

void UGraphicsOptionPanel::OnGraphicsApplyButtonClicked()
{
	UserSettingsProfile->Print();
}

void UGraphicsOptionPanel::OnGraphicsResetButtonClicked()
{
	UserSettingsProfile->setQualityPresetIndex(4);
	RealizeGraphicsOptions(UserSettingsProfile);
}

void UGraphicsOptionPanel::RealizeGraphicsOptions(UUserSettingsProfile* UserSettingsProfile)
{
}
