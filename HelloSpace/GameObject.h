#pragma once
#include <iostream>
#include "vector"
#include "vector2.h"

using namespace std;

class GameObject
{
private:
	vector2 position;
	vector2 size;
	static vector<GameObject*> activeGameObjects;
public:
	GameObject();
	GameObject(vector2 position);
	~GameObject();

	// Getters
	vector2 GetPosition();
	vector2 GetSize();
	static vector<GameObject*> GetActiveGameObjects();

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
