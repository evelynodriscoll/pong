// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPaddle.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/BoxComponent.h"
#include "Ball.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AAIPaddle::AAIPaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AICollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	AIPaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PaddleMesh"));
	AIPaddleMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	SetRootComponent(AIPaddleMesh);

	SetActorEnableCollision(true);

	AIPaddleMesh->SetupAttachment(AICollision);
	//AIPaddleMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	AICollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	AICollision->SetSimulatePhysics(true);
	AICollision->SetEnableGravity(false);
	AICollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

}

// Called when the game starts or when spawned
void AAIPaddle::BeginPlay()
{
	Super::BeginPlay();
	AICollision->OnComponentHit.AddDynamic(this, &AAIPaddle::OnHit);
	
}

void AAIPaddle::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

}

void AAIPaddle::AIMove(FVector BallLocation)
{

	float BallX = BallLocation.X;

	FVector temp = GetActorLocation();
	temp.SetComponentForAxis(EAxis::X, BallX);
	SetActorLocation(temp);

}


// Called every frame
void AAIPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABall::StaticClass(), BallArray);
	Ball = Cast<ABall>(BallArray[0]);

	FVector BallLocation = Ball->GetActorLocation();
	AIMove(BallLocation);

}

void AAIPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
}




