#pragma once
#include "Command.hpp"
#include <map>
class CommandQueue;

class Player
{

	enum Action
	{
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown
	};
public:
	Player();
	const float defaultSpeed = 30.0f;
	float playerSpeedX = 0.0f, playerSpeedY = 0.0f;
	void handleEvent(CommandQueue& commands);
	void handleRealtimeInput(CommandQueue& commands);
	void assignKey(Action action, unsigned int vKey);
	unsigned int getAssignedKey(Action action) const;
private:
	bool isKeyPressed(unsigned int vKey);
	bool isRealtimeAction(Action action);
	std::map<int, Action> mKeyBinding;
	std::map<Action, Command> mActionBinding;

};


