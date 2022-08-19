// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsMenuWidget.h"
#include "Components/Button.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

void USettingsMenuWidget::SetCurrentOptionsToAllFields()
{
	//Set the resolution combo box to the current resolution
	FString CurrentResolution = FString::FromInt(Settings->GetScreenResolution().X) + "x" + FString::FromInt(Settings->GetScreenResolution().Y);
	ResolutionComboBox->SetSelectedOption(CurrentResolution);
	
	//Sets the window mode combo box to the current window mode
	FString CurrentWindowMode;
	if(Settings->GetFullscreenMode() == EWindowMode::Fullscreen)
		CurrentWindowMode = "Fullscreen";
	else if(Settings->GetFullscreenMode() == EWindowMode::WindowedFullscreen)
		CurrentWindowMode = "Borderless";
	else
		CurrentWindowMode = "Windowed";
	WindowModeComboBox->SetSelectedOption(CurrentWindowMode);
	
	//Sets the quality combo box to the current quality level
	int CurrentQualityLevel = Settings->ScalabilityQuality.GetSingleQualityLevel(); //Get the current quality level, -1 if "Custom"
	if(CurrentQualityLevel == -1)
		QualityPresetComboBox->SetSelectedOption("Custom");
	else
	{
		QualityPresetComboBox->SetSelectedIndex(CurrentQualityLevel);
	}

	//Sets the V-Sync checkbox to the current V-Sync setting
	if(Settings->IsVSyncEnabled())
		VSyncCheckBox->SetCheckedState(ECheckBoxState::Checked);
	else
		VSyncCheckBox->SetCheckedState(ECheckBoxState::Unchecked);
	
	//PostProcessing
}

void USettingsMenuWidget::SetActionFunctionsForInputs()
{
	AudioOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnAudioOptionButtonClicked);
	DisplayOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnDisplayOptionButtonClicked);
	GameplayOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnGameplayOptionButtonClicked);
	ControlsOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnControlsOptionButtonClicked);
	GraphicsOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnGraphicsOptionButtonClicked);
	
	ResolutionComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::SetResolution);
	WindowModeComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::SetWindowMode);
	QualityPresetComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::SetQualityPreset);
	VSyncCheckBox->OnCheckStateChanged.AddDynamic(this, &USettingsMenuWidget::SetVSync);
	BrightnessSlider->OnValueChanged.AddDynamic(this, &USettingsMenuWidget::SetBrightness);
	GammaSlider->OnValueChanged.AddDynamic(this, &USettingsMenuWidget::SetGamma);
	
	DisplayApplyButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::ApplySettings);
	DisplayResetButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::ResetSettings);
}

void USettingsMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	Settings = GEngine->GetGameUserSettings();

	OnAudioOptionButtonClicked(); // Show the audio panel by default

	SetCurrentOptionsToAllFields();

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