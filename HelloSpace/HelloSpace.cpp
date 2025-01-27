#include <iostream>
#include "Spaceship.h"
#include "Bullet.h"
#include "AwesomeLibrary.h"
#include "vector2.h"
#include <crtdbg.h>
#include "GarbageCollector.h"

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

void MoveAllActiveGameObjects()
{
	for (GameObject* gameObject : GameObject::GetAllGameObjects())
	{
		if (gameObject->IsActive())
		{
			gameObject->Move();
		}
	}
}

int main()
{
	locale::global(locale("en_US.UTF-8")); // I have a whole video on what this line is and why I wrote it. Feel free to share it with future students.

	GarbageCollector garbageCollector;
	Spaceship spaceship;
	spaceship.SetPosition(vector2(10, 10));

	int frames = 1000000000;
	int frame = 0;
	int loopIncrease = 1;

	while (frame < frames)
	{
		MoveAllActiveGameObjects();

		if (GetKeyState(0x20) < 0)
		{
			spaceship.Shoot();
		}

		system("cls");
		DrawAllActiveGameObjects();
		
		frame++;
		Sleep(loopIncrease);
		spaceship.GetGun()->Cooldown(loopIncrease);
		
		garbageCollector.CollectInactiveGameObjects();

		if (GetKeyState('X') < 0)
		{

			break;
		}
	}
}

