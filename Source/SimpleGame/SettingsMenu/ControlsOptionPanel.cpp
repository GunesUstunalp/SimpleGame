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
}

void UControlsOptionPanel::RealizeControlsOptions(UUserSettingsProfile* UserSettingsProfile)
{
}
