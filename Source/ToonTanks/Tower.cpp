// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"


ATower::ATower()
{


}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Tank)
	{
	//Find distance to the tank
	float Distance = FVector::Dist(GetActorLocation(),Tank->GetActorLocation());
	
		//Check to see if Tank is in the range
		if (Distance <= FireRange)
		{
			//If so, rotate turet to the tank
		RotateTuret(Tank->GetActorLocation());

		}
	}
	
}

void ATower::BeginPlay() 
{
	Super::BeginPlay();
	
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0)); 
}
