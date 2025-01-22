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
	try
	{
		SetPosition(position += vectorUp);
	}
	catch (const invalid_argument& e)
	{
		
	}
}