#pragma once
#include "Movement.h"

using namespace std;

class PredefinedMovement : public Movement
{
public:
	PredefinedMovement();
	~PredefinedMovement();

	void DefineMovement(directions direction);
};
