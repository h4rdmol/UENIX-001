// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimatedActor.h"

// Sets default values
AAnimatedActor::AAnimatedActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
	TextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>("TextRender");
	TextRenderComponent->SetText(FText::FromString(TEXT("Test")));
	TextRenderComponent->SetTextRenderColor(FColor::Black);
	TextRenderComponent->SetWorldSize(10.f);
	TextRenderComponent->SetRelativeLocation(FVector(200, 20, 20));
	Mesh->SetupAttachment(TextRenderComponent);
	
}

// Called when the game starts or when spawned
void AAnimatedActor::BeginPlay()
{
	Super::BeginPlay();
	
	Material = Mesh->GetMaterial(0);
	DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);
	Mesh->SetMaterial(0, DynamicMaterial);

	// Set timer by value
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AAnimatedActor::SwapColor, 1.0f, true,
									this->TimeToSwapColor);
	
}

// Called every frame
void AAnimatedActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAnimatedActor::SwapColor()
{
	FColor fColor(FMath::RandRange (0.f, 255.f),FMath::RandRange (0.f, 255.f),FMath::RandRange (0.f, 255.f),0);
	FLinearColor FLinearColorColor (fColor);
	FString myString = FString::SanitizeFloat(fColor.R);
	TextRenderComponent->SetText(TEXT("R: ") + FString::SanitizeFloat(fColor.R) + TEXT(" G: ") + FString::SanitizeFloat(fColor.G)+ TEXT(" Blue: ") + FString::SanitizeFloat(fColor.B) );
	DynamicMaterial->SetVectorParameterValue(TEXT("Colour"), FLinearColorColor);
}

