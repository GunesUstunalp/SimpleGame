// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioOptionPanel.h"

#include "GameFramework/GameUserSettings.h"

void UAudioOptionPanel::OnMasterSliderValueChanged(float Value)
{
	UserSettingsProfile->MasterVolume = Value;
}

void UAudioOptionPanel::OnSFXSliderValueChanged(float Value)
{
	UserSettingsProfile->SFXVolume = Value;
}

void UAudioOptionPanel::OnAmbianceSliderValueChanged(float Value)
{
	UserSettingsProfile->AmbianceVolume = Value;
}

void UAudioOptionPanel::OnMusicSliderValueChanged(float Value)
{
	UserSettingsProfile->MusicVolume = Value;
}

void UAudioOptionPanel::OnVoiceSliderValueChanged(float Value)
{
	UserSettingsProfile->VoiceVolume = Value;
}

void UAudioOptionPanel::OnAudioApplyButtonClicked()
{
	UserSettingsProfile->Print();
}

void UAudioOptionPanel::OnAudioResetButtonClicked(){
}

void UAudioOptionPanel::RealizeAudioOptions(UUserSettingsProfile* UserSettingsProfile)
{
}
