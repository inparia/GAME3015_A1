#include "Player.hpp"
#include "Aircraft.hpp"
#include "Game.hpp"


struct AircraftMover
{

	AircraftMover(float vx, float vy, float vz) :
		velocity(vx, vy, vz)
	{
	}


	void operator() (SceneNode& node, const GameTimer&) const
	{
		Aircraft& aircraft = static_cast<Aircraft&>(node);
		aircraft.setVelocity(velocity.x, velocity.y, velocity.z);
	}
	XMFLOAT3 velocity;
};

Player::Player()
{
	mKeyBinding[VK_LEFT] = MoveLeft;
	mKeyBinding[VK_RIGHT] = MoveRight;
	mKeyBinding[VK_DOWN] = MoveDown;
	mKeyBinding[VK_UP] = MoveUp;

}

void Player::handleEvent(CommandQueue& commands)
{
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
	/*const float playerSpeed = 30.f;
	float tempX = 0, tempZ = 0;


	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		Command moveLeft;
		tempX = -playerSpeed;
		moveLeft.category = Category::PlayerAircraft;
		moveLeft.action = derivedAction<Aircraft>(
			AircraftMover(tempX, 0.f, tempZ));
		commands.push(moveLeft);
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		Command moveRight;
		tempX = playerSpeed;
		moveRight.category = Category::PlayerAircraft;
		moveRight.action = derivedAction<Aircraft>(
			AircraftMover(tempX, 0.f, tempZ));
		commands.push(moveRight);
	}


	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		Command moveUp;
		tempZ = playerSpeed;
		moveUp.category = Category::PlayerAircraft;
		moveUp.action = derivedAction<Aircraft>(
			AircraftMover(tempX, 0.f, tempZ));
		commands.push(moveUp);
	}

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		Command moveDown;
		tempZ = -playerSpeed;
		moveDown.category = Category::PlayerAircraft;
		moveDown.action = derivedAction<Aircraft>(
			AircraftMover(tempX, 0.f, tempZ));
		commands.push(moveDown);
	}


	if(GetAsyncKeyState(VK_UP) == 0 && GetAsyncKeyState(VK_DOWN) == 0 && GetAsyncKeyState(VK_RIGHT) == 0&& GetAsyncKeyState(VK_LEFT) == 0)
	{
		Command stopMove;
		stopMove.category = Category::PlayerAircraft;
		stopMove.action = derivedAction<Aircraft>(
			AircraftMover(0.f, 0.f, 0.f));
		commands.push(stopMove);
	}*/


	mActionBinding[MoveLeft].action =
		derivedAction<Aircraft>(
			AircraftMover(playerSpeedX, 0.f, playerSpeedY));

	mActionBinding[MoveRight].action =
		derivedAction<Aircraft>(
			AircraftMover(playerSpeedX, 0.f, playerSpeedY));

	mActionBinding[MoveDown].action =
		derivedAction<Aircraft>(
			AircraftMover(playerSpeedX, 0.f, playerSpeedY));

	mActionBinding[MoveUp].action =
		derivedAction<Aircraft>(
			AircraftMover(playerSpeedX, 0.f, playerSpeedY));


	for (auto& pair : mActionBinding)
		pair.second.category = Category::PlayerAircraft;


	for (auto pair : mKeyBinding)
	{
		if (isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}

	if (!isKeyPressed(VK_UP) && !isKeyPressed(VK_DOWN))
	{
		
		playerSpeedY = 0;
		
	}

	if (!isKeyPressed(VK_LEFT) && !isKeyPressed(VK_RIGHT))
	{
		playerSpeedX = 0;
	}

	if (!isKeyPressed(VK_UP) && !isKeyPressed(VK_DOWN) && !isKeyPressed(VK_LEFT) && !isKeyPressed(VK_RIGHT))
	{
		Command stopMove;
		stopMove.category = Category::PlayerAircraft;
		stopMove.action = derivedAction<Aircraft>(
			AircraftMover(0.f, 0.f, 0.f));
		commands.push(stopMove);
	}
}

unsigned int Player::getAssignedKey(Action action) const
{
	for (auto pair : mKeyBinding)
	{
		if (pair.second == action)
			return pair.first;
	}
	return 0;
}


bool Player::isKeyPressed(unsigned int vKey)
{
	if (GetAsyncKeyState(vKey) & 0x8000)
	{
		if (vKey == VK_LEFT)
		{
			playerSpeedX = -defaultSpeed;
		}
		if (vKey == VK_RIGHT)
		{
			playerSpeedX = defaultSpeed;
		}
		if (vKey == VK_UP)
		{
			playerSpeedY = defaultSpeed;
		}
		if (vKey == VK_DOWN)
		{
			playerSpeedY = -defaultSpeed;
		}
		return true;
	}
	return false;
}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
	case MoveLeft:
	case MoveRight:
	case MoveDown:
	case MoveUp:
		return true;

	default:
		return false;
	}
}

void Player::assignKey(Action action, unsigned int vKey)
{
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyBinding[vKey] = action;
}
