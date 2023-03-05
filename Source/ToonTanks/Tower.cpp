// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

ATower::ATower()
{


}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

		if(IsInDistance())
		{
			//If so, rotate turet to the tank
		RotateTuret(Tank->GetActorLocation());

		}
	
	
}
void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();

}
void ATower::BeginPlay() 
{
	Super::BeginPlay();
	
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0)); 

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{	
	if (IsInDistance())
	{
		Fire();
	}
}

bool ATower::IsInDistance()
{
	//Find distance to the tank
	
	if (Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		//Check to see if Tank is in the range
		if (Distance <= FireRange)
		{
			return true;
		}
		
	}
	return false;
	
}