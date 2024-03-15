// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include "Components/BoxComponent.h"
#include "PongGameStateBase.h"
#include "Ball.h"
#include "GameFramework/FloatingPawnMovement.h" // Include the FloatingPawnMovement class for pawn movement operations



// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	PaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PaddleMesh"));
	PaddleMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	SetRootComponent(Collision);
	//PaddleMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Collision->SetSimulatePhysics(true);
	//Collision->SetEnableGravity(false);

	Collision->GetBodyInstance()->bLockXRotation = true;
	Collision->GetBodyInstance()->bLockYRotation = true;
	Collision->GetBodyInstance()->bLockZRotation = true;
	//PlayerRoot->GetBodyInstance()->bLockXTranslation = true;
	Collision->GetBodyInstance()->bLockYTranslation = true;
	Collision->GetBodyInstance()->bLockZTranslation = true;

	PaddleMesh->SetupAttachment(Collision);

	SetActorEnableCollision(true);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	Collision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();



}


// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
		
}

void APaddle::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

}

void APaddle::MoveForward(float Amount)
{

	FVector Location = GetActorLocation() + FVector(1.0f, 0.0f, 0.0f) * Amount * 5000 * GetWorld()->GetDeltaSeconds();
	SetActorLocation(Location);
	
		
}


// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APaddle::MoveForward);

}

