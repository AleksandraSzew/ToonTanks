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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
private:

	UPROPERTY(VisibleAnywhere, Category = "Pawn components")
	class USpringArmComponent* ArmComponent;
	UPROPERTY(VisibleAnywhere, Category = "Pawn components")
	class UCameraComponent* Camera;

	void Move(float value);
	void Turn(float value);

protected:
	virtual void BeginPlay() override;
public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	APlayerController* PlayerController;	
	void HandleDestruction();
	APlayerController* GetTankPlayerController() const { return PlayerController; }


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float Speed = 200.f; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float TurnRate = 100.f;

};
