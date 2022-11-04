// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/Actor.h"
#include "AnimatedActor.generated.h"

UCLASS()
class NIXUE_API AAnimatedActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAnimatedActor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NIXTab)
	float TimeToSwapColor;
	FTimerHandle TimerHandle;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = NIXTab)
	UMaterialInterface* Material;
	
	UPROPERTY(EditAnywhere, Category = NIXTab)
	UMaterialInstance* MaterialInstance;
	
	UTextRenderComponent* TextRenderComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SwapColor ();
private:
	UMaterialInstanceDynamic* DynamicMaterial;
};
