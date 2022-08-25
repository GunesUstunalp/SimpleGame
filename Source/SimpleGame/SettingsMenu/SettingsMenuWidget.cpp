// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsMenuWidget.h"
#include "Components/Button.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

void USettingsMenuWidget::SetCurrentOptionsToAllFields()
{
	//Audio Options
	MasterSlider->SetValue(CurrentSettingsProfile->MasterVolume);
	SFXSlider->SetValue(CurrentSettingsProfile->SFXVolume);
	AmbianceSlider->SetValue(CurrentSettingsProfile->AmbianceVolume);
	MusicSlider->SetValue(CurrentSettingsProfile->MusicVolume);
	VoiceSlider->SetValue(CurrentSettingsProfile->VoiceVolume);
	//Display Options
	switch (CurrentSettingsProfile->WindowMode)
	{
	case EWindowMode::Fullscreen:
		WindowModeComboBox->SetSelectedIndex(0);
		break;
	case EWindowMode::WindowedFullscreen:
		WindowModeComboBox->SetSelectedIndex(1);
		break;
	case EWindowMode::Windowed:
		WindowModeComboBox->SetSelectedIndex(2);
		break;
	default:
		UE_LOG(LogTemp, Error, TEXT("ERROR! Unknown WindowMode!!!"));
	}
	ResolutionComboBox->SetSelectedOption(CurrentSettingsProfile->Resolution);
	VSyncCheckBox->SetCheckedState(CurrentSettingsProfile->VSyncEnabled ? ECheckBoxState::Checked : ECheckBoxState::Unchecked);
	BrightnessSlider->SetValue(CurrentSettingsProfile->Brightness);
	GammaSlider->SetValue(CurrentSettingsProfile->Gamma);
	//Gameplay Options
	LanguageComboBox->SetSelectedOption(CurrentSettingsProfile->Language);
	SubtitlesCheckBox->SetCheckedState(CurrentSettingsProfile->IsSubtitleEnabled ? ECheckBoxState::Checked : ECheckBoxState::Unchecked);
	BloodCheckBox->SetCheckedState(CurrentSettingsProfile->IsBloodEnabled ? ECheckBoxState::Checked : ECheckBoxState::Unchecked);
	GoreCheckBox->SetCheckedState(CurrentSettingsProfile->IsGoreEnabled ? ECheckBoxState::Checked : ECheckBoxState::Unchecked);
	InsectsCheckBox->SetCheckedState(CurrentSettingsProfile->IsInsectsEnabled ? ECheckBoxState::Checked : ECheckBoxState::Unchecked);
	//Controls Options
	MouseSensitivitySlider->SetValue(CurrentSettingsProfile->MouseSensitivity);
	//Graphics Options
	QualityPresetComboBox->SetSelectedIndex(4 - CurrentSettingsProfile->QualityPreset);
	ResolutionQualityComboBox->SetSelectedIndex(4 - CurrentSettingsProfile->ResolutionQuality);
	ViewDistanceComboBox->SetSelectedIndex(4 - CurrentSettingsProfile->ViewDistanceQuality);
	AntiAliasingComboBox->SetSelectedIndex(4 - CurrentSettingsProfile->AntiAliasingQuality);
	ShadowQualityComboBox->SetSelectedIndex(4 - CurrentSettingsProfile->ShadowQuality);
	GlobalIlluminationQualityComboBox->SetSelectedIndex(4 - CurrentSettingsProfile->GlobalIlluminationQuality);
	ReflectionQualityComboBox->SetSelectedIndex(4 - CurrentSettingsProfile->ReflectionQuality);
	PostProcessQualityComboBox->SetSelectedIndex(4 - CurrentSettingsProfile->PostProcessQuality);
	TextureQualityComboBox->SetSelectedIndex(4 - CurrentSettingsProfile->TextureQuality);
	EffectsQualityComboBox->SetSelectedIndex(4 - CurrentSettingsProfile->EffectsQuality);
	FoliageQualityComboBox->SetSelectedIndex(4 - CurrentSettingsProfile->FoliageQuality);
	ShadingQualityComboBox->SetSelectedIndex(4 - CurrentSettingsProfile->ShadingQuality);
}

