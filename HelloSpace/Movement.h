#pragma once
#include "vector2.h"
#include "Directions.h"

class Movement
{
public:
	// Public functions that the owners of the movement can use
	void SetDirectionAllowed(directions direction, bool permision);
	vector2 GetMovementVector();
	bool MovementDelayPerformed(float loopTime);
	void SetSpeed(float speed);

protected:
	Movement();
	~Movement();


	// Protected functions that each movement type can use for it's given movement
	void SetMovementVector(vector2 movementVector);
	bool DirectionIsAllowed(directions direction);
	vector2 DirectionToVector(directions direction);

private:
	// Private variables specific to the movement object.
	vector2 movementVector;
	bool permittedMovementDirections[LAST];
	
	// Variables for movement speed
	float movementDelay;
	float currentDelay;
	float speed;
};
