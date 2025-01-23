#pragma once
#include "vector2.h"

class Movement
{
public:
	enum directions {UP, DOWN, LEFT, RIGHT,	LAST};

	// Public functions that the owners of the movement can use
	void SetDirectionAllowed(directions direction, bool permision);
	vector2 GetMovementVector();

protected:
	Movement();
	~Movement();

	// Protected functions that each movement type can use for it's given movement
	void SetMovementVector(vector2 movementVector);
	bool IsDirectionAllowed(directions direction);
	vector2 DirectionToVector(directions direction);

private:
	// Private variables specific to the movement object.
	vector2 movementVector;
	bool permittedMovementDirections[LAST];
};