void USettingsMenuWidget::SetActionFunctionsForInputs()
{
	//Option panel buttons
	AudioOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnAudioOptionButtonClicked);
	DisplayOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnDisplayOptionButtonClicked);
	GameplayOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnGameplayOptionButtonClicked);
	ControlsOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnControlsOptionButtonClicked);
	GraphicsOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnGraphicsOptionButtonClicked);

	//Audio option panel
	MasterSlider->OnValueChanged.AddDynamic(AudioOptionPanel, &UAudioOptionPanel::OnMasterSliderValueChanged);
	SFXSlider->OnValueChanged.AddDynamic(AudioOptionPanel, &UAudioOptionPanel::OnSFXSliderValueChanged);
	AmbianceSlider->OnValueChanged.AddDynamic(AudioOptionPanel, &UAudioOptionPanel::OnAmbianceSliderValueChanged);
	MusicSlider->OnValueChanged.AddDynamic(AudioOptionPanel, &UAudioOptionPanel::OnMusicSliderValueChanged);
	VoiceSlider->OnValueChanged.AddDynamic(AudioOptionPanel, &UAudioOptionPanel::OnVoiceSliderValueChanged);
	AudioApplyButton->OnClicked.AddDynamic(AudioOptionPanel, &UAudioOptionPanel::OnAudioApplyButtonClicked);
	AudioResetButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::AudioResetButtonHelper);

	//Display option panel
	WindowModeComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::WindowModeComboBoxHelper);
	ResolutionComboBox->OnSelectionChanged.AddDynamic(DisplayOptionPanel, &UDisplayOptionPanel::OnResolutionComboBoxSelectionChanged);
	VSyncCheckBox->OnCheckStateChanged.AddDynamic(DisplayOptionPanel, &UDisplayOptionPanel::OnVSyncCheckBoxSelectionChanged);
	BrightnessSlider->OnValueChanged.AddDynamic(DisplayOptionPanel, &UDisplayOptionPanel::OnBrightnessSliderValueChanged);
	GammaSlider->OnValueChanged.AddDynamic(DisplayOptionPanel, &UDisplayOptionPanel::OnGammaSliderValueChanged);
	DisplayApplyButton->OnClicked.AddDynamic(DisplayOptionPanel, &UDisplayOptionPanel::OnDisplayApplyButtonClicked);
	DisplayResetButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::DisplayResetButtonHelper);
	
	//Gameplay option panel
	LanguageComboBox->OnSelectionChanged.AddDynamic(GameplayOptionPanel, &UGameplayOptionPanel::OnLanguageComboBoxSelectionChanged);
	SubtitlesCheckBox->OnCheckStateChanged.AddDynamic(GameplayOptionPanel, &UGameplayOptionPanel::OnSubtitlesCheckBoxSelectionChanged);
	BloodCheckBox->OnCheckStateChanged.AddDynamic(GameplayOptionPanel, &UGameplayOptionPanel::OnBloodCheckBoxSelectionChanged);
	GoreCheckBox->OnCheckStateChanged.AddDynamic(GameplayOptionPanel, &UGameplayOptionPanel::OnGoreCheckBoxSelectionChanged);
	InsectsCheckBox->OnCheckStateChanged.AddDynamic(GameplayOptionPanel, &UGameplayOptionPanel::OnInsectsCheckBoxSelectionChanged);
	GameplayApplyButton->OnClicked.AddDynamic(GameplayOptionPanel, &UGameplayOptionPanel::OnGameplayApplyButtonClicked);
	GameplayResetButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::GameplayResetButtonHelper);
	
	//Controls option panel
	MouseSensitivitySlider->OnValueChanged.AddDynamic(ControlsOptionPanel, &UControlsOptionPanel::OnMouseSensitivitySliderValueChanged);
	ControlsApplyButton->OnClicked.AddDynamic(ControlsOptionPanel, &UControlsOptionPanel::OnControlsApplyButtonClicked);
	ControlsResetButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::ControlsResetButtonHelper);
	
	//Graphics option panel
	QualityPresetComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::QualityPresetComboBoxHelper);
	ResolutionQualityComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::ResolutionQualityComboBoxHelper);
	ViewDistanceComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::ViewDistanceComboBoxHelper);
	AntiAliasingComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::AntiAliasingComboBoxHelper);
	ShadowQualityComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::ShadowQualityComboBoxHelper);
	GlobalIlluminationQualityComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::GlobalIlluminationComboBoxHelper);
	ReflectionQualityComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::ReflectionQualityComboBoxHelper);
	PostProcessQualityComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::PostProcessComboBoxHelper);
	TextureQualityComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::TextureQualityComboBoxHelper);
	EffectsQualityComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::EffectsQualityComboBoxHelper);
	FoliageQualityComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::FoliageQualityComboBoxHelper);
	ShadingQualityComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::ShadingQualityComboBoxHelper);
	GraphicsAutoDetectButton->OnClicked.AddDynamic(GraphicsOptionPanel, &UGraphicsOptionPanel::OnGraphicsAutoDetectButtonClicked);
	GraphicsApplyButton->OnClicked.AddDynamic(GraphicsOptionPanel, &UGraphicsOptionPanel::OnGraphicsApplyButtonClicked);
	GraphicsResetButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::GraphicsResetButtonHelper);
}

