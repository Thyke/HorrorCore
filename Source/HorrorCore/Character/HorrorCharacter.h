// Copyright (C) Thyke 2025 All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "HorrorCharacter.generated.h"

UCLASS()
class HORRORCORE_API AHorrorCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AHorrorCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
