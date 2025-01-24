#include <iostream>
#include "Spaceship.h"
#include "Bullet.h"
#include "AwesomeLibrary.h"
#include "vector2.h"

using namespace std;

void DrawAllActiveGameObjects()
{
	for (GameObject* gameObject : GameObject::GetActiveGameObjects())
	{
		gameObject->Draw();
	}
}

void MoveAllActiveGameObjects()
{
	for (GameObject* gameObject : GameObject::GetActiveGameObjects())
	{
		gameObject->Move();
	}
}

void DestroyInactiveGameObjects(bool includePool)
{
	for (GameObject* gameObject : GameObject::GetInactiveGameObjects())
	{
		if (includePool)
		{
			delete gameObject;
		}
		else
		{
			if (!(gameObject->IsPooled())) { delete gameObject; }
		}
	}
}

int main()
{
	locale::global(locale("en_US.UTF-8")); // I have a whole video on what this line is and why I wrote it. Feel free to share it with future students.

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
		DestroyInactiveGameObjects(false);
		
		frame++;
		Sleep(loopIncrease);
		spaceship.GetGun()->Cooldown(loopIncrease);
	}
}

