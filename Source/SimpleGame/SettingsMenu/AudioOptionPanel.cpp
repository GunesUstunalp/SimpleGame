// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioOptionPanel.h"

#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"

void UAudioOptionPanel::OnMasterSliderValueChanged(float Value)
{
	CurrentSettingsProfile->MasterVolume = Value;
}

void UAudioOptionPanel::OnSFXSliderValueChanged(float Value)
{
	CurrentSettingsProfile->SFXVolume = Value;
}

void UAudioOptionPanel::OnAmbianceSliderValueChanged(float Value)
{
	CurrentSettingsProfile->AmbianceVolume = Value;
}

void UAudioOptionPanel::OnMusicSliderValueChanged(float Value)
{
	CurrentSettingsProfile->MusicVolume = Value;
}

void UAudioOptionPanel::OnVoiceSliderValueChanged(float Value)
{
	CurrentSettingsProfile->VoiceVolume = Value;
}

void UAudioOptionPanel::OnAudioApplyButtonClicked()
{
	SavedSettingsProfile->SetFromOther(CurrentSettingsProfile);
	UGameplayStatics::SaveGameToSlot(SavedSettingsProfile, "SettingsProfile", 0);
}

void UAudioOptionPanel::OnAudioResetButtonClicked(){
	CurrentSettingsProfile->MasterVolume = 1.0f;
	CurrentSettingsProfile->SFXVolume = 1.0f;
	CurrentSettingsProfile->AmbianceVolume = 1.0f;
	CurrentSettingsProfile->MusicVolume = 1.0f;
	CurrentSettingsProfile->VoiceVolume = 1.0f;
	RealizeAudioOptions(CurrentSettingsProfile);
}

void UAudioOptionPanel::RealizeAudioOptions(UUserSettingsProfile* UserSettingsProfile)
{
	//TODO: Implement Audio Settings
	
}
