// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "UserSettingsProfile.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API UUserSettingsProfile : public USaveGame
{
	GENERATED_BODY()
public:
	UUserSettingsProfile();
	UUserSettingsProfile(UUserSettingsProfile &Other); // Copy constructor

	bool operator==(const UUserSettingsProfile &Other) const;

	
	//Display Options
	bool VSyncEnabled;
	EWindowMode::Type WindowMode;
	FString Resolution;
	float Gamma;
	float Brightness;
	
	//Graphics Options
	int QualityPreset;
	int ResolutionQuality;
	int ViewDistanceQuality;
	int AntiAliasingQuality;
	int ShadowQuality;
	int GlobalIlluminationQuality;
	int ReflectionQuality;
	int PostProcessQuality;
	int TextureQuality;
	int EffectsQuality;
	int FoliageQuality;
	int ShadingQuality;

	//Audio Options
	float MasterVolume;
	float MusicVolume;
	float SFXVolume;
	float VoiceVolume;
	float AmbianceVolume;
	
	//Gameplay Options
	bool IsBloodEnabled;
	bool IsGoreEnabled;
	bool IsInsectsEnabled;
	FString Language;
	bool IsSubtitleEnabled;

	//Controls Options
	float MouseSensitivity;

	void Print(); // Prints the settings to the console
	
private:
	void setQualityPresetIndex(int Index); // Set the quality preset index and sets all the quality indexes to the preset index
};
