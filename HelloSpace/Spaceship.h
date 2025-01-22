#pragma once
#include <string>
#include "GameObject.h"
#include "ControlledMovement.h"

using namespace std;

class Spaceship : public GameObject
{
private:
	ControlledMovement controlledMovement;
public:
	Spaceship();
	~Spaceship();

	void Draw() override;
	
	/// <summary>
	/// Updates the spaceship's position based on the 'movementVector' member variable of the ControlledMovement class.
	/// <para>- Does NOT visually move the spaceship; it only updates the position vector.</para>
	/// <para>- To visually reflect movement on screen:</para>
	/// <para>		1. Hide the spaceship.</para>
	/// <para>		2. Update its position by calling Move.</para>
	/// <para>		3. Redraw the spaceship at its new position.</para>
	/// </summary>
	void Move() override;
};
