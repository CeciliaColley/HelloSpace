#include "GarbageCollector.h"
#include "GameObject.h"

GarbageCollector::GarbageCollector() = default;
GarbageCollector::~GarbageCollector() = default;
void GarbageCollector::CollectInactiveGameObjects()
{
	for (GameObject* gameObject : GameObject::GetAllGameObjects())
	{
		if (!(gameObject->IsActive()) && gameObject->IsGarbage())
		{
			delete gameObject;
		}
	}
}