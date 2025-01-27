#pragma once
#include "queue"
#include "vector2.h"
#include "Directions.h"
#include "Bullet.h"

class Gun
{
private:
	int cooldownTimer;
	int cooldownThreshold;
	int shootCount;
	bool canShoot;
	vector<Bullet*> bulletPool;
public:
	Gun();
	~Gun();

	// TODO: Get rid of some of these if other classes shouldnt be able to modify them.
	//int GetCooldownTimer();
	//int GetCooldownThreshold();
	//int GetShootCount();
	//bool CanShoot();

	//void IncreaseCooldownTimer(int increase);
	//void SetCooldownThreshold(int threshold);
	//void SetCanShoot(bool canShoot);

	void GenerateBullet(vector2 muzzlePosition, directions direction);
	void GenerateBulletPool(int poolSize);
	void Shoot(vector2 shooterPosition, int offset, directions direction);
	bool UseBulletPool(vector2 muzzlePosition);
	void Cooldown(int cooldownFactor);
	vector2 GetMuzzlePosition(vector2 shooterPosition, int offset);
};