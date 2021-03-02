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

void Player::handleEvent(CommandQueue& commands)
{

}
void Player::handleRealtimeInput(CommandQueue& commands)
{
	const float playerSpeed = 30.f;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		Command moveLeft;
		moveLeft.category = Category::PlayerAircraft;
		moveLeft.action = derivedAction<Aircraft>(
			AircraftMover(-playerSpeed, 0.f, 0.f));
		commands.push(moveLeft);
	}

	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		Command moveRight;
		moveRight.category = Category::PlayerAircraft;
		moveRight.action = derivedAction<Aircraft>(
			AircraftMover(playerSpeed, 0.f, 0.f));
		commands.push(moveRight);
	}

	else if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		Command moveUp;
		moveUp.category = Category::PlayerAircraft;
		moveUp.action = derivedAction<Aircraft>(
			AircraftMover(0.f, 0.f, playerSpeed));
		commands.push(moveUp);
	}

	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		Command moveDown;
		moveDown.category = Category::PlayerAircraft;
		moveDown.action = derivedAction<Aircraft>(
			AircraftMover(0.f, 0.f, -playerSpeed));
		commands.push(moveDown);
	}
	else
	{
		Command stopMove;
		stopMove.category = Category::PlayerAircraft;
		stopMove.action = derivedAction<Aircraft>(
			AircraftMover(0.f, 0.f, 0.f));
		commands.push(stopMove);
	}
}
