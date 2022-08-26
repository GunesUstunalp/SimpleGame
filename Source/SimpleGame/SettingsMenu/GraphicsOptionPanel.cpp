// Fill out your copyright notice in the Description page of Project Settings.


#include "GraphicsOptionPanel.h"

#include "Kismet/GameplayStatics.h"

void UGraphicsOptionPanel::OnQualityPresetComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->SetQualityPresetIndex(4 - SelectedIndex);
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnGraphicsAutoDetectButtonClicked()
{
	//TODO: Implement Auto-Detect functionality
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnResolutionQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->ResolutionQuality = 4 - SelectedIndex;
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnViewDistanceComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->ViewDistanceQuality = 4 - SelectedIndex;
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnAntiAliasingComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->AntiAliasingQuality = 4 - SelectedIndex;
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnShadowQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->ShadowQuality = 4 - SelectedIndex;
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnGlobalIlluminationComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->GlobalIlluminationQuality = 4 - SelectedIndex;
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnReflectionQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->ReflectionQuality = 4 - SelectedIndex;
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnPostProcessQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->PostProcessQuality = 4 - SelectedIndex;
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnTextureQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->TextureQuality = 4 - SelectedIndex;
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnEffectsQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->EffectsQuality = 4 - SelectedIndex;
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnFoliageQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->FoliageQuality = 4 - SelectedIndex;
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnShadingQualityComboBoxSelectionChanged(int SelectedIndex)
{
	CurrentSettingsProfile->ShadingQuality = 4 - SelectedIndex;
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnGraphicsApplyButtonClicked()
{
	CurrentSettingsProfile->Print();
	SavedSettingsProfile->SetFromOther(CurrentSettingsProfile);
	UGameplayStatics::SaveGameToSlot(SavedSettingsProfile, "SettingsProfile", 0);
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::OnGraphicsResetButtonClicked()
{
	CurrentSettingsProfile->SetQualityPresetIndex(4);
	RealizeGraphicsOptions(CurrentSettingsProfile);
}

void UGraphicsOptionPanel::RealizeGraphicsOptions(UUserSettingsProfile* UserSettingsProfile)
{
	//if(SavedSettingsProfile->QualityPreset != -1) //If the selected index is not the custom quality level
    	//Settings->ScalabilityQuality.SetFromSingleQualityLevel(4 - selected); //The quality preset is set from the highest quality to the lowest quality, so we have to reverse the index
    //Settings->ApplySettings(false);
}
