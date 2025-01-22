#pragma once

struct vector2
{
	int x = 0;
	int y = 0;

	vector2() = default;

	vector2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	vector2& operator+=(const vector2& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	vector2 operator + (const vector2& other)
	{
		return vector2(this->x + other.x, this->y + other.y);
	}
};

const vector2 vectorZero(0, 0);
const vector2 vectorOne(1, 1);
const vector2 vectorUp(0, -1);
const vector2 vectorDown(0, 1);
const vector2 vectorRight(1, 0);
const vector2 vectorLeft(-1, 0);