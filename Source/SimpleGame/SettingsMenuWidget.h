// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/ComboBox.h"
#include "SettingsMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API USettingsMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void NativeConstruct() override; //constructor for the class
	
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
    UCanvasPanel* AudioOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
    UCanvasPanel* GraphicsOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
    UCanvasPanel* GameplayOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
    UCanvasPanel* ControlsOptionPanel;

	//Menu Selection Buttons on the left side of the screen
	UPROPERTY(BlueprintReadWrite, Category= Buttons, meta=(BindWidget))
	UButton* AudioOptionButton;
	UPROPERTY(BlueprintReadWrite, Category= Buttons, meta=(BindWidget))
	UButton* GraphicsOptionButton;
	UPROPERTY(BlueprintReadWrite, Category= Buttons, meta=(BindWidget))
	UButton* GameplayOptionButton;
	UPROPERTY(BlueprintReadWrite, Category= Buttons, meta=(BindWidget))
	UButton* ControlsOptionButton;

	UFUNCTION()
	void OnAudioOptionButtonClicked();
	UFUNCTION()
	void OnGraphicsOptionButtonClicked();
	UFUNCTION()
	void OnGameplayOptionButtonClicked();
	UFUNCTION()
	void OnControlsOptionButtonClicked();

	//Logic for the GraphicsOptionPanel
	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBox* WindowModeComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBox* ResolutionComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBox* QualityPresetComboBox;
	
	UFUNCTION(BlueprintCallable)
	void SetResolution(FString Resolution);

	UFUNCTION(BlueprintCallable)
	void SetWindowMode(FString WindowMode);

	UFUNCTION(BlueprintCallable)
	void SetQualityPreset(FString QualityPreset);

	UFUNCTION(BlueprintCallable)
	void SetBrightness(FString Brightness);

	UFUNCTION(BlueprintCallable)
	void SetGamma(FString Gamma);

	//Logic for the AudioOptionPanel
	//TODO

	//Logic for the GameplayOptionPanel
	//TODO

	//Logic for the ControlsOptionPanel
	//TODO
};
