#pragma region step 1

#pragma once

#include "State.hpp"
#include "World.hpp"
#include "Player.hpp"


class GameState : public State
{
public:
	GameState(StateStack* stack, Context* context);

	virtual void		draw();
	virtual bool		update(GameTimer& gt);
	virtual bool		handleEvent(WPARAM btnState);


private:
	World*				mWorld;
	Player* mPlayer;
};

#pragma endregion

