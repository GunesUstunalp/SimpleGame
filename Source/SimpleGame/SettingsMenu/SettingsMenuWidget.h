// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AudioOptionPanel.h"
#include "ControlsOptionPanel.h"
#include "DisplayOptionPanel.h"
#include "GameplayOptionPanel.h"
#include "GraphicsOptionPanel.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/CheckBox.h"
#include "Components/ComboBox.h"
#include "Components/ComboBoxString.h"
#include "Components/Slider.h"
#include "Components/WidgetSwitcher.h"
#include "SimpleGame/UserSettingsProfile.h"
#include "SettingsMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API USettingsMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UUserSettingsProfile* CurrentSettingsProfile;
	
	UFUNCTION()
	void NativeConstruct() override; //constructor for the class
	UGameUserSettings* Settings; //pointer to the game user settings
	
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
    UAudioOptionPanel* AudioOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
    UDisplayOptionPanel* DisplayOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
    UGameplayOptionPanel* GameplayOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
    UControlsOptionPanel* ControlsOptionPanel;
	UPROPERTY(BlueprintReadWrite, Category= Panels, meta=(BindWidget))
	UGraphicsOptionPanel* GraphicsOptionPanel;

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
	UCheckBox* VSyncCheckBox;
	
	UPROPERTY(BlueprintReadWrite, Category= DisplayOption, meta=(BindWidget))
	USlider* BrightnessSlider;

	UPROPERTY(BlueprintReadWrite, Category= DisplayOption, meta=(BindWidget))
	USlider* GammaSlider;

	UPROPERTY(BlueprintReadWrite, Category= DisplayOption, meta=(BindWidget))
	UButton* DisplayApplyButton;

	UPROPERTY(BlueprintReadWrite, Category= DisplayOption, meta=(BindWidget))
	UButton* DisplayResetButton;
	
	//Logic for the AudioOptionPanel
	UPROPERTY(BlueprintReadWrite, Category= AudioOption, meta=(BindWidget))
	USlider* MasterSlider;
	
	UPROPERTY(BlueprintReadWrite, Category= AudioOption, meta=(BindWidget))
	USlider* SFXSlider;
	
	UPROPERTY(BlueprintReadWrite, Category= AudioOption, meta=(BindWidget))
	USlider* AmbianceSlider;
	
	UPROPERTY(BlueprintReadWrite, Category= AudioOption, meta=(BindWidget))
	USlider* MusicSlider;
	
	UPROPERTY(BlueprintReadWrite, Category= AudioOption, meta=(BindWidget))
	USlider* VoiceSlider;

	UPROPERTY(BlueprintReadWrite, Category= AudioOption, meta=(BindWidget))
	UButton* AudioResetButton;

	UPROPERTY(BlueprintReadWrite, Category= AudioOption, meta=(BindWidget))
	UButton* AudioApplyButton;

	//Logic for the GameplayOptionPanel
	UPROPERTY(BlueprintReadWrite, Category= GameplayOption, meta=(BindWidget))
	UComboBoxString* LanguageComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GameplayOption, meta=(BindWidget))
	UCheckBox* SubtitlesCheckBox;
	
	UPROPERTY(BlueprintReadWrite, Category= GameplayOption, meta=(BindWidget))
	UCheckBox* BloodCheckBox;

	UPROPERTY(BlueprintReadWrite, Category= GameplayOption, meta=(BindWidget))
	UCheckBox* GoreCheckBox;

	UPROPERTY(BlueprintReadWrite, Category= GameplayOption, meta=(BindWidget))
	UCheckBox* InsectsCheckBox;

	UPROPERTY(BlueprintReadWrite, Category= GameplayOption, meta=(BindWidget))
	UButton* GameplayApplyButton;
	
	UPROPERTY(BlueprintReadWrite, Category= GameplayOption, meta=(BindWidget))
	UButton* GameplayResetButton;
	
	//Logic for the ControlsOptionPanel
	UPROPERTY(BlueprintReadWrite, Category= ControlsOption, meta=(BindWidget))
	USlider* MouseSensitivitySlider;

	UPROPERTY(BlueprintReadWrite, Category= ControlsOption, meta=(BindWidget))
	UButton* ControlsApplyButton;
	
	UPROPERTY(BlueprintReadWrite, Category= ControlsOption, meta=(BindWidget))
	UButton* ControlsResetButton;
	
	//Logic for the GraphicsOptionPanel
	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBoxString* QualityPresetComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UButton* GraphicsAutoDetectButton;
	
	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBoxString* ResolutionQualityComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBoxString* ViewDistanceComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBoxString* AntiAliasingComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBoxString* ShadowQualityComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBoxString* GlobalIlluminationQualityComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBoxString* ReflectionQualityComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBoxString* PostProcessQualityComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBoxString* TextureQualityComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBoxString* EffectsQualityComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBoxString* FoliageQualityComboBox;

	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UComboBoxString* ShadingQualityComboBox;
	
	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UButton* GraphicsApplyButton;
	
	UPROPERTY(BlueprintReadWrite, Category= GraphicsOption, meta=(BindWidget))
	UButton* GraphicsResetButton;

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
	
private:
	void SetCurrentOptionsToAllFields(); //To be used when the menu first opens
	void SetActionFunctionsForInputs(); //To be used in the constructor
};
