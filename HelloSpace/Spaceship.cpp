#include <iostream>
#include "Spaceship.h"
#include "AwesomeLibrary.h"
#include "Bullet.h"

using namespace std;

/***************************************************************** CONSTRUCTORS AND DECONSTRUCTORS ******************************************************/
Spaceship::Spaceship() : GameObject()
{
	SetSize(vector2(5, 3));
	controlledMovement.SetDirectionAllowed(controlledMovement.UP, false);
	controlledMovement.SetDirectionAllowed(controlledMovement.DOWN, false);
}
Spaceship::~Spaceship() = default;
/************************************************************************* OVERRIDEN METHODS ************************************************************/
void Spaceship::Shoot()
{
	int bulletSpawnX = GetPosition().x + (GetSize().x / 2);
	int bulletSpawnY = GetPosition().y + 1;
	vector2 bulletSpawnPoint = vector2(bulletSpawnX, bulletSpawnY);
	Bullet* bullet = new Bullet(bulletSpawnPoint, Movement::UP);
}
void Spaceship::Draw()
{
	int x = GetPosition().x;
	int y = GetPosition().y;
	goToCoordinates(x, y);
	wcout << L"  ▲";
	goToCoordinates(x, (y + 1));
	wcout << L" (╬)";
	goToCoordinates(x, (y + 2));
	wcout << L"▲╝ ╚▲";
}
void Spaceship::Move()
{
	controlledMovement.ControlMovement();
	vector2 newPosition = GetPosition() + controlledMovement.GetMovementVector();
	try
	{
		SetPosition(newPosition);
	}
	catch (const invalid_argument& e) {}

	// TODO: CHANGE ABOVE LINE TO THE FOLLOWING, TO KEEP THE SPACESHIP IN THE CONFINES OF THE SCREEN.

	/*if (newPosition.x >= screenPosition.x && newPosition.x <= screenPosition.x + screenSize.x)
	{
		try
		{
			SetPosition(newPosition);
		}
		catch (const invalid_argument& e) {}
	}*/
}