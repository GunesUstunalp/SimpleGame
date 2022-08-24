// Fill out your copyright notice in the Description page of Project Settings.


#include "UserSettingsProfile.h"

UUserSettingsProfile::UUserSettingsProfile()
{
	VSyncEnabled = true;
	WindowMode = EWindowMode::Windowed;
	Resolution = "1280x720";
	Gamma = 0.5f;
	Brightness = 0.5f; //?

	setQualityPresetIndex(4);
	
	MasterVolume = 1.0f;
	MusicVolume = 1.0f;
	SFXVolume = 1.0f;
	VoiceVolume = 1.0f;
	AmbianceVolume = 1.0f;

	IsBloodEnabled = true;
	IsGoreEnabled = true;
	IsInsectsEnabled = true;
	Language = "English";
	IsSubtitleEnabled = true;

	MouseSensitivity = 0.5f;
}

UUserSettingsProfile::UUserSettingsProfile(UUserSettingsProfile& Other)
{
	VSyncEnabled = Other.VSyncEnabled;
	WindowMode = Other.WindowMode;
	Resolution = Other.Resolution;
	Gamma = Other.Gamma;
	Brightness = Other.Brightness;
	
	QualityPreset = Other.QualityPreset;
	ResolutionQuality = Other.ResolutionQuality;
	ViewDistanceQuality = Other.ViewDistanceQuality;
	AntiAliasingQuality = Other.AntiAliasingQuality;
	ShadowQuality = Other.ShadowQuality;
	GlobalIlluminationQuality = Other.GlobalIlluminationQuality;
	ReflectionQuality = Other.ReflectionQuality;
	PostProcessQuality = Other.PostProcessQuality;
	TextureQuality = Other.TextureQuality;
	EffectsQuality = Other.EffectsQuality;
	FoliageQuality = Other.FoliageQuality;
	ShadingQuality = Other.ShadingQuality;

	MasterVolume = Other.MasterVolume;
	MusicVolume = Other.MusicVolume;
	SFXVolume = Other.SFXVolume;
	VoiceVolume = Other.VoiceVolume;
	AmbianceVolume = Other.AmbianceVolume;

	IsBloodEnabled = Other.IsBloodEnabled;
	IsGoreEnabled = Other.IsGoreEnabled;
	IsInsectsEnabled = Other.IsInsectsEnabled;
	Language = Other.Language;
	IsSubtitleEnabled = Other.IsSubtitleEnabled;
	
	MouseSensitivity = Other.MouseSensitivity;
}

bool UUserSettingsProfile::operator==(const UUserSettingsProfile& Other) const
{
	if(VSyncEnabled != Other.VSyncEnabled || WindowMode != Other.WindowMode || Resolution != Other.Resolution || Gamma != Other.Gamma || Brightness != Other.Brightness)
		return false;

	if(QualityPreset != Other.QualityPreset || ResolutionQuality != Other.ResolutionQuality || ViewDistanceQuality != Other.ViewDistanceQuality || AntiAliasingQuality != Other.AntiAliasingQuality || ShadowQuality != Other.ShadowQuality || GlobalIlluminationQuality != Other.GlobalIlluminationQuality || ReflectionQuality != Other.ReflectionQuality || PostProcessQuality != Other.PostProcessQuality || TextureQuality != Other.TextureQuality || EffectsQuality != Other.EffectsQuality || FoliageQuality != Other.FoliageQuality || ShadingQuality != Other.ShadingQuality)
		return false;

	if(MasterVolume != Other.MasterVolume || MusicVolume != Other.MusicVolume || SFXVolume != Other.SFXVolume || VoiceVolume != Other.VoiceVolume || AmbianceVolume != Other.AmbianceVolume)
		return false;

	if(IsBloodEnabled != Other.IsBloodEnabled || IsGoreEnabled != Other.IsGoreEnabled || IsInsectsEnabled != Other.IsInsectsEnabled || Language != Other.Language || IsSubtitleEnabled != Other.IsSubtitleEnabled)
		return false;

	if(MouseSensitivity != Other.MouseSensitivity)
		return false;
	
	return true; //All equal
}