void USettingsMenuWidget::SetUserSettingsProfilePointersForOptionPanels()
{
	AudioOptionPanel->CurrentSettingsProfile = CurrentSettingsProfile;
	DisplayOptionPanel->CurrentSettingsProfile = CurrentSettingsProfile;
	GameplayOptionPanel->CurrentSettingsProfile = CurrentSettingsProfile;
	ControlsOptionPanel->CurrentSettingsProfile = CurrentSettingsProfile;
	GraphicsOptionPanel->CurrentSettingsProfile = CurrentSettingsProfile;
}

void USettingsMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	Settings = GEngine->GetGameUserSettings();
	if(UGameplayStatics::DoesSaveGameExist("SettingsProfile", 0))
	{
		SavedSettingsProfile = Cast<UUserSettingsProfile>(UGameplayStatics::LoadGameFromSlot("SettingsProfile", 0));
	}
	else
	{
		SavedSettingsProfile = NewObject<UUserSettingsProfile>();
	}
    
	CurrentSettingsProfile = NewObject<UUserSettingsProfile>();
	CurrentSettingsProfile->SetFromOther(*SavedSettingsProfile);
	

	OnAudioOptionButtonClicked(); // Show the audio panel by default
	SetCurrentOptionsToAllFields();
	SetUserSettingsProfilePointersForOptionPanels();
	SetActionFunctionsForInputs();
}

void USettingsMenuWidget::SetResolution(FString Resolution, ESelectInfo::Type SelectionType)
{
	FString LeftS, RightS;
	Resolution.Split("x", &LeftS, &RightS);
	Settings->SetScreenResolution(FIntPoint(UKismetStringLibrary::Conv_StringToInt(LeftS), UKismetStringLibrary::Conv_StringToInt(RightS)));
	Settings->ApplySettings(false);
}

void USettingsMenuWidget::SetWindowMode(FString WindowMode, ESelectInfo::Type SelectionType)
{
	// if(WindowMode == "Fullscreen")
	// 	Settings->SetFullscreenMode(EWindowMode::Fullscreen);
	// else if(WindowMode.Equals("Windowed"))
	// 	Settings->SetFullscreenMode(EWindowMode::Windowed);
	// else if(WindowMode.Equals("Borderless"))
	// 	Settings->SetFullscreenMode(EWindowMode::WindowedFullscreen);
	// else
	// {
	// 	UE_LOG(LogTemp, Error, TEXT("ERROR! Unknown WindowMode!!!"));
	// }

	int selected = WindowModeComboBox->GetSelectedIndex(); //Instead of using the above code, we can use the selected index of the combo box to set the window mode to make the selection name agnostic i.e. "Borderless" is the same as "WindowedFullscreen"
	switch (selected)
	{
	case 0:
		Settings->SetFullscreenMode(EWindowMode::Fullscreen);
		break;
	case 1:
		Settings->SetFullscreenMode(EWindowMode::WindowedFullscreen);
		break;
	case 2:
		Settings->SetFullscreenMode(EWindowMode::Windowed);
		break;
	default:
		UE_LOG(LogTemp, Error, TEXT("ERROR! Unknown WindowMode!!!"));
	}
	
	//Settings->ApplySettings(false);
}

