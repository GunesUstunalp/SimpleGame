// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "SettingsMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API USettingsMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	
public:
	USettingsMenuWidget(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(BlueprintReadWrite, Category= Panels)
    UCanvasPanel* AudioOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels)
    UCanvasPanel* GraphicsOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels)
    UCanvasPanel* GameplayOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels)
    UCanvasPanel* ControlsOptionPanel;
    
	UFUNCTION(BlueprintCallable)
	void SetResolution(FString Resolution);
};
