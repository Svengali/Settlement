// Copyright Marc Hernandez All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONRPG_API AMyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
	/** Constructor */
	AMyGameStateBase();

	/** Called by game mode to set the started play bool */
	virtual void HandleBeginPlay() override;


	/** Returns true if GameOver() has been called, false otherwise */
	virtual bool HasMatchEnded() const override;

	/** Called when the game is over i.e. the player dies, the time runs out or the
	 *	game is finished*/
	UFUNCTION(BlueprintCallable, Category = Game)
		virtual void GameOver();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = Game, meta = (DisplayName = "DoRestart", ScriptName = "DoRestart"))
		void K2_DoRestart();

	UFUNCTION(BlueprintImplementableEvent, Category = Game, meta = (DisplayName = "OnGameOver", ScriptName = "OnGameOver"))
		void K2_OnGameOver();

	UPROPERTY(BlueprintReadOnly, Category = Game)
		uint32 bGameOver : 1;


};
