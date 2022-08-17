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
}

void USettingsMenuWidget::SetActionFunctionsForInputs()
{
	AudioOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnAudioOptionButtonClicked);
	GraphicsOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnGraphicsOptionButtonClicked);
	GameplayOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnGameplayOptionButtonClicked);
	ControlsOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnControlsOptionButtonClicked);

	ResolutionComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::SetResolution);
	WindowModeComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::SetWindowMode);
	QualityPresetComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::SetQualityPreset);
	VSyncCheckBox->OnCheckStateChanged.AddDynamic(this, &USettingsMenuWidget::SetVSync);
	BrightnessSlider->OnValueChanged.AddDynamic(this, &USettingsMenuWidget::SetBrightness);
	GammaSlider->OnValueChanged.AddDynamic(this, &USettingsMenuWidget::SetGamma);

	
	ApplyButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::ApplySettings);
	ResetButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::ResetSettings);

	
}

void USettingsMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	Settings = GEngine->GetGameUserSettings();

	OnAudioOptionButtonClicked(); // Show the audio panel by default

	SetCurrentOptionsToAllFields();

	SetActionFunctionsForInputs();
	
	//At the editor the Render Transforms of the option menu panels are set different from each other to easily edit them. If not they would overlap on each other
	//But we have to set the Render Transforms of the panels to the default value before executing the code
	//This is the reason the code piece below exists, to reset the Render Transforms of those panels
	const FWidgetTransform PanelTransform(FVector2D(0.f,0.f),FVector2D(1.f,1.f),FVector2D(0.f,0.f),0.f); //Default transform
	AudioOptionPanel->SetRenderTransform(PanelTransform);
	GraphicsOptionPanel->SetRenderTransform(PanelTransform);
	GameplayOptionPanel->SetRenderTransform(PanelTransform);
	ControlsOptionPanel->SetRenderTransform(PanelTransform);
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
	
	Settings->ApplySettings(false);
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
	Settings->ApplySettings(false);
}

void USettingsMenuWidget::SetVSync(bool VSync)
{
	Settings->SetVSyncEnabled(VSync);
}

void USettingsMenuWidget::SetBrightness(float Brightness)
{
	UGameplayStatics::GetActorOfClass(PostProcessVolu, this)->SetFloatParameterValue("Brightness", Brightness);
}

void USettingsMenuWidget::SetGamma(float Gamma)
{
	Settings->SetGamma(Gamma);
}


void USettingsMenuWidget::ApplySettings()
{
	Settings->ApplySettings(false);
}

void USettingsMenuWidget::ResetSettings()
{
	//TODO: Reset the settings to the default values
}




void USettingsMenuWidget::OnAudioOptionButtonClicked()
{
	
	AudioOptionPanel->SetVisibility(ESlateVisibility::Visible);
	GraphicsOptionPanel->SetVisibility(ESlateVisibility::Hidden);
	GameplayOptionPanel->SetVisibility(ESlateVisibility::Hidden);
	ControlsOptionPanel->SetVisibility(ESlateVisibility::Hidden);
}

void USettingsMenuWidget::OnGraphicsOptionButtonClicked()
{
	AudioOptionPanel->SetVisibility(ESlateVisibility::Hidden);
	GraphicsOptionPanel->SetVisibility(ESlateVisibility::Visible);
	GameplayOptionPanel->SetVisibility(ESlateVisibility::Hidden);
	ControlsOptionPanel->SetVisibility(ESlateVisibility::Hidden);
}

void USettingsMenuWidget::OnGameplayOptionButtonClicked()
{
	AudioOptionPanel->SetVisibility(ESlateVisibility::Hidden);
	GraphicsOptionPanel->SetVisibility(ESlateVisibility::Hidden);
	GameplayOptionPanel->SetVisibility(ESlateVisibility::Visible);
	ControlsOptionPanel->SetVisibility(ESlateVisibility::Hidden);
}

void USettingsMenuWidget::OnControlsOptionButtonClicked()
{
	AudioOptionPanel->SetVisibility(ESlateVisibility::Hidden);
	GraphicsOptionPanel->SetVisibility(ESlateVisibility::Hidden);
	GameplayOptionPanel->SetVisibility(ESlateVisibility::Hidden);
	ControlsOptionPanel->SetVisibility(ESlateVisibility::Visible);
}
