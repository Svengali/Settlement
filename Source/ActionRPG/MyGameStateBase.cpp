// Copyright Marc Hernandez All Rights Reserved.


#include "MyGameStateBase.h"

#include "Items/Item.h"



AMyGameStateBase::AMyGameStateBase()
{
	bGameOver = false;
}

static bool SDoTest = false;

void AMyGameStateBase::HandleBeginPlay()
{

	if (SDoTest)
	{
		UItemTest::TestSimplex();
	}


}

bool AMyGameStateBase::HasMatchEnded() const
{
	return bGameOver;
}

void AMyGameStateBase::GameOver()
{
	if (bGameOver == false)
	{
		K2_OnGameOver();
		bGameOver = true;
	}
}