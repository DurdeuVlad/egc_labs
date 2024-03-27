#include <iostream>
#include "vec2.h"

namespace egc {

	vec2& egc::vec2::operator=(const vec2& srcVector)
	{
		x = srcVector.x;
		y = srcVector.y;
		return *this;
	}

	vec2 egc::vec2::operator+(const vec2& srcVector) const
	{
		return vec2(x+srcVector.x, srcVector.y+y);
	}

	vec2& egc::vec2::operator+=(const vec2& srcVector)
	{
		x += srcVector.x;
		y += srcVector.y;
		return *this;
	}

	vec2 egc::vec2::operator*(float scalarValue) const
	{

		return vec2(x*scalarValue, y*scalarValue);
	}

	vec2 egc::vec2::operator-(const vec2& srcVector) const
	{
		return vec2(x-srcVector.x, y-srcVector.y);
	}

	vec2& egc::vec2::operator-=(const vec2& srcVector)
	{
		x -= srcVector.x;
		y -= srcVector.y;
		return *this;
	}

	vec2 egc::vec2::operator-() const
	{
		return vec2(-x, -y);
	}

	float egc::vec2::length() const
	{
		return sqrt(x*x + y*y);
	}

	vec2& egc::vec2::normalize()
	{
		float length = this->length();
		x /= length;
		y /= length;
		return *this;
	}

	float dotProduct(const vec2& v1, const vec2& v2)
	{
		return 0;
	}
	
}