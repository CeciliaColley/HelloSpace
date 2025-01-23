#include "Movement.h"

Movement::Movement()
{
	movementVector = vectorZero;
	for (int i = 0; i < LAST; i++)
	{
		permittedMovementDirections[i] = true;
	}
}

Movement::~Movement() = default;

vector2 Movement::GetMovementVector()
{
	return movementVector;
}

void Movement::SetMovementVector(vector2 movementVector)
{
	this->movementVector = movementVector;
}

void Movement::SetDirectionAllowed(directions direction, bool permision)
{
	permittedMovementDirections[direction] = permision;
}

bool Movement::IsDirectionAllowed(directions direction)
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