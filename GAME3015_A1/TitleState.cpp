#include "TitleState.hpp"
#include "SpriteNode.h"
#include "Game.hpp"
TitleState::TitleState(StateStack* stack, Context* context)
	: State(stack, context)
{

	mCameraPos = XMFLOAT3(0.f, 0.f, -10.f);
	mTargetPos = XMFLOAT3(0.f, 0.f, 0.f);

	std::unique_ptr<SpriteNode> backgroundSprite = std::make_unique<SpriteNode>(this);
	backgroundSprite->setMatGeoDrawName("TitleStateBackMat", "shapeGeo", "quad");
	backgroundSprite->setScale(XMVectorSet(13, 10, 1, 0));
	backgroundSprite->setPosition(XMVectorSet(0, 0, 1, 0));
	mSceneGraph->attachChild(std::move((backgroundSprite)));

	std::unique_ptr<SpriteNode> textSprite = std::make_unique<SpriteNode>(this);
	textSprite->setMatGeoDrawName("PressanykeytostartMat", "shapeGeo", "quad");
	textSprite->setScale(XMVectorSet(13, 10, 1, 0));
	textSprite->setPosition(XMVectorSet(0, 0, 1, 0));
	mSceneGraph->attachChild(std::move((textSprite)));

	mSceneGraph->build();

	mContext->game->BuildFrameResources(mAllRitems.size());


}

void TitleState::draw()
{
	mSceneGraph->draw();
}

bool TitleState::update(GameTimer& gt)
{
	mSceneGraph->update(gt);
	return true;
}

bool TitleState::handleEvent(WPARAM btnState)
{
	requestStackPop();
	requestStackPush(States::Menu);
	return true;
}

bool TitleState::handleRealtimeInput()
{
	return true;
}