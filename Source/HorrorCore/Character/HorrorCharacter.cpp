// Copyright (C) Thyke 2025 All Rights Reserved.


#include "HorrorCharacter.h"

#include "HorrorCharacterMovementComponent.h"
#include "GameFramework/Character.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(HorrorCharacter)

AHorrorCharacter::AHorrorCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UHorrorCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = false;
}

void AHorrorCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHorrorCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

