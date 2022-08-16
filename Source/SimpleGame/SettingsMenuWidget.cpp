// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsMenuWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "GameFramework/GameUserSettings.h"
#include "Kismet/KismetStringLibrary.h"

void USettingsMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
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

	WindowModeComboBox
}

void USettingsMenuWidget::SetResolution(FString Resolution) //TODO: TIDY-UP
{
	FString LeftS, RightS;
	Resolution.Split("x", &LeftS, &RightS);
	UE_LOG(LogTemp,Warning, TEXT("Tried : %s %s"), *LeftS, *RightS);
	GEngine->GameUserSettings->SetScreenResolution(FIntPoint(UKismetStringLibrary::Conv_StringToInt(LeftS), UKismetStringLibrary::Conv_StringToInt(RightS)));
	GEngine->GameUserSettings->ApplyResolutionSettings(false);
	UE_LOG(LogTemp, Warning, TEXT("Set : %i, %i"), GEngine->GameUserSettings->GetScreenResolution().X, GEngine->GameUserSettings->GetScreenResolution().Y);
}

void USettingsMenuWidget::SetWindowMode(FString WindowMode)
{
	if(WindowMode.Equals("Fullscreen"))
		GEngine->GameUserSettings->SetFullscreenMode(EWindowMode::Fullscreen);
	else if(WindowMode.Equals("Windowed"))
		GEngine->GameUserSettings->SetFullscreenMode(EWindowMode::Windowed);
	else if(WindowMode.Equals("Borderless"))
		GEngine->GameUserSettings->SetFullscreenMode(EWindowMode::WindowedFullscreen);
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR! Unknown WindowMode!!!"));
	}
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
