#pragma once
#include "GameObject.h"
#include "PredefinedMovement.h"

class Asteroid : public GameObject
{
private:
	PredefinedMovement predefinedMovement;
public:
	Asteroid();
	~Asteroid();

	void Draw() override;
	void Move(float loopIncrease) override;

	static int speed;
};