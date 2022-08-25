// Fill out your copyright notice in the Description page of Project Settings.


#include "DisplayOptionPanel.h"

void UDisplayOptionPanel::OnWindowModeComboBoxSelectionChanged(int SelectedIndex)
{
	switch (SelectedIndex)
	{
	case 0:
		CurrentSettingsProfile->WindowMode = EWindowMode::Fullscreen;
		break;
	case 1:
		CurrentSettingsProfile->WindowMode = EWindowMode::WindowedFullscreen;
		break;
	case 2:
		CurrentSettingsProfile->WindowMode = EWindowMode::Windowed;
		break;
	default:
		UE_LOG(LogTemp, Error, TEXT("ERROR! Unknown WindowMode!!!"));
	}
}

void UDisplayOptionPanel::OnResolutionComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType)
{
	CurrentSettingsProfile->Resolution = Selection;
}

void UDisplayOptionPanel::OnVSyncCheckBoxSelectionChanged(bool Selection)
{
	CurrentSettingsProfile->VSyncEnabled = Selection;
}

void UDisplayOptionPanel::OnBrightnessSliderValueChanged(float Value)
{
	CurrentSettingsProfile->Brightness = Value;
}

void UDisplayOptionPanel::OnGammaSliderValueChanged(float Value)
{
	CurrentSettingsProfile->Gamma = Value;
}

void UDisplayOptionPanel::OnDisplayApplyButtonClicked()
{
	CurrentSettingsProfile->Print();
}

void UDisplayOptionPanel::OnDisplayResetButtonClicked()
{
	CurrentSettingsProfile->WindowMode = EWindowMode::Windowed;
	CurrentSettingsProfile->Resolution = "1280x720";
	CurrentSettingsProfile->VSyncEnabled = true;
	CurrentSettingsProfile->Brightness = 0.5f;
	CurrentSettingsProfile->Gamma = 0.5f;
	RealizeDisplayOptions(CurrentSettingsProfile);
}

void UDisplayOptionPanel::RealizeDisplayOptions(UUserSettingsProfile* UserSettingsProfile)
{
}
