// Fill out your copyright notice in the Description page of Project Settings.


#include "DisplayOptionPanel.h"

#include "Kismet/GameplayStatics.h"

void UDisplayOptionPanel::OnWindowModeComboBoxSelectionChanged(int SelectedIndex)
{
	switch (SelectedIndex)
	{
	case 0:
		CurrentSettingsProfile->WindowMode = "Fullscreen";
		break;
	case 1:
		CurrentSettingsProfile->WindowMode = "WindowedFullscreen";
		break;
	case 2:
		CurrentSettingsProfile->WindowMode = "Windowed";
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
	SavedSettingsProfile->SetFromOther(CurrentSettingsProfile);
	UGameplayStatics::SaveGameToSlot(SavedSettingsProfile, "SettingsProfile", 0);
}

void UDisplayOptionPanel::OnDisplayResetButtonClicked()
{
	CurrentSettingsProfile->WindowMode = "Windowed";
	CurrentSettingsProfile->Resolution = "1280x720";
	CurrentSettingsProfile->VSyncEnabled = true;
	CurrentSettingsProfile->Brightness = 0.5f;
	CurrentSettingsProfile->Gamma = 0.5f;
	RealizeDisplayOptions(CurrentSettingsProfile);
}

void UDisplayOptionPanel::RealizeDisplayOptions(UUserSettingsProfile* UserSettingsProfile)
{
}
