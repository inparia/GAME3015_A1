#pragma region step 3
#pragma once

#include "../../Common/GameTimer.h"
#include "StateIdentifiers.hpp"
#include "ResourceIdentifiers.hpp"
#include "CommandQueue.hpp"
#include "SpriteNode.h"
#include "SceneNode.hpp"
#include "World.hpp"
#include "StateStack.hpp"
#include <memory>
#include <vector>

namespace sf
{
	class RenderWindow;
}

class StateStack;
class Player;
class World;
class SceneNode;

class State
{
public:
	typedef std::unique_ptr<State> Ptr;

	struct Context
	{
		Context(Game* _game, Player* _player);

		Game* game;
		Player* player;
	};


public:
	State(StateStack* stack, Context* context);
	virtual				~State();

	virtual void		draw() = 0;
	virtual bool		update(GameTimer& gt) = 0;
	virtual bool		handleEvent(WPARAM btnState) = 0;
	virtual bool		handleRealtimeInput() = 0;

	XMFLOAT3 GetCameraPos() { return mCameraPos; }
	XMFLOAT3 GetTargetPos() { return mTargetPos; }

	std::vector<std::unique_ptr<RenderItem>>& GetRenderItems() { return mAllRitems; }
	Context*				getContext() const;

protected:
	void				requestStackPush(States::ID stateID);
	void				requestStackPop();
	void				requestStateClear();

protected:
	StateStack*				mStack;
	Context*				mContext;
	XMFLOAT3				mCameraPos;
	XMFLOAT3				mTargetPos;

	std::unique_ptr<SceneNode>	mSceneGraph;

	std::vector<std::unique_ptr<RenderItem>> mAllRitems;
};

#pragma endregion


