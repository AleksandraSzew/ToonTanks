// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	ATank();

	
private:

	UPROPERTY(VisibleAnywhere, Category = "Pawn components")
	class USpringArmComponent* ArmComponent;
	UPROPERTY(VisibleAnywhere, Category = "Pawn components")
	class UCameraComponent* Camera;

	void Move(float value);

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
