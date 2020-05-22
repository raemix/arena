#include "Vec2.h"

Vec2::Vec2(float x_in, float y_in)
	:
	x( x_in),
	y(y_in)
{
}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2& Vec2::operator+=(const Vec2 rhs)
{
	return *this = *this + rhs;
}

Vec2 Vec2::operator*(float rhs) const
{
	return Vec2( x * rhs, y * rhs);
}

Vec2& Vec2::operator*=(Vec2 rhs)
{
	return *this = *this *= rhs;
}

Vec2 Vec2::operator-(const Vec2& rhs) const
{
	return Vec2( x - rhs.x, y - rhs.y);
}

Vec2& Vec2::operator-=(const Vec2& rhs)
{
	return *this = *this - rhs;
}

float Vec2::getLength()
{
	float length = std::sqrt(getLengthSq());
	return length;
}

float Vec2::getLengthSq()
{
	return ((x * x) + (y * y));
}

Vec2 Vec2::getVec()
{
	float a = x;
	float b = y;
	return Vec2(a, b);
}
