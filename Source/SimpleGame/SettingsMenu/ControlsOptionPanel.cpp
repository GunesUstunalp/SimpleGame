// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlsOptionPanel.h"

void UControlsOptionPanel::OnMouseSensitivitySliderValueChanged(float Value)
{
	UserSettingsProfile->MouseSensitivity = Value;
}

void UControlsOptionPanel::OnControlsApplyButtonClicked()
{
	UserSettingsProfile->Print();
}

void UControlsOptionPanel::OnControlsResetButtonClicked()
{
	UserSettingsProfile->MouseSensitivity = 0.5f;
	RealizeControlsOptions(UserSettingsProfile);
}

void UControlsOptionPanel::RealizeControlsOptions(UUserSettingsProfile* UserSettingsProfile)
{
}
