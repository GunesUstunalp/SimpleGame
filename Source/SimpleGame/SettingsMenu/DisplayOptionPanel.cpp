// Fill out your copyright notice in the Description page of Project Settings.


#include "DisplayOptionPanel.h"

void UDisplayOptionPanel::OnWindowModeComboBoxSelectionChanged(int SelectedIndex)
{
	switch (SelectedIndex)
	{
	case 0:
		UserSettingsProfile->WindowMode = EWindowMode::Fullscreen;
		break;
	case 1:
		UserSettingsProfile->WindowMode = EWindowMode::WindowedFullscreen;
		break;
	case 2:
		UserSettingsProfile->WindowMode = EWindowMode::Windowed;
		break;
	default:
		UE_LOG(LogTemp, Error, TEXT("ERROR! Unknown WindowMode!!!"));
	}
}

void UDisplayOptionPanel::OnResolutionComboBoxSelectionChanged(FString Selection, ESelectInfo::Type SelectionType)
{
	UserSettingsProfile->Resolution = Selection;
}

void UDisplayOptionPanel::OnVSyncCheckBoxSelectionChanged(bool Selection)
{
	UserSettingsProfile->VSyncEnabled = Selection;
}

void UDisplayOptionPanel::OnBrightnessSliderValueChanged(float Value)
{
	UserSettingsProfile->Brightness = Value;
}

void UDisplayOptionPanel::OnGammaSliderValueChanged(float Value)
{
	UserSettingsProfile->Gamma = Value;
}

void UDisplayOptionPanel::OnDisplayApplyButtonClicked()
{
	UserSettingsProfile->Print();
}

void UDisplayOptionPanel::OnDisplayResetButtonClicked()
{
}
