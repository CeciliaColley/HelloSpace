#include "Gun.h"

Gun::Gun()
{
	cooldownThreshold = 10;
	cooldownTimer = cooldownThreshold;
	shootCount = 0;
	canShoot = true;
	GenerateBulletPool(10);
}
Gun::~Gun()
{
	// //Bullets in the bullet pool are destroyed in the guns deconstructor
	for (auto it = bulletPool.begin(); it != bulletPool.end();)
	{
		delete* it; // Deletes the Bullet object the iterator points to
		it = bulletPool.erase(it); // Erases the pointer from the vector and updates the iterator
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
	bullet->FlagForCleanup();
}
void Gun::GenerateBulletPool(int poolSize)
{
	//Bullets in the bullet pool are destroyed in the guns deconstructor and don't need to be flagged for cleanup
	for (int i = 0; i < poolSize; i++)
	{
		Bullet* bullet = new Bullet();
		bullet->SetActiveState(false);
		bulletPool.push_back(bullet);
	}
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
void Gun::Cooldown(float cooldownFactor)
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