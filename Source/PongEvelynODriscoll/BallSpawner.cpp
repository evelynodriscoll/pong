// Fill out your copyright notice in the Description page of Project Settings.


#include "BallSpawner.h"
#include "Ball.h"

// Sets default values
ABallSpawner::ABallSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABallSpawner::BeginPlay()
{
	Super::BeginPlay();
    SpawnBall();
	
}

// Called every frame
void ABallSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABallSpawner::SpawnBall()
{
    if (!IsValid(BallObject))
    {
        FActorSpawnParameters SpawnParams;
       
        SpawnParams.Owner = this;
       
        SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

        BallObject = GetWorld()->SpawnActor<ABall>(BallBlueprint, GetActorLocation(), GetActorRotation(), SpawnParams);
    }
}
