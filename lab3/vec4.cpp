#include "vec4.h"
#include <iostream>

namespace egc{
	vec4& egc::vec4::operator=(const vec4& srcVector)
	{
		x = srcVector.x;
		y = srcVector.y;
		z = srcVector.z;
		w = srcVector.w;
		return *this;
	}

	vec4 egc::vec4::operator+(const vec4& srcVector) const
	{
		return vec4(srcVector.x + x, srcVector.y + y, srcVector.z + z, srcVector.w + w);
	}

	vec4& egc::vec4::operator+=(const vec4& srcVector)
	{
		x += srcVector.x;
		y += srcVector.y;
		z += srcVector.z;
		w += srcVector.w;
		return *this;
	}

	vec4 egc::vec4::operator*(float scalarValue) const
	{
		return vec4(x * scalarValue, y * scalarValue, z * scalarValue, w * scalarValue);
	}

	vec4 egc::vec4::operator-(const vec4& srcVector) const
	{
		return vec4(x - srcVector.x, y - srcVector.y, z - srcVector.z, w - srcVector.w);
	}

	vec4& egc::vec4::operator-=(const vec4& srcVector)
	{
		x -= srcVector.x;
		y -= srcVector.y;
		z -= srcVector.z;
		w -= srcVector.w;
		return *this;
	}

	vec4 egc::vec4::operator-() const
	{
		return vec4(-x, -y, -z, -w);
	}

	float egc::vec4::length() const
	{
		return sqrt(x * x + y * y + z * z + w * w);
	}

	vec4& egc::vec4::normalize()
	{
		float length = this->length();
		x /= length;
		y /= length;
		z /= length;
		w /= length;
		return *this;
	}
}