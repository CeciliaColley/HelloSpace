#include "GameObject.h"
#include "AwesomeLibrary.h"


using namespace std;
vector<GameObject*> GameObject::gameObjects;
/************************************************************** CONSTRUCTORS AND DECONSTRUCTORS ******************************************************/
GameObject::GameObject()
{
	position = vectorOne;
	size = vectorZero;
	isActive = true;
	isGarbage = false;
	gameObjects.push_back(this);
}
GameObject::GameObject(vector2 position)
{
	size = vectorZero;
	isGarbage = false;
	try
	{
		SetPosition(position);
		isActive = true;
	}
	catch (const invalid_argument& e)
	{
		isActive = false;
		cerr << e.what() << endl;
	}
	gameObjects.push_back(this);
}
GameObject::~GameObject()
{
	auto it = find(gameObjects.begin(), gameObjects.end(), this);
	if (it != gameObjects.end())
	{
		gameObjects.erase(it);
	}
}

/************************************************************************* GETTERS *********************************************************************/
vector2 GameObject::GetPosition()
{
	return position;
}
vector2 GameObject::GetSize()
{
	return size;
}
vector<GameObject*> GameObject::GetAllGameObjects()
{
	return gameObjects;
}
bool GameObject::IsActive()
{
	return isActive;
}
bool GameObject::IsGarbage()
{
	return isGarbage;
}
/********************************************************************** SETTERS ************************************************************************/
void GameObject::SetPosition(vector2 position)
{
	if (position.x <= 0 || position.y <= 0)
	{
		throw invalid_argument("The given position for the game object is out of bounds.");
	}
	this->position = position;
}
void GameObject::SetSize(vector2 size)
{
	this->size = size;
}
void GameObject::SetActiveState(bool isActive)
{
	this->isActive = isActive;
}
/****************************************************************** CLASS FUNCTIONS ********************************************************************/
//void GameObject::Hide()
//{
//	string line;
//	for (int i = 0; i < size.x; i++)
//	{
//		line += ' ';
//	}
//
//	for (int j = 0; j < size.y; j++)
//	{
//		int verticalPosition = position.y + j;
//		goToCoordinates(position.x, verticalPosition);
//		cout << line;
//	}
//}
bool GameObject::Collided(vector2 otherPosition, vector2 otherSize)
{
	if (position.x >= otherPosition.x && position.x <= otherPosition.x + otherSize.x      // Overlapping on the x (horizontal) space
		&& position.y >= otherPosition.y && position.y <= otherPosition.y + otherSize.y)  // Overlapping on the y (vertical space)
	{
		return true;
	}
	else return false;
}
void GameObject::FlagForCleanup()
{
	isGarbage = true;
}