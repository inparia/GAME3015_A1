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
	}
}
