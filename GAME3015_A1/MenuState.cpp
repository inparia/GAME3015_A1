#include "MenuState.hpp"
#include "SpriteNode.h"
#include "Game.hpp"

MenuState::MenuState(StateStack* stack, Context* context)
	: State(stack, context)
{

	mCameraPos = XMFLOAT3(0.f, 0.f, -10.f);
	mTargetPos = XMFLOAT3(0.f, 0.f, 0.f);

	std::unique_ptr<SpriteNode> backgroundSprite = std::make_unique<SpriteNode>(this);

	backgroundSprite->SetMatGeoDrawName("MenuStateBackMat", "shapeGeo", "quad");
	backgroundSprite->setScale(XMVectorSet(13, 10, 1, 0));
	backgroundSprite->setPosition(XMVectorSet(0, 0, 1, 0));
	mSceneGraph->attachChild(std::move((backgroundSprite)));

	mSceneGraph->build();

	mContext->game->BuildFrameResources(mAllRitems.size());
}

void MenuState::draw()
{
	mSceneGraph->draw();
}

bool MenuState::update(GameTimer& gt)
{
	mSceneGraph->update(gt);
	return true;
}


bool MenuState::handleEvent(WPARAM btnState)
{
	requestStackPop();
	requestStackPush(States::Menu);
	return true;
}

bool MenuState::handleRealtimeInput()
{
	return true;
}
void MenuState::updateOptionText()
{
}
