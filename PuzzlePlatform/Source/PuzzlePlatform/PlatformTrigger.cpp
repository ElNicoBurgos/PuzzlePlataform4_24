// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"
#include "PuzzlePlatformCharacter.h"

// Sets default values
APlatformTrigger::APlatformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComponentRef = CreateAbstractDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponentRef;
	BoxComponentRef->InitBoxExtent(FVector(50.f, 50.f, 100.f));
	
	MeshComponentRef = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponentRef->SetupAttachment(BoxComponentRef);
}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	BoxComponentRef->OnComponentBeginOverlap.AddUniqueDynamic(this, &APlatformTrigger::OnBeginOverlap);
	BoxComponentRef->OnComponentEndOverlap.AddUniqueDynamic(this, &APlatformTrigger::OnOverlapEnd);
}

// Called every frame
void APlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformTrigger::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APuzzlePlatformCharacter* MyCharacter = Cast<APuzzlePlatformCharacter>(OtherActor);
	check(MyCharacter);
	UE_LOG(LogTemp, Warning, TEXT("Pise"));
}

void APlatformTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	APuzzlePlatformCharacter* MyCharacter = Cast<APuzzlePlatformCharacter>(OtherActor);
	check(MyCharacter);
	UE_LOG(LogTemp, Warning, TEXT("Me fui"));
}

