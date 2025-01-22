#pragma once
#include "GameObject.h"

class Asteroid : public GameObject
{
private:
public:
	Asteroid();
	~Asteroid();

	void Draw() override;
	void Move() override;
};