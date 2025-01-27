#pragma once
#include "string"
#include "vector"
#include "vector2.h"

using namespace std;

class GameObject
{
private:
	static vector<GameObject*> gameObjects;
	vector2 position;
	vector2 size;
	bool isActive;
	bool isGarbage;
	
public:
	GameObject();
	GameObject(vector2 position);
	virtual ~GameObject();


	vector2 GetPosition();
	vector2 GetSize();
	static vector<GameObject*> GetAllGameObjects();
	bool IsActive();
	bool IsGarbage();

	// Setters
	void SetPosition(vector2 position);
	void SetSize(vector2 size);
	void SetActiveState(bool isActive);

	// Class Functions

	// TODO: CONSIDER ELIMINATING THE HIDE FUNCTION IF IT'S NEVER USED
	//void Hide();
	bool Collided(vector2 otherPosition, vector2 otherSize);
	void FlagForCleanup();
	
	// Virtual Functions
	virtual void Draw() = 0;
	virtual void Move(float loopIncrease) = 0;
};
