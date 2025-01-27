#include "Movement.h"

Movement::Movement()
{
	movementVector = vectorZero;
	for (int i = 0; i < LAST; i++)
	{
		permittedMovementDirections[i] = true;
	}
	speed = 1;
	// Larger speed values result in smaller thresholds and therefore shorter delays.
	movementDelay = 1 / speed;
	currentDelay = movementDelay;
}

Movement::~Movement() = default;

vector2 Movement::GetMovementVector()
{
	return movementVector;
}

void Movement::SetSpeed(float speed)
{
	this->speed = speed;
	// Larger speed values result in smaller thresholds and therefore shorter delays.
	movementDelay = 1 / speed;
	currentDelay = movementDelay;
}

void Movement::SetMovementVector(vector2 movementVector)
{
	this->movementVector = movementVector;
}

void Movement::SetDirectionAllowed(directions direction, bool permision)
{
	permittedMovementDirections[direction] = permision;
}

bool Movement::DirectionIsAllowed(directions direction)
{
	return permittedMovementDirections[direction];
}
vector2 Movement::DirectionToVector(directions direction)
{
	switch (direction)
	{
	case UP:
		return vectorUp;
		break;
	case DOWN:
		return vectorDown;
		break;
	case LEFT:
		return vectorLeft;
		break;
	case RIGHT:
		return vectorRight;
		break;
	default:
		return vectorZero;
		break;
	}
}
bool Movement::MovementDelayPerformed(float loopTime)
{
	if (currentDelay >= movementDelay)
	{
		currentDelay = 0;
		return true;
	}
	else
	{
		currentDelay += loopTime;
		return false;
	}
}