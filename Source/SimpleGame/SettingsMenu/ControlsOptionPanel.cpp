// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlsOptionPanel.h"

void UControlsOptionPanel::OnMouseSensitivitySliderValueChanged(float Value)
{
	CurrentSettingsProfile->MouseSensitivity = Value;
}

void UControlsOptionPanel::OnControlsApplyButtonClicked()
{
	CurrentSettingsProfile->Print();
}

void UControlsOptionPanel::OnControlsResetButtonClicked()
{
	CurrentSettingsProfile->MouseSensitivity = 0.5f;
	RealizeControlsOptions(CurrentSettingsProfile);
}

void UControlsOptionPanel::RealizeControlsOptions(UUserSettingsProfile* UserSettingsProfile)
{
}
