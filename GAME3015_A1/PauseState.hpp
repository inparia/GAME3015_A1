#pragma region step 2
#pragma once

#include "State.hpp"


class PauseState : public State
{
public:
	PauseState(StateStack& stack, Context context);

	virtual void		draw();
	virtual bool		update(GameTimer& gt);
	virtual bool		handleEvent(WPARAM btnState);


private:
	SpriteNode*		mBackgroundSprite;
	SceneNode* mPausedText;
	SceneNode* mInstructionText;
};

#pragma endregion