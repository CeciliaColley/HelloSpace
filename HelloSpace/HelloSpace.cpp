#include <iostream>
#include "Spaceship.h"
#include "Bullet.h"
#include "AwesomeLibrary.h"
#include "vector2.h"

using namespace std;


int main()
{
	locale::global(locale("en_US.UTF-8")); // I have a whole video on what this line is and why I wrote it. Feel free to share it with future students.

	Spaceship spaceship;
	spaceship.SetPosition(vector2(10, 10));
	spaceship.Draw();

	Bullet bullet = Bullet(vector2(5, 20));

	int frames = 1000000000;
	int frame = 0;

	while (frame < frames)
	{
		spaceship.Move();
		bullet.Move();
		system("cls");
		spaceship.Draw();
		bullet.Draw();
		frame++;
		Sleep(1);
	}
}
