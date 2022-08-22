// Fill out your copyright notice in the Description page of Project Settings.


#include "UserProfile.h"

UUserProfile::UUserProfile()
{
	VSyncEnabled = true;
	WindowMode = EWindowMode::Windowed;
	Resolution = "1280x720";
	Gamma = 2.2f;
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

UUserProfile::UUserProfile(UUserProfile& Other)
{
	VSyncEnabled = Other.VSyncEnabled;
	WindowMode = Other.WindowMode;
	Resolution = Other.Resolution;
	Gamma = Other.Gamma;
	Brightness = Other.Brightness;
	
	QualityPresetIndex = Other.QualityPresetIndex;
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

bool UUserProfile::operator==(const UUserProfile& Other) const
{
	if(VSyncEnabled != Other.VSyncEnabled || WindowMode != Other.WindowMode || Resolution != Other.Resolution || Gamma != Other.Gamma || Brightness != Other.Brightness)
		return false;

	if(QualityPresetIndex != Other.QualityPresetIndex || ResolutionQuality != Other.ResolutionQuality || ViewDistanceQuality != Other.ViewDistanceQuality || AntiAliasingQuality != Other.AntiAliasingQuality || ShadowQuality != Other.ShadowQuality || GlobalIlluminationQuality != Other.GlobalIlluminationQuality || ReflectionQuality != Other.ReflectionQuality || PostProcessQuality != Other.PostProcessQuality || TextureQuality != Other.TextureQuality || EffectsQuality != Other.EffectsQuality || FoliageQuality != Other.FoliageQuality || ShadingQuality != Other.ShadingQuality)
		return false;

	if(MasterVolume != Other.MasterVolume || MusicVolume != Other.MusicVolume || SFXVolume != Other.SFXVolume || VoiceVolume != Other.VoiceVolume || AmbianceVolume != Other.AmbianceVolume)
		return false;

	if(IsBloodEnabled != Other.IsBloodEnabled || IsGoreEnabled != Other.IsGoreEnabled || IsInsectsEnabled != Other.IsInsectsEnabled || Language != Other.Language || IsSubtitleEnabled != Other.IsSubtitleEnabled)
		return false;

	if(MouseSensitivity != Other.MouseSensitivity)
		return false;
	
	return true; //All equal
}


void UUserProfile::setQualityPresetIndex(int Index)
{
	QualityPresetIndex = Index;
	if(QualityPresetIndex != -1) //Custom -> -1
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


