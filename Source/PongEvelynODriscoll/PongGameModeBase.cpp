// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameModeBase.h"
#include "PongGameStateBase.h"
#include <Kismet/GameplayStatics.h>

APongGameModeBase::APongGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void APongGameModeBase::BeginPlay() {
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABallSpawner::StaticClass(), SpawnArray);
	BallSpawner = Cast<ABallSpawner>(SpawnArray[0]);
}

void APongGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APongGameModeBase::Reset() {
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABall::StaticClass(), BallArray);
	Ball = Cast<ABall>(BallArray[0]);

	Ball->Destroy();

	BallSpawner->SpawnBall();

}
