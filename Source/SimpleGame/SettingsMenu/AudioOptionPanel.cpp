// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioOptionPanel.h"

#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"

void UAudioOptionPanel::OnMasterSliderValueChanged(float Value)
{
	CurrentSettingsProfile->MasterVolume = Value;
	RealizeAudioOptions(CurrentSettingsProfile);
}

void UAudioOptionPanel::OnSFXSliderValueChanged(float Value)
{
	CurrentSettingsProfile->SFXVolume = Value;
	RealizeAudioOptions(CurrentSettingsProfile);
}

void UAudioOptionPanel::OnAmbianceSliderValueChanged(float Value)
{
	CurrentSettingsProfile->AmbianceVolume = Value;
	RealizeAudioOptions(CurrentSettingsProfile);
}

void UAudioOptionPanel::OnMusicSliderValueChanged(float Value)
{
	CurrentSettingsProfile->MusicVolume = Value;
	RealizeAudioOptions(CurrentSettingsProfile);
}

void UAudioOptionPanel::OnVoiceSliderValueChanged(float Value)
{
	CurrentSettingsProfile->VoiceVolume = Value;
	RealizeAudioOptions(CurrentSettingsProfile);
}

void UAudioOptionPanel::OnAudioApplyButtonClicked()
{
	SavedSettingsProfile->SetFromOther(CurrentSettingsProfile);
	UGameplayStatics::SaveGameToSlot(SavedSettingsProfile, "SettingsProfile", 0);
	RealizeAudioOptions(CurrentSettingsProfile);
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
