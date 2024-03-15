// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"
#include "EngineUtils.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PongGameStateBase.h"
#include "PaddlePlayerController.h"


// Sets default values
ABoard::ABoard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Board"));
	VisualMeshRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VisualMeshRoot"));
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	SetRootComponent(Root);

	SetActorEnableCollision(false);

	VisualMeshRoot->SetupAttachment(Root);

	VisualMesh->SetupAttachment(VisualMeshRoot);

	MainCamera->SetupAttachment(VisualMeshRoot);
	
}

void ABoard::SetCameraToActorContainingACamera()
{
	
	UWorld* World = GetWorld();
	

	if (World) {
		
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		
		for (TActorIterator<ABoard> ActorItr(GetWorld()); ActorItr; ++ActorItr) //Search for ABoard. TActorIterator requires #include "EngineUtils.h"
		{
			
			PC->SetViewTarget(*ActorItr);
			PC->SetViewTargetWithBlend(*ActorItr, 3.f, EViewTargetBlendFunction::VTBlend_Cubic);
		}
	}
	
	
}


// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();
	SetCameraToActorContainingACamera();
	
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

