#include <iostream>
#include <string>
#include "GameObject.h"
#include "AwesomeLibrary.h"


using namespace std;
vector<GameObject*> GameObject::activeGameObjects;
/************************************************************** CONSTRUCTORS AND DECONSTRUCTORS ******************************************************/
GameObject::GameObject()
{
	position = vectorOne;
	size = vectorZero;
	activeGameObjects.push_back(this);
}
GameObject::GameObject(vector2 position)
{
	try
	{
		SetPosition(position);
	}
	catch (const invalid_argument& e)
	{
		cerr << e.what() << endl;
	}
	size = vectorZero;
	activeGameObjects.push_back(this);
}
GameObject::~GameObject() = default;

/************************************************************************* GETTERS *********************************************************************/
vector2 GameObject::GetPosition()
{
	return position;
}
vector2 GameObject::GetSize()
{
	return size;
}
vector<GameObject*> GameObject::GetActiveGameObjects()
{
	return activeGameObjects;
}
/********************************************************************** SETTERS ************************************************************************/
void GameObject::SetPosition(vector2 position)
{
	if (position.x <= 0 || position.y <= 0)
	{
		throw invalid_argument("0 is not allowed for a game object's position.");
	}
	this->position = position;
}
void GameObject::SetSize(vector2 size)
{
	this->size = size;
}

/****************************************************************** CLASS FUNCTIONS ********************************************************************/
void GameObject::Hide()
{
	string line;
	for (int i = 0; i < size.x; i++)
	{
		line += ' ';
	}

	for (int j = 0; j < size.y; j++)
	{
		int verticalPosition = position.y + j;
		goToCoordinates(position.x, verticalPosition);
		cout << line;
	}
}
bool GameObject::Collided(vector2 otherPosition, vector2 otherSize)
{
	if (position.x >= otherPosition.x && position.x <= otherPosition.x + otherSize.x      // Overlapping on the x (horizontal) space
		&& position.y >= otherPosition.y && position.y <= otherPosition.y + otherSize.y)  // Overlapping on the y (vertical space)
	{
		return true;
	}
	else return false;
}