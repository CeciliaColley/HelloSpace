#include <iostream>
#include "Spaceship.h"
#include "AwesomeLibrary.h"

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
void Spaceship::Draw()
{
	goToCoordinates(position.x, position.y);
	wcout << L"  ▲";
	goToCoordinates(position.x, (position.y + 1));
	wcout << L" (╬)";
	goToCoordinates(position.x, (position.y + 2));
	wcout << L"▲╝ ╚▲";
}
void Spaceship::Move()
{
	controlledMovement.CaptureInput();
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