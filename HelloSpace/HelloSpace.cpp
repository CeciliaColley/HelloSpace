#include <iostream>
#include "Spaceship.h"
#include "Bullet.h"
#include "AwesomeLibrary.h"
#include "vector2.h"
#include <crtdbg.h>
#include "GarbageCollector.h"
#include "Asteroid.h"

using namespace std;

void DrawAllActiveGameObjects()
{
	for (GameObject* gameObject : GameObject::GetAllGameObjects())
	{
		if (gameObject->IsActive())
		{
			gameObject->Draw();
		}
	}
}

void MoveAllActiveGameObjects(float loopIncrease)
{
	for (GameObject* gameObject : GameObject::GetAllGameObjects())
	{
		if (gameObject->IsActive())
		{
			gameObject->Move(loopIncrease);
		}
	}
}

int main()
{
	locale::global(locale("en_US.UTF-8")); // I have a whole video on what this line is and why I wrote it. Feel free to share it with future students.

	GarbageCollector garbageCollector;
	Spaceship spaceship;
	spaceship.SetPosition(vector2(10, 10));
	Asteroid asteroid;

	bool stillPlaying = true;
	float loopIncrease = 1;

	while (stillPlaying)
	{
		MoveAllActiveGameObjects(loopIncrease);

		if (GetKeyState(0x20) < 0)
		{
			spaceship.Shoot();
		}

		system("cls");
		DrawAllActiveGameObjects();
		
		Sleep(loopIncrease);
		spaceship.GetGun()->Cooldown(loopIncrease);
		
		garbageCollector.CollectInactiveGameObjects();

		if (GetKeyState(KEY_ESC) < 0)
		{
			stillPlaying = false;
		}
	}
}

