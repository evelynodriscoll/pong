// Fill out your copyright notice in the Description page of Project Settings.


#include "Wall.h"
#include "Components/BoxComponent.h"

// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WallCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Wall"));
	//RootComponent = WallMesh;
	SetActorEnableCollision(true);

	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh"));

	SetRootComponent(WallCollision);

	WallMesh->SetupAttachment(WallCollision);
	WallMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WallCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	WallCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

