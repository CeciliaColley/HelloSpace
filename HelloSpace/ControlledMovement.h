#pragma once
#include "Movement.h"

class ControlledMovement : public Movement
{
private:
	/// <summary>
	/// <para> Checks which Arrow key is pressed and returns the corresponding direction. </para>
	/// </summary>
	directions InputToDirection();

public:
	ControlledMovement();
	~ControlledMovement();
	
	/// <summary>
	/// <para> Uses the InputToDirection function to validate the direction and set the movementVector member variable. </para>
	/// </summary>
	void ControlMovement();
};