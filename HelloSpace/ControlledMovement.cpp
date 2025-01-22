#include <iostream>
#include "ControlledMovement.h"
#include "AwesomeLibrary.h"

using namespace std;

ControlledMovement::ControlledMovement() : Movement() {};
ControlledMovement::~ControlledMovement() = default;

vector2 ControlledMovement::InputToVector()
{
	// GetKeyState is a function of WinUser.h, which is included by the AwesomeLibrary.h when it includes windows.h

	if (IsDirectionAllowed(UP) && GetKeyState(0x26) < 0) // Up Arrow
	{
		return vectorUp;
	}
	else if (IsDirectionAllowed(DOWN) && GetKeyState(0x28) < 0) // Down Arrow
	{
		return vectorDown;
	}
	else if (IsDirectionAllowed(LEFT) && GetKeyState(0x25) < 0) // Left Arrow
	{
		return vectorLeft;
	}
	else if (IsDirectionAllowed(RIGHT) && GetKeyState(0x27) < 0) // Right Arrow
	{
		return vectorRight;
	}
	else // default to a vector zero.
	{
		return vectorZero;
	}
}
void ControlledMovement::CaptureInput()
{
	SetMovementVector(InputToVector());
}