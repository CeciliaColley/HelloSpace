#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
private:
public:
	Bullet();
	Bullet(vector2 position);
	~Bullet();

	void Draw() override;
	void Move() override;
};
