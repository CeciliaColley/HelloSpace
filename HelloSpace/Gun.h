#pragma once
#include "vector2.h"
#include "Directions.h"

class Gun
{
private:
	int cooldownTimer;
	int cooldownThreshold;
	int shootCount;
	bool canShoot;
public:
	Gun();
	~Gun();

	// TODO: Get rid of some of these if other classes shouldnt be able to modify them.
	int GetCooldownTimer();
	int GetCooldownThreshold();
	int GetShootCount();
	bool CanShoot();

	void IncreaseCooldownTimer(int increase);
	void SetCooldownThreshold(int threshold);
	void SetCanShoot(bool canShoot);

	void GenerateBullet(vector2 shooterPosition, int offset, directions direction);
	void Shoot(vector2 shooterPosition, int offset, directions direction);
	void Cooldown(int cooldownFactor);
};