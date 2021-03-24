#pragma once
#pragma region step 7
#include "State.hpp"
#include "SpriteNode.h"


class TitleState : public State
{
public:
	TitleState(StateStack* stack, Context* context);

	virtual void		draw();
	virtual bool		update(GameTimer& gt);
	virtual bool		handleEvent(WPARAM btnState);
	virtual bool		handleRealtimeInput();


};
#pragma endregion
