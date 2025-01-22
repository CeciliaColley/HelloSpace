#pragma once
#include "Movement.h"

class ControlledMovement : public Movement
{
private:
	/// <summary>
	/// <para> Checks which Arrow key is pressed and if the direction is permisable. </para>
	/// <para> Defaults to a vector 0 if the Arrow key that is pressed isn't allowed. </para>
	/// </summary>
	vector2 InputToVector();

public:
	ControlledMovement();
	~ControlledMovement();
	
	/// <summary>
	/// <para> Uses the InputToVector function to set the movementVector member variable. </para>
	/// </summary>
	void CaptureInput();
};