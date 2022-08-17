// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsMenuWidget.h"
#include "Components/Button.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/KismetStringLibrary.h"

void USettingsMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	Settings = GEngine->GetGameUserSettings();
	
	AudioOptionPanel->SetVisibility(ESlateVisibility::Visible); // Show the audio panel by default
	GraphicsOptionPanel->SetVisibility(ESlateVisibility::Hidden);
	GameplayOptionPanel->SetVisibility(ESlateVisibility::Hidden);
	ControlsOptionPanel->SetVisibility(ESlateVisibility::Hidden);

	//At the editor the Render Transforms of the option menu panels are set different from each other to easily edit them. If not they would overlap on each other
	//But we have to set the Render Transforms of the panels to the default value before executing the code
	//This is the reason the code piece below exists, to reset the Render Transforms of those panels
	const FWidgetTransform PanelTransform(FVector2D(0.f,0.f),FVector2D(1.f,1.f),FVector2D(0.f,0.f),0.f); //Default transform
	AudioOptionPanel->SetRenderTransform(PanelTransform);
	GraphicsOptionPanel->SetRenderTransform(PanelTransform);
	GameplayOptionPanel->SetRenderTransform(PanelTransform);
	ControlsOptionPanel->SetRenderTransform(PanelTransform);

	AudioOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnAudioOptionButtonClicked);
	GraphicsOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnGraphicsOptionButtonClicked);
	GameplayOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnGameplayOptionButtonClicked);
	ControlsOptionButton->OnClicked.AddDynamic(this, &USettingsMenuWidget::OnControlsOptionButtonClicked);

	ResolutionComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::SetResolution);
	WindowModeComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::SetWindowMode);
	QualityPresetComboBox->OnSelectionChanged.AddDynamic(this, &USettingsMenuWidget::SetQualityPreset);
	
}

void USettingsMenuWidget::SetResolution(FString Resolution, ESelectInfo::Type SelectionType) //TODO: TIDY-UP
{
	FString LeftS, RightS;
	Resolution.Split("x", &LeftS, &RightS);
	UE_LOG(LogTemp,Warning, TEXT("Tried : %s %s"), *LeftS, *RightS);

	Settings->SetScreenResolution(FIntPoint(UKismetStringLibrary::Conv_StringToInt(LeftS), UKismetStringLibrary::Conv_StringToInt(RightS)));
	Settings->ApplySettings(false);
	//GEngine->GameUserSettings->SetScreenResolution(FIntPoint(UKismetStringLibrary::Conv_StringToInt(LeftS), UKismetStringLibrary::Conv_StringToInt(RightS)));
	//GEngine->GameUserSettings->ApplyResolutionSettings(false);
	//GEngine->GameUserSettings->ApplySettings(false);
	UE_LOG(LogTemp, Warning, TEXT("Set : %i, %i"), GEngine->GameUserSettings->GetScreenResolution().X, GEngine->GameUserSettings->GetScreenResolution().Y);
}

void USettingsMenuWidget::SetWindowMode(FString WindowMode, ESelectInfo::Type SelectionType)
{
	if(WindowMode.Equals("Fullscreen"))
		Settings->SetFullscreenMode(EWindowMode::Fullscreen);
	else if(WindowMode.Equals("Windowed"))
		Settings->SetFullscreenMode(EWindowMode::Windowed);
	else if(WindowMode.Equals("Borderless"))
		Settings->SetFullscreenMode(EWindowMode::WindowedFullscreen);
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR! Unknown WindowMode!!!"));
	}

	Settings->ApplySettings(false);
}

void USettingsMenuWidget::SetQualityPreset(FString QualityPreset, ESelectInfo::Type SelectionType)
{
	if(QualityPreset.Equals("Very Low"))
		Settings->ScalabilityQuality.SetFromSingleQualityLevel(0);
	else if(QualityPreset.Equals("Low"))
		Settings->ScalabilityQuality.SetFromSingleQualityLevel(1);
	else if(QualityPreset.Equals("Medium"))
		Settings->ScalabilityQuality.SetFromSingleQualityLevel(2);
	else if(QualityPreset.Equals("High"))
		Settings->ScalabilityQuality.SetFromSingleQualityLevel(3);
	else if(QualityPreset.Equals("Very High"))
		Settings->ScalabilityQuality.SetFromSingleQualityLevel(4);
	else
		UE_LOG(LogTemp, Error, TEXT("ERROR! Unknown QualityPreset!!!"));
	
	Settings->ApplySettings(false);
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
