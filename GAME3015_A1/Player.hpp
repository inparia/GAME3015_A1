#pragma once
#include "Command.hpp"

class CommandQueue;

class Player
{
public:
	void handleEvent(CommandQueue& commands);
	void handleRealtimeInput(CommandQueue& commands);

};


