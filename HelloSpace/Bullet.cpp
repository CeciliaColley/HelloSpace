﻿#include "Bullet.h"
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
	//Hide();
}
void Bullet::Draw()
{
	int x = GetPosition().x;
	int y = GetPosition().y;
	goToCoordinates(x, y);
	wcout << L"⌂";
}
void Bullet::Move(float loopIncrease)
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