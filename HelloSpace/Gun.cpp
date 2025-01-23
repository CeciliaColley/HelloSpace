#include "Gun.h"
#include "Bullet.h"

Gun::Gun()
{
	cooldownThreshold = 10;
	cooldownTimer = cooldownThreshold;
	shootCount = 0;
	canShoot = true;
}
Gun::~Gun()
{

}

// TODO: THESE FUNCTIONS ARENT BEING USED, ARE THEY NECESSARY
int Gun::GetCooldownTimer()
{
	return cooldownTimer;
}
int Gun::GetCooldownThreshold()
{
	return cooldownThreshold;
}
int Gun::GetShootCount()
{
	return shootCount;
}
bool Gun::CanShoot()
{
	return canShoot;
}
void Gun::IncreaseCooldownTimer(int increase)
{
	cooldownTimer += increase;
}
void Gun::SetCooldownThreshold(int threshold)
{
	cooldownThreshold = threshold;
	cooldownTimer = cooldownThreshold;
}
void Gun::SetCanShoot(bool canShoot)
{
	this->canShoot = canShoot;
}
//Functions being used
void Gun::GenerateBullet(vector2 shooterPosition, int offset, directions direction)
{
	int bulletSpawnX = shooterPosition.x + offset;
	int bulletSpawnY = shooterPosition.y - 1;
	vector2 bulletSpawnPoint = vector2(bulletSpawnX, bulletSpawnY);
	Bullet* bullet = new Bullet(bulletSpawnPoint, direction);
}
void Gun::Shoot(vector2 shooterPosition, int offset, directions direction)
{
	if (canShoot && cooldownTimer >= cooldownThreshold)
	{
		GenerateBullet(shooterPosition, offset, direction);
		shootCount++;
		cooldownTimer = 0;
	}
}
void Gun::Cooldown(int cooldownFactor)
{
	if (cooldownTimer < cooldownThreshold)
	{
		cooldownTimer += cooldownFactor;
	}
}