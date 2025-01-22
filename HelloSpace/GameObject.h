#pragma once
#include <iostream>
#include "vector2.h"

using namespace std;

class GameObject
{
protected:
	vector2 position;
	vector2 size;
public:
	GameObject();
	GameObject(vector2 position);
	~GameObject();

	// Getters
	vector2 GetPosition();
	vector2 GetSize();

	// Setters
	void SetPosition(vector2 position);
	void SetSize(vector2 size);

	// Class Functions
	void Hide();
	bool Collided(vector2 otherPosition, vector2 otherSize);
	
	// Virtual Functions
	virtual void Draw() = 0;
	virtual void Move() = 0;
};
