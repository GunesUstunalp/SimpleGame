// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/CheckBox.h"
#include "Components/ComboBox.h"
#include "Components/ComboBoxString.h"
#include "Components/Slider.h"
#include "Components/WidgetSwitcher.h"
#include "SettingsMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API USettingsMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION()
	void NativeConstruct() override; //constructor for the class
	UGameUserSettings* Settings; //pointer to the game user settings
	
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
    UCanvasPanel* AudioOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
    UCanvasPanel* DisplayOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
    UCanvasPanel* GameplayOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
    UCanvasPanel* ControlsOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
	UCanvasPanel* GraphicsOptionPanel;

	UPROPERTY(BlueprintReadWrite, Category = Panels, meta = (BindWidget))
	UWidgetSwitcher* OptionSwitcher;
	
	//Menu Selection Buttons on the left side of the screen
	UPROPERTY(BlueprintReadWrite, Category= Buttons, meta=(BindWidget))
	UButton* AudioOptionButton;
	UPROPERTY(BlueprintReadWrite, Category= Buttons, meta=(BindWidget))
	UButton* DisplayOptionButton;
	UPROPERTY(BlueprintReadWrite, Category= Buttons, meta=(BindWidget))
	UButton* GameplayOptionButton;
	UPROPERTY(BlueprintReadWrite, Category= Buttons, meta=(BindWidget))
	UButton* ControlsOptionButton;
	UPROPERTY(BlueprintReadWrite, Category= Buttons, meta=(BindWidget))
	UButton* GraphicsOptionButton;

	UFUNCTION()
	void OnAudioOptionButtonClicked();
	UFUNCTION()
	void OnDisplayOptionButtonClicked();
	UFUNCTION()
	void OnGameplayOptionButtonClicked();
	UFUNCTION()
	void OnControlsOptionButtonClicked();
	UFUNCTION()
	void OnGraphicsOptionButtonClicked();

	//Logic for the DisplayOptionPanel
	UPROPERTY(BlueprintReadWrite, Category= DisplayOption, meta=(BindWidget))
	UComboBoxString* WindowModeComboBox;

	UPROPERTY(BlueprintReadWrite, Category= DisplayOption, meta=(BindWidget))
	UComboBoxString* ResolutionComboBox;

	UPROPERTY(BlueprintReadWrite, Category= DisplayOption, meta=(BindWidget))
	UComboBoxString* QualityPresetComboBox;

	UPROPERTY(BlueprintReadWrite, Category= DisplayOption, meta=(BindWidget))
	UCheckBox* VSyncCheckBox;
	
	UPROPERTY(BlueprintReadWrite, Category= DisplayOption, meta=(BindWidget))
	USlider* BrightnessSlider;

	UPROPERTY(BlueprintReadWrite, Category= DisplayOption, meta=(BindWidget))
	USlider* GammaSlider;

	UPROPERTY(BlueprintReadWrite, Category= DisplayOption, meta=(BindWidget))
	UButton* ApplyButton;

	UPROPERTY(BlueprintReadWrite, Category= DisplayOption, meta=(BindWidget))
	UButton* ResetButton;
	
	UFUNCTION(BlueprintCallable)
	void SetResolution(FString Resolution, ESelectInfo::Type SelectionType); //if it gives an error, make sure to enable "Slate" and "SlateCore" in the build.cs file

	UFUNCTION(BlueprintCallable)
	void SetWindowMode(FString WindowMode, ESelectInfo::Type SelectionType);

	UFUNCTION(BlueprintCallable)
	void SetQualityPreset(FString QualityPreset, ESelectInfo::Type SelectionType);

	UFUNCTION(BlueprintCallable)
	void SetVSync(bool VSync);

	UFUNCTION(BlueprintCallable)
	void SetBrightness(float Brightness);

	UFUNCTION(BlueprintCallable)
	void SetGamma(float Gamma);

	UFUNCTION(BlueprintCallable)
	void ApplySettings();

	UFUNCTION(BlueprintCallable)
	void ResetSettings();
	
	//Logic for the AudioOptionPanel
	//TODO

	//Logic for the GameplayOptionPanel
	//TODO

	//Logic for the ControlsOptionPanel
	//TODO
private:
	void SetCurrentOptionsToAllFields(); //To be used when the menu first opens
	void SetActionFunctionsForInputs(); //To be used in the constructor
};
