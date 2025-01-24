#include "GameObject.h"
#include "AwesomeLibrary.h"


using namespace std;

// NOTE: The cleanup system relies on the active and inactive game objects vectors being accurate. A game object must always exist in one of them.
vector<GameObject*> GameObject::activeGameObjects;
vector<GameObject*> GameObject::inactiveGameObjects;
/************************************************************** CONSTRUCTORS AND DECONSTRUCTORS ******************************************************/
GameObject::GameObject()
{
	position = vectorOne;
	size = vectorZero;
	isActive = true;
	activeGameObjects.push_back(this);
	isPooled = false;
}
GameObject::GameObject(vector2 position)
{
	size = vectorZero;
	try
	{
		SetPosition(position);
		SetActiveState(true);
	}
	catch (const invalid_argument& e)
	{
		SetActiveState(false);
		cerr << e.what() << endl;
	}
	isPooled = false;
}
GameObject::~GameObject()
{
	if (isActive)
	{
		/*auto it = find(activeGameObjects.begin(), activeGameObjects.end(), this);
		if (it != activeGameObjects.end())
		{
			activeGameObjects.erase(it);
		}*/
		FindAndErase(activeGameObjects, this);
	}
	else
	{
		/*auto it = find(inactiveGameObjects.begin(), inactiveGameObjects.end(), this);
		if (it != inactiveGameObjects.end())
		{
			inactiveGameObjects.erase(it);
		}*/
		FindAndErase(inactiveGameObjects, this);
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
vector<GameObject*> GameObject::GetActiveGameObjects()
{
	return activeGameObjects;
}
vector<GameObject*> GameObject::GetInactiveGameObjects()
{
	return inactiveGameObjects;
}
bool GameObject::IsActive()
{
	return isActive;
}
bool GameObject::IsPooled()
{
	return isPooled;
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
void GameObject::SetActiveState(bool activeState)
{
	// Only change status if it's a different status. This avoids multiple inclusions in the active / inactive game object vectors
	if (activeState == isActive) { return;	}
	else { isActive = activeState; }
	
	// If the active status indeed changed, switch it out of the respective tracking vectors
	// NOTE: The cleanup system relies on the active and inactive game objects vectors being accurate. A game object must always exist in one of them.
	if (isActive)
	{
		activeGameObjects.push_back(this);
		/*auto it = find(inactiveGameObjects.begin(), inactiveGameObjects.end(), this);
		if (it != inactiveGameObjects.end())
		{
			inactiveGameObjects.erase(it);
		}*/
		FindAndErase(inactiveGameObjects, this);
	}
	else
	{
		inactiveGameObjects.push_back(this);
		/*auto it = find(activeGameObjects.begin(), activeGameObjects.end(), this);
		if (it != activeGameObjects.end())
		{
			activeGameObjects.erase(it);
		}*/
		FindAndErase(activeGameObjects, this);
	}
}
void GameObject::SetIsPooled(bool isPooled)
{
	this->isPooled = isPooled;
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
void GameObject::FindAndErase(vector<GameObject*> &theVector, GameObject* gameObject)
{
	auto it = find(theVector.begin(), theVector.end(), gameObject);
	if (it != theVector.end())
	{
		theVector.erase(it);
	}
}