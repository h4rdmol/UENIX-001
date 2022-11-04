// Fill out your copyright notice in the Description page of Project Settings.


#include "AutoDestroyableActor.h"

// Sets default values
AAutoDestroyableActor::AAutoDestroyableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AAutoDestroyableActor::BeginPlay()
{
	Super::BeginPlay();
	if ( TimeToDestroy > 0 && (TimeToDestroy))
	{
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AAutoDestroyableActor::DestroyObject, 1.0f, false,
									this->TimeToDestroy);	
	}
}

// Called every frame
void AAutoDestroyableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAutoDestroyableActor::DestroyObject()
{
	this->Destroy();
	UE_LOG(LogTemp, Warning, TEXT("Actor Destroyed"));
}

