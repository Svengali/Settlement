// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModBase.generated.h"



/*
UENUM( BlueprintType )
enum EConnectionFace
{
	ConnectionFace_Invalid,
	ConnectionFace_PosX,
	ConnectionFace_NegX,
	ConnectionFace_PosY,
	ConnectionFace_NegY,
	ConnectionFace_PosZ,
	ConnectionFace_NegZ,
};
*/

static FName CnxTorque( "CnxTorque" );
static FName CnxLiquid( "CnxLiquid" );
static FName CnxPower ( "CnxPower" );
static FName CnxGas   ( "CnxGas" );



USTRUCT()
struct FTmplConnection
{
	GENERATED_BODY()

	FName CnxType;

	FIntVector  LocalCnx;

};

USTRUCT()
struct F8Data
{
	GENERATED_BODY()
};



UCLASS()
class SETTLEMENT_API AModBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AModBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	TArray<FTmplConnection> Connections;


};
