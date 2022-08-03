#include "MyObject.h"

UMyObject::UMyObject() {
	myFloat = 0.f;
}

void UMyObject::MyFunction() {
	UE_LOG(LogTemp, Warning, TEXT("This is our warning text!"));
}