void USettingsMenuWidget::SetQualityPreset(FString QualityPreset, ESelectInfo::Type SelectionType)
{
	// if(QualityPreset.Equals("Very Low"))
	// 	Settings->ScalabilityQuality.SetFromSingleQualityLevel(0);
	// else if(QualityPreset.Equals("Low"))
	// 	Settings->ScalabilityQuality.SetFromSingleQualityLevel(1);
	// else if(QualityPreset.Equals("Medium"))
	// 	Settings->ScalabilityQuality.SetFromSingleQualityLevel(2);
	// else if(QualityPreset.Equals("High"))
	// 	Settings->ScalabilityQuality.SetFromSingleQualityLevel(3);
	// else if(QualityPreset.Equals("Very High"))
	// 	Settings->ScalabilityQuality.SetFromSingleQualityLevel(4);
	// else
	// 	UE_LOG(LogTemp, Error, TEXT("ERROR! Unknown QualityPreset!!!"));

	int selected = QualityPresetComboBox->GetSelectedIndex(); //Instead of using the above code, we can use the selected index of the combo box to set the quality preset to make the selection name agnostic i.e. "Cinematic" is the same as "Very High"
	if(selected != 5) //If the selected index is not the custom quality level
		Settings->ScalabilityQuality.SetFromSingleQualityLevel(4 - selected); //The quality preset is set from the highest quality to the lowest quality, so we have to reverse the index
	//Settings->ApplySettings(false);
}

void USettingsMenuWidget::SetVSync(bool VSync)
{
	Settings->SetVSyncEnabled(VSync);

	//TODO: Wait for ApplySettings() to set the VSyncEnabled value to true
}

void USettingsMenuWidget::SetBrightness(float Brightness)
{
	//UGameplayStatics::GetActorOfClass(PostProcessVolume, this)->SetFloatParameterValue("Brightness", Brightness);
}

void USettingsMenuWidget::SetGamma(float Gamma)
{
	float LerpedValue = FMath::Lerp(0.f, 4.4f, Gamma);
	GetOwningPlayer()->ConsoleCommand("gamma " + FString::SanitizeFloat(LerpedValue));
	//TODO:Do not apply immediately, wait for ApplySettings() to set the Gamma value to the correct value
	//Settings->SetGamma(Gamma);
}


void USettingsMenuWidget::ApplySettings()
{
	Settings->ApplySettings(false);
}

void USettingsMenuWidget::ResetSettings()
{
	//Gamma
	GammaSlider->SetValue(0.5f);
	GetOwningPlayer()->ConsoleCommand("gamma " + FString::SanitizeFloat(2.2f));
	//TODO: Reset the settings to the default values
}




void USettingsMenuWidget::OnAudioOptionButtonClicked()
{
	AudioOptionButton->SetIsEnabled(false);
	DisplayOptionButton->SetIsEnabled(true);
	GameplayOptionButton->SetIsEnabled(true);
	ControlsOptionButton->SetIsEnabled(true);
	GraphicsOptionButton->SetIsEnabled(true);
	
	OptionSwitcher->SetActiveWidgetIndex(0);
}

void USettingsMenuWidget::OnDisplayOptionButtonClicked()
{
	DisplayOptionButton->SetIsEnabled(false);
	AudioOptionButton->SetIsEnabled(true);
	GameplayOptionButton->SetIsEnabled(true);
	ControlsOptionButton->SetIsEnabled(true);
	GraphicsOptionButton->SetIsEnabled(true);
	
	OptionSwitcher->SetActiveWidgetIndex(1);
}

void USettingsMenuWidget::OnGameplayOptionButtonClicked()
{
	GameplayOptionButton->SetIsEnabled(false);
	AudioOptionButton->SetIsEnabled(true);
	DisplayOptionButton->SetIsEnabled(true);
	ControlsOptionButton->SetIsEnabled(true);
	GraphicsOptionButton->SetIsEnabled(true);
	
	OptionSwitcher->SetActiveWidgetIndex(2);
}

void USettingsMenuWidget::OnControlsOptionButtonClicked()
{
	ControlsOptionButton->SetIsEnabled(false);
	AudioOptionButton->SetIsEnabled(true);
	DisplayOptionButton->SetIsEnabled(true);
	GameplayOptionButton->SetIsEnabled(true);
	GraphicsOptionButton->SetIsEnabled(true);
	
	OptionSwitcher->SetActiveWidgetIndex(3);
}

void USettingsMenuWidget::OnGraphicsOptionButtonClicked()
{
	GraphicsOptionButton->SetIsEnabled(false);
	ControlsOptionButton->SetIsEnabled(true);
	AudioOptionButton->SetIsEnabled(true);
	DisplayOptionButton->SetIsEnabled(true);
	GameplayOptionButton->SetIsEnabled(true);
	
	OptionSwitcher->SetActiveWidgetIndex(4);
}