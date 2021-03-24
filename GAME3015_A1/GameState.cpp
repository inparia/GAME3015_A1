#include "GameState.hpp"

GameState::GameState(StateStack* stack, Context* context)
	: State(stack, context)
	, mWorld(*context->mWorld)
	, mPlayer(*context->player)
{

}
void GameState::draw()
{
	mWorld->draw();
}

bool GameState::update(GameTimer& gt)
{
	mWorld.update(gt);

	CommandQueue& commands = mWorld.getCommandQueue();
	mPlayer.handleRealtimeInput(commands);

	return true;
}

bool GameState::handleEvent(CommandQueue& commands)
{
	// Game input handling
	CommandQueue& command = mWorld.getCommandQueue();
	mPlayer.handleEvent(command);

	// Escape pressed, trigger the pause screen
	//if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
	//	requestStackPush(States::Pause);

	return true;
}
