#include "Player.hpp"
#include "Aircraft.hpp"
#include "Game.hpp"


struct AircraftMover
{

	AircraftMover(float vx, float vy) :
		velocity(vx, vy)
	{
	}


	void operator() (SceneNode& node, const GameTimer&) const
	{
		Aircraft& aircraft = static_cast<Aircraft&>(node);
		aircraft.setVelocity(aircraft.getVelocity().x + velocity.x, aircraft.getVelocity().y + velocity.y);
	}
	XMFLOAT2 velocity;
};

void Player::handleEvent(CommandQueue& commands)
{

}
void Player::handleRealtimeInput(CommandQueue& commands)
{
	const float playerSpeed = 0.1f;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		Command moveLeft;
		moveLeft.category = Category::PlayerAircraft;
		moveLeft.action = derivedAction<Aircraft>(
			AircraftMover(-playerSpeed, 0.f));
		commands.push(moveLeft);
	}
}
