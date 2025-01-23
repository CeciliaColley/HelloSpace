#include <iostream>
#include "ControlledMovement.h"
#include "AwesomeLibrary.h"

using namespace std;

ControlledMovement::ControlledMovement() : Movement() {};
ControlledMovement::~ControlledMovement() = default;

Movement::directions ControlledMovement::InputToDirection()
{
	// GetKeyState is a function of WinUser.h, which is included by the AwesomeLibrary.h when it includes windows.h
	// NOTE: Due to the use of else if diagonal movement is not currently possible.

	if (GetKeyState(0x26) < 0) // Up Arrow
	{
		return UP;
	}
	else if (GetKeyState(0x28) < 0) // Down Arrow
	{
		return DOWN;
	}
	else if (GetKeyState(0x25) < 0) // Left Arrow
	{
		return LEFT;
	}
	else if (GetKeyState(0x27) < 0) // Right Arrow
	{
		return RIGHT;
	}
	else // default to no direction
	{
		return LAST;
	}
}
void ControlledMovement::ControlMovement()
{
	directions inputDirection = InputToDirection();
	if (IsDirectionAllowed(inputDirection))
	{
		vector2 inputVector = DirectionToVector(inputDirection);
		SetMovementVector(inputVector);
	}
}