﻿#include <iostream>
#include "Spaceship.h"
#include "AwesomeLibrary.h"


using namespace std;

/***************************************************************** CONSTRUCTORS AND DECONSTRUCTORS ******************************************************/
Spaceship::Spaceship() : GameObject()
{
	SetSize(vector2(5, 3));
	controlledMovement.SetDirectionAllowed(UP, false);
	controlledMovement.SetDirectionAllowed(DOWN, false);
	gun = new Gun();
}
Spaceship::~Spaceship()
{
	delete gun;
}
/************************************************************************* OVERRIDEN METHODS ************************************************************/
void Spaceship::SetGun(Gun* gun)
{
	this->gun = gun;
}
Gun* Spaceship::GetGun()
{
	return gun;
}
void Spaceship::Shoot()
{
	int offset = GetSize().x / 2;
	gun->Shoot(GetPosition(), offset, UP);
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