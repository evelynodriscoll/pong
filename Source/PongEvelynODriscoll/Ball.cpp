// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"
#include "Components/SphereComponent.h"
#include <Engine/StaticMeshActor.h>
#include "Wall.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Paddle.h"
#include "AIPaddle.h"
#include "Board.h"
#include "EngineUtils.h"
#include "Goal.h"
#include "PongGameModeBase.h"
#include "PongGameStateBase.h"
#include "UObject/UObjectBaseUtility.h"


// Sets default values
ABall::ABall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMeshRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VisualMeshRoot"));
	BallMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("BallMovement"));

	//CollisionSphere->SetSimulatePhysics(true);
	SetRootComponent(CollisionSphere);
	//VisualMeshRoot->SetupAttachment(RootComponent);
	VisualMesh->SetupAttachment(CollisionSphere);


	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionSphere->SetCollisionProfileName("Ball");

	CollisionSphere->SetSimulatePhysics(true);
	CollisionSphere->SetEnableGravity(false);

	BallMovement->SetUpdatedComponent(CollisionSphere);
	BallMovement->InitialSpeed = 10000;
	BallMovement->MaxSpeed = 200000;
	BallMovement->bShouldBounce = true;
	BallMovement->Bounciness = 1.0f;
	BallMovement->Friction = 0.0f;

	CollisionSphere->GetBodyInstance()->bLockZTranslation = true;
	CollisionSphere->SetLinearDamping(-1.0f);

	FVector BallDirection = FVector(1.0f, 1.0f, 0.0f);
	BallMovement->Velocity = BallDirection;


	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this,
		&ABall::OnCollisionSphereBeginOverlap);
	CollisionSphere->OnComponentEndOverlap.AddDynamic(this,
		&ABall::OnCollisionSphereEndOverlap);
	CollisionSphere->OnComponentHit.AddDynamic(this,
		&ABall::OnCollisionSphereHit);

	

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}


void ABall::OnCollisionSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor) {

		if (AGoal* Goal = Cast<AGoal>(OtherActor)) {

			APongGameModeBase* GameMode = (APongGameModeBase*)GetWorld()->GetAuthGameMode();
			GameMode->Reset();

			APongGameStateBase* GameState = (APongGameStateBase*)GetWorld()->GetGameState();
			if (Goal->GetName() == "AIGoal") {
				GameState->IncrementScore("Player");
			}
			else {
				GameState->IncrementScore("AI");
			}

			
		}

	}
	
}
	
	


void ABall::OnCollisionSphereHit(UPrimitiveComponent* HitComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	FVector NormalImpulse,
	const FHitResult& Hit)
{

	BallMovement->Velocity = BallMovement->Velocity * 10000;
	
	//DO SOMETHING;

	
}


void ABall::OnCollisionSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}





