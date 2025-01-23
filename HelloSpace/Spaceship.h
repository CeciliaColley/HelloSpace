#pragma once
#include "GameObject.h"
#include "ControlledMovement.h"
#include "Gun.h"

using namespace std;

class Spaceship : public GameObject
{
private:
	ControlledMovement controlledMovement;
	Gun* gun;
public:
	Spaceship();
	~Spaceship();

	Gun* GetGun();
	void SetGun(Gun* gun);
	void Shoot();

	void Draw() override;
	
	/// <summary>
	/// Updates the spaceship's position based on the 'movementVector' member variable of the ControlledMovement class.
	/// <para>- Does NOT visually move the spaceship; it only updates the position vector.</para>
	/// <para>- To visually reflect movement on screen, hide the spaceship, then redraw the spaceship at its new position.</para>
	/// </summary>
	void Move() override;
};
