#include "Bullet.h"
#include "AwesomeLibrary.h"

Bullet::Bullet() : GameObject()
{
	SetSize(vectorOne);
	predefinedMovement.DefineMovement(UP);
}
Bullet::Bullet(vector2 position, directions movementDirection) : GameObject(position)
{
	SetSize(vectorOne);
	predefinedMovement.DefineMovement(movementDirection);
}
Bullet::~Bullet()
{
	Hide();
}
void Bullet::Draw()
{
	int x = GetPosition().x;
	int y = GetPosition().y;
	goToCoordinates(x, y);
	wcout << L"⌂";
}
void Bullet::Move()
{
	vector2 newPosition = GetPosition() + predefinedMovement.GetMovementVector();
	try
	{
		SetPosition(newPosition);
	}
	catch (const invalid_argument& e) {}
}