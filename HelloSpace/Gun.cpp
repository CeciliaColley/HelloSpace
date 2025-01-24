#include "Gun.h"

Gun::Gun()
{
	cooldownThreshold = 10;
	cooldownTimer = cooldownThreshold;
	shootCount = 0;
	canShoot = true;
	bulletPoolSize = 10;
	for (int i = 0; i < 10; i++)
	{
		Bullet* bullet = new Bullet();
		bullet->SetActiveState(false);
		bulletPool.push_back(bullet);
	}
}
Gun::~Gun()
{
	for (Bullet* bullet : bulletPool)
	{
		delete bullet;
	}
}

// TODO: THESE FUNCTIONS ARENT BEING USED, ARE THEY NECESSARY
//int Gun::GetCooldownTimer()
//{
//	return cooldownTimer;
//}
//int Gun::GetCooldownThreshold()
//{
//	return cooldownThreshold;
//}
//int Gun::GetShootCount()
//{
//	return shootCount;
//}
//bool Gun::CanShoot()
//{
//	return canShoot;
//}
//void Gun::IncreaseCooldownTimer(int increase)
//{
//	cooldownTimer += increase;
//}
//void Gun::SetCooldownThreshold(int threshold)
//{
//	cooldownThreshold = threshold;
//	cooldownTimer = cooldownThreshold;
//}
//void Gun::SetCanShoot(bool canShoot)
//{
//	this->canShoot = canShoot;
//}
//Functions being used
void Gun::GenerateBullet(vector2 muzzlePosition, directions direction)
{
	Bullet* bullet = new Bullet(muzzlePosition, direction);
}
void Gun::Shoot(vector2 shooterPosition, int offset, directions direction)
{
	if (!canShoot || cooldownTimer < cooldownThreshold) { return; }

	vector2 muzzlePosition = GetMuzzlePosition(shooterPosition, offset);
	if (!UseBulletPool(muzzlePosition)) // Reuse bullet if possible
	{
		GenerateBullet(muzzlePosition, direction); // Otherwise, generate a new one
	}

	shootCount++;
	cooldownTimer = 0;
}
bool Gun::UseBulletPool(vector2 muzzlePosition)
{
	for (Bullet* bullet : bulletPool)
	{
		if (!(bullet->IsActive()))
		{
			bullet->SetPosition(muzzlePosition);
			bullet->SetActiveState(true);
			return true;
		}
	}
	return false;
}
void Gun::Cooldown(int cooldownFactor)
{
	if (cooldownTimer < cooldownThreshold)
	{
		cooldownTimer += cooldownFactor;
	}
}
vector2 Gun::GetMuzzlePosition(vector2 shooterPosition, int offset)
{
	int muzzlePositionX = shooterPosition.x + offset;
	int muzzlePositionY = shooterPosition.y - 1;
	vector2 muzzlePosition = vector2(muzzlePositionX, muzzlePositionY);
	return muzzlePosition;
}