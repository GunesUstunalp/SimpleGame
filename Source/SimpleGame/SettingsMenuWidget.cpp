// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsMenuWidget.h"

#include "GameFramework/GameUserSettings.h"
#include "Kismet/KismetStringLibrary.h"

void USettingsMenuWidget::SetResolution(FString Resolution)
{
	FString LeftS, RightS;
	Resolution.Split("x", &LeftS, &RightS);
	UE_LOG(LogTemp,Warning, TEXT("Tried : %s %s"), *LeftS, *RightS);
	GEngine->GameUserSettings->SetScreenResolution(FIntPoint(UKismetStringLibrary::Conv_StringToInt(LeftS), UKismetStringLibrary::Conv_StringToInt(RightS)));
	GEngine->GameUserSettings->ApplyResolutionSettings(false);
	UE_LOG(LogTemp, Warning, TEXT("Set : %i, %i"), GEngine->GameUserSettings->GetScreenResolution().X, GEngine->GameUserSettings->GetScreenResolution().Y);
}
