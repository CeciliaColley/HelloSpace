#include "Asteroid.h"
#include "AwesomeLibrary.h"

using namespace std;

int Asteroid::speed;

Asteroid::Asteroid()
{
	vector2 size(3, 6);
	SetSize(size);
	predefinedMovement.DefineMovement(DOWN);
}
Asteroid::~Asteroid()
{

}
void Asteroid::Draw()
{
	int x = GetPosition().x;
	int y = GetPosition().y;
	goToCoordinates(x, y);
	wcout << L"  ▄▄";
	goToCoordinates(x, (y + 1));
	wcout << L"▄▀█▄█▄";
	goToCoordinates(x, (y + 2));
	wcout << L" ▀██▀";
}
void Asteroid::Move(float loopIncrease)
{
	if (!predefinedMovement.MovementDelayPerformed(loopIncrease)) { return; }
	vector2 newPosition = GetPosition() + predefinedMovement.GetMovementVector();
	if (!(newPosition.x <= 0 || newPosition.y <= 0))
	{
		SetPosition(newPosition);
	}
	else
	{
		SetActiveState(false);
	}
}    