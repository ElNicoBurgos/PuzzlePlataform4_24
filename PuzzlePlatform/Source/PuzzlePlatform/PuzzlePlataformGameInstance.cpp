// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlataformGameInstance.h"


UPuzzlePlataformGameInstance::UPuzzlePlataformGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Construct"));
}

void UPuzzlePlataformGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
}

void UPuzzlePlataformGameInstance::Host()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Hosting"));

	GetWorld()->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlataformGameInstance::Join(const FString& Address)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "Join to " + Address);
	//GetWorld()->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}
