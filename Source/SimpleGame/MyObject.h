#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SIMPLEGAME_API UMyObject : public UObject
{
	GENERATED_BODY()
public:
	UMyObject();

	UPROPERTY(BlueprintReadWrite, Category = "MyVariables")
	float myFloat;

	UFUNCTION(BlueprintCallable, Category = "MyFunctions")
	void MyFunction();
};
