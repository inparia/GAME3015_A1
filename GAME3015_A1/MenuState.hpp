#pragma once
#pragma region step 1
#include "State.hpp"
#include "SpriteNode.h"

class MenuState : public State
{
public:
	MenuState(StateStack* stack, Context* context);

	virtual void			draw();
	virtual bool			update(GameTimer& gt);
	virtual bool			handleEvent(WPARAM btnState);
	virtual bool			handleRealtimeInput();
	void					updateOptionText();


private:
	enum OptionNames
	{
		Play,
		Exit,
	};

};

#pragma endregion
