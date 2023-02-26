// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h" 
#include "Components/InputComponent.h" 
#include "Camera/CameraComponent.h" 
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	ArmComponent->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(ArmComponent);
}

void ATank::Move(float value)
{
	//UE_LOG(LogTemp, Warning, TEXT("Move: %f"), value);
	float Delta = UGameplayStatics::GetWorldDeltaSeconds(this);
	
	FVector DeltaLocation(0.f);
	DeltaLocation.X = value*Delta*Speed;

	AddActorLocalOffset(DeltaLocation);
}
// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//binding function to axis maping
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);

}