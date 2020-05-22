#pragma once

#include <cmath>


class Vec2
{

public:


	float x;
	float y;

private:



public:
	Vec2() = default;
	Vec2(float x_in, float y_in);
	Vec2 operator+(const Vec2& rhs) const;
	Vec2& operator+=(const Vec2 rhs);
	Vec2 operator*(float rhs) const;
	Vec2& operator*=(Vec2 rhs);
	Vec2 operator-(const Vec2& rhs) const;
	Vec2& operator-=(const Vec2& rhs);
	float getLength();
	float getLengthSq();
	Vec2 getVec();

};
