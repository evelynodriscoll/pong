// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"
#include "Components/BoxComponent.h"

// Sets default values
AGoal::AGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GoalCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Goal"));
	//RootComponent = GoalMesh;
	SetActorEnableCollision(true);

	GoalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh"));

	SetRootComponent(GoalMesh);

	GoalCollision->SetupAttachment(GoalMesh);
	GoalMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GoalCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

}

// Called when the game starts or when spawned
void AGoal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

