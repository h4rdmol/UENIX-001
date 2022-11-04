// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AutoDestroyableActor.generated.h"

UCLASS()
class NIXUE_API AAutoDestroyableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAutoDestroyableActor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NIXTab)
	float TimeToDestroy;
	FTimerHandle TimerHandle;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void DestroyObject ();

};
