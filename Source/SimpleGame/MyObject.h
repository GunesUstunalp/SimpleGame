#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyObject.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAME_API UMyObject : public UObject
{
	GENERATED_BODY()
public:
	UMyObject();

	float myFloat;

	void MyFunction();
};
