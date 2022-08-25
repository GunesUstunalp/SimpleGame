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
	UPROPERTY(SaveGame)
	bool VSyncEnabled;
	UPROPERTY(SaveGame)
	FString WindowMode;
	UPROPERTY(SaveGame)
	FString Resolution;
	UPROPERTY(SaveGame)
	float Gamma;
	UPROPERTY(SaveGame)
	float Brightness;
	
	//Graphics Options
	UPROPERTY(SaveGame)
	int QualityPreset;
	UPROPERTY(SaveGame)
	int ResolutionQuality;
	UPROPERTY(SaveGame)
	int ViewDistanceQuality;
	UPROPERTY(SaveGame)
	int AntiAliasingQuality;
	UPROPERTY(SaveGame)
	int ShadowQuality;
	UPROPERTY(SaveGame)
	int GlobalIlluminationQuality;
	UPROPERTY(SaveGame)
	int ReflectionQuality;
	UPROPERTY(SaveGame)
	int PostProcessQuality;
	UPROPERTY(SaveGame)
	int TextureQuality;
	UPROPERTY(SaveGame)
	int EffectsQuality;
	UPROPERTY(SaveGame)
	int FoliageQuality;
	UPROPERTY(SaveGame)
	int ShadingQuality;

	//Audio Options
	UPROPERTY(SaveGame)
	float MasterVolume;
	UPROPERTY(SaveGame)
	float MusicVolume;
	UPROPERTY(SaveGame)
	float SFXVolume;
	UPROPERTY(SaveGame)
	float VoiceVolume;
	UPROPERTY(SaveGame)
	float AmbianceVolume;
	
	//Gameplay Options
	UPROPERTY(SaveGame)
	bool IsBloodEnabled;
	UPROPERTY(SaveGame)
	bool IsGoreEnabled;
	UPROPERTY(SaveGame)
	bool IsInsectsEnabled;
	UPROPERTY(SaveGame)
	FString Language;
	UPROPERTY(SaveGame)
	bool IsSubtitleEnabled;

	//Controls Options
	UPROPERTY(SaveGame)
	float MouseSensitivity;

	void Print(); // Prints the settings to the console
	void SetQualityPresetIndex(int Index); // Set the quality preset index and sets all the quality indexes to the preset index
	void SetFromOther(UUserSettingsProfile* Other); // Set the settings from another profile
};