void UUserSettingsProfile::setQualityPresetIndex(int Index)
{
	QualityPreset = Index;
	if(QualityPreset != -1) //Custom -> -1
	{
		ResolutionQuality = Index;
		ViewDistanceQuality = Index;
		AntiAliasingQuality = Index;
		ShadowQuality = Index;
		GlobalIlluminationQuality = Index;
		ReflectionQuality = Index;
		PostProcessQuality = Index;
		TextureQuality = Index;
		EffectsQuality = Index;
		FoliageQuality = Index;
		ShadingQuality = Index;
	}
}

void UUserSettingsProfile::Print()
{
	UE_LOG(LogTemp, Warning, TEXT("SettingsProfile: "));
	UE_LOG(LogTemp, Warning, TEXT("VSync: %d"), VSyncEnabled);
	UE_LOG(LogTemp, Warning, TEXT("WindowMode: %d"), WindowMode);
	UE_LOG(LogTemp, Warning, TEXT("Resolution: %s"), *Resolution);
	UE_LOG(LogTemp, Warning, TEXT("Gamma: %f"), Gamma);
	UE_LOG(LogTemp, Warning, TEXT("Brightness: %f"), Brightness);
	UE_LOG(LogTemp, Warning, TEXT("QualityPresetIndex: %d"), QualityPreset);
	UE_LOG(LogTemp, Warning, TEXT("ResolutionQuality: %d"), ResolutionQuality);
	UE_LOG(LogTemp, Warning, TEXT("ViewDistanceQuality: %d"), ViewDistanceQuality);
	UE_LOG(LogTemp, Warning, TEXT("AntiAliasingQuality: %d"), AntiAliasingQuality);
	UE_LOG(LogTemp, Warning, TEXT("ShadowQuality: %d"), ShadowQuality);
	UE_LOG(LogTemp, Warning, TEXT("GlobalIlluminationQuality: %d"), GlobalIlluminationQuality);
	UE_LOG(LogTemp, Warning, TEXT("ReflectionQuality: %d"), ReflectionQuality);
	UE_LOG(LogTemp, Warning, TEXT("PostProcessQuality: %d"), PostProcessQuality);
	UE_LOG(LogTemp, Warning, TEXT("TextureQuality: %d"), TextureQuality);
	UE_LOG(LogTemp, Warning, TEXT("EffectsQuality: %d"), EffectsQuality);
	UE_LOG(LogTemp, Warning, TEXT("FoliageQuality: %d"), FoliageQuality);
	UE_LOG(LogTemp, Warning, TEXT("ShadingQuality: %d"), ShadingQuality);
	UE_LOG(LogTemp, Warning, TEXT("MasterVolume: %f"), MasterVolume);
	UE_LOG(LogTemp, Warning, TEXT("MusicVolume: %f"), MusicVolume);
	UE_LOG(LogTemp, Warning, TEXT("SFXVolume: %f"), SFXVolume);
	UE_LOG(LogTemp, Warning, TEXT("VoiceVolume: %f"), VoiceVolume);
	UE_LOG(LogTemp, Warning, TEXT("AmbianceVolume: %f"), AmbianceVolume);
	UE_LOG(LogTemp, Warning, TEXT("IsBloodEnabled: %d"), IsBloodEnabled);
	UE_LOG(LogTemp, Warning, TEXT("IsGoreEnabled: %d"), IsGoreEnabled);
	UE_LOG(LogTemp, Warning, TEXT("IsInsectsEnabled: %d"), IsInsectsEnabled);
	UE_LOG(LogTemp, Warning, TEXT("Language: %s"), *Language);
	UE_LOG(LogTemp, Warning, TEXT("IsSubtitleEnabled: %d"), IsSubtitleEnabled);
	UE_LOG(LogTemp, Warning, TEXT("MouseSensitivity: %f"), MouseSensitivity);
}



