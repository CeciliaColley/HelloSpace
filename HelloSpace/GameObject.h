#pragma once
#include "string"
#include "vector"
#include "vector2.h"

using namespace std;

class GameObject
{
private:
	static vector<GameObject*> activeGameObjects;
	static vector<GameObject*> inactiveGameObjects;
	vector2 position;
	vector2 size;
	bool isActive;
	bool isPooled;
public:
	GameObject();
	GameObject(vector2 position);
	virtual ~GameObject();

	// Getters
	static vector<GameObject*> GetActiveGameObjects();
	static vector<GameObject*> GetInactiveGameObjects();
	vector2 GetPosition();
	vector2 GetSize();
	bool IsActive();
	bool IsPooled();

	// Setters
	void SetPosition(vector2 position);
	void SetSize(vector2 size);
	void SetActiveState(bool activeState);
	void SetIsPooled(bool isPooled);

	// Class Functions

	// TODO: CONSIDER ELIMINATING THE HIDE FUNCTION IF IT'S NEVER USED
	//void Hide();
	bool Collided(vector2 otherPosition, vector2 otherSize);
	void FindAndErase(vector<GameObject*> &theVector, GameObject* gameObject);
	
	// Virtual Functions
	virtual void Draw() = 0;
	virtual void Move() = 0;
};
