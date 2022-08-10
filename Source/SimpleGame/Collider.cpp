// Fill out your copyright notice in the Description page of Project Settings.


#include "Collider.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "ColliderMovementComponent.h"

// Sets default values
ACollider::ACollider()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SetRootComponent(SphereComponent);
	SphereComponent->InitSphereRadius(40.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(GetRootComponent());
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshComponentAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (MeshComponentAsset.Succeeded()) {
		MeshComponent->SetStaticMesh(MeshComponentAsset.Object);
		MeshComponent->SetRelativeLocation(FVector(0.f, 0.f, -40.f));
		MeshComponent->SetWorldScale3D(FVector(0.8f, 0.8f, 0.8f));
	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->SetRelativeRotation(FRotator(0.f, 0.f, 0.f)); //changed
	SpringArm->TargetArmLength = 400.f;
	SpringArm->bEnableCameraLag = true; //what does it do?
	SpringArm->CameraLagSpeed = 3.0f; 

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	OurMovementComponent = CreateDefaultSubobject<UColliderMovementComponent>(TEXT("OurMovementComponent"));
	OurMovementComponent->UpdatedComponent = RootComponent;

	CameraInput = FVector2D(0.f, 0.f);

	//AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ACollider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator NewRotation = GetActorRotation();

	//UE_LOG(LogTemp, Warning, TEXT("CameraInput.X is %f"), CameraInput.X);

	NewRotation.Yaw += RotationInput.X + CameraInput.X;
	NewRotation.Pitch += RotationInput.Y; //new


	///***Option 1
	//NewRotation.Roll += RotationInput.X;

	///***Option 2
	/*if (RotationInput.X != 0)
		NewRotation.Roll += RotationInput.X;
	else {
		if (NewRotation.Roll < 1 && NewRotation.Roll > -1)
			NewRotation.Roll = 0;
		else if (NewRotation.Roll > 0)
			NewRotation.Roll -= DeltaTime * 60;
		else if (NewRotation.Roll < 0)
			NewRotation.Roll += DeltaTime * 60;
	}*/

	///***Option 3
	FRotator NewMeshRotation = MeshComponent->GetRelativeRotation();
	NewMeshRotation.Pitch = FMath::Fmod(NewMeshRotation.Pitch + 360.0f, 360.0f);
	//UE_LOG(LogTemp, Warning, TEXT("NewMeshRotation = %f, %f, %f"), NewMeshRotation.Pitch, NewMeshRotation.Yaw, NewMeshRotation.Roll);

	if (RotationInput.X + CameraInput.X != 0) {
		if(NewMeshRotation.Pitch < 88.f || NewMeshRotation.Pitch > 272.f)
			NewMeshRotation.Pitch += (RotationInput.X + CameraInput.X) * 2;
		else {
			if (NewMeshRotation.Pitch < 180.f)
				NewMeshRotation.Pitch = 89.f;
			else
				NewMeshRotation.Pitch = 271.f;
		}
	}
	else {
		if (NewMeshRotation.Pitch < 2.f || NewMeshRotation.Pitch > 358.f)
			NewMeshRotation.Pitch = 0.f;
		else if (NewMeshRotation.Pitch < 180.f)
			NewMeshRotation.Pitch -= DeltaTime * 120;
		else
			NewMeshRotation.Pitch += DeltaTime * 120;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("NewMeshRotation.Pitch = %f   and RotationInput.X = %f"), NewMeshRotation.Pitch, RotationInput.X);

	MeshComponent->SetRelativeRotation(FRotator(NewMeshRotation.Pitch, 270.f, 0.f) );
	NewRotation.Roll = 0;
	//End of Option 3

	SetActorRotation(NewRotation);




	/*FRotator NewSpringArmRotation = SpringArm->GetComponentRotation();*/
	//NewSpringArmRotation.Pitch = FMath::Clamp(NewSpringArmRotation.Pitch + CameraInput.Y, -80.f, 30.f);
	/*NewSpringArmRotation.Yaw = FMath::Clamp(NewSpringArmRotation.Yaw + CameraInput.X, -45.f, 45.f);
	if (CameraInput.X == 0) {
		if (NewSpringArmRotation.Yaw > 1)
			NewSpringArmRotation.Yaw -= DeltaTime * 30;
		else if (NewSpringArmRotation.Yaw < -1)
			NewSpringArmRotation.Yaw += DeltaTime * 30;
		else
			NewSpringArmRotation.Yaw = 0;
	}

	if (RotationInput.X != 0)
		NewSpringArmRotation.Yaw = 0;*/

	/*SpringArm->SetWorldRotation(NewSpringArmRotation);*/


	

	

	

}

// Called to bind functionality to input
void ACollider::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACollider::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACollider::MoveRight);

	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ACollider::YawCamera);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ACollider::PitchCamera);
}

void ACollider::MoveForward(float input) {
	FVector Forward = GetActorForwardVector();
	if (OurMovementComponent && input > 0)
	{
		OurMovementComponent->AddInputVector(Forward * input);
	}
}
	
void ACollider::MoveRight(float input) {
	RotationInput.X = input;
	CameraInput.X = input;
	//UE_LOG(LogTemp, Warning, TEXT("input is %f"), input);
	FVector Right = GetActorRightVector();
	if (OurMovementComponent)
	{
		OurMovementComponent->AddInputVector(Right * input * 0.2f);
	}
}

void ACollider::PitchCamera(float AxisValue) {
	RotationInput.Y = -1.f * AxisValue;
}

void ACollider::YawCamera(float AxisValue) {
	//UE_LOG(LogTemp, Warning, TEXT("AxisValue is %f"), AxisValue);
	CameraInput.X = AxisValue;
}


UPawnMovementComponent* ACollider::GetMovementComponent() const {
	return OurMovementComponent;
}
