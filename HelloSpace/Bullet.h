#pragma once
#include "GameObject.h"
#include "PredefinedMovement.h"

class Bullet : public GameObject
{
private:
PredefinedMovement predefinedMovement;
public:
	Bullet();
	Bullet(vector2 position);
	~Bullet();

	void Draw() override;
	void Move() override;
};
