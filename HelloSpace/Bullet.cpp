#include "Bullet.h"
#include "AwesomeLibrary.h"

Bullet::Bullet() : GameObject()
{
	SetSize(vectorOne);
}
Bullet::Bullet(vector2 position) : GameObject(position)
{
	SetSize(vectorOne);
}
Bullet::~Bullet()
{
	Hide();
}
void Bullet::Draw()
{
	goToCoordinates(position.x, position.y);
	wcout << L"⌂";
}
void Bullet::Move()
{
	vector2 newPosition = GetPosition() + predefinedMovement.GetMovementVector();
	try
	{
		SetPosition(newPosition);
	}
	catch (const invalid_argument& e)
	{
		cerr << e.what << endl;
	}

	
}