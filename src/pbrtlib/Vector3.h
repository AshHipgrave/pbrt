#pragma once

#include <ostream>
#include <cassert>

template <typename T> class Vector3
{
public:
	Vector3()
	{
		x = y = z = 0;
	}

	Vector3(T xVal, T yVal, T zVal)
		: x(xVal), y(yVal), z(zVal)
	{
		assert(!HasNaNs());
	}

	//TODO: Implement types
	explicit Vector3(const Point3<T>& point);
	explicit Vector3(const Normal3<T>& normal);

#ifndef NDEBUG
	Vector3(const Vector3<T>& otherVector)
	{
		assert(!otherVector.HasNaNs());

		x = otherVector.x;
		y = otherVector.y;
		z = otherVector.z;
	}

	Vector3 > <T>& operator=(const Vector3<T>& otherVector)
	{
		assert(!otherVector.HasNaNs());

		x = otherVector.x;
		y = otherVector.y;
		z = otherVector.z;

		return *this;
	}
#endif

	friend std::ostream& operator<<(std::ostream& outputStream, const Vector3<T>& vector)
	{
		outputStream << "[" << vector.x << ", " << vector.y << ", " vector.z << "]";

		return outputStream;
	}

	Vector3<T> operator+(const Vector3<T>& otherVector) const
	{
		return Vector3(x + otherVector.x, y + otherVector.y, z + otherVector.z);
	}

	Vector3<T>& operator+=(const Vector3<T>& otherVector)
	{
		x += otherVector.x;
		y += otherVector.y;
		z += otherVector.z;

		return *this;
	}

	Vector3<T> operator-(const Vector3<T>& otherVector) const
	{
		return Vector3(x - otherVector.x, y - otherVector.y, z - otherVector.z);
	}

	Vector3<T>& operator-=(const Vector3<T>& otherVector)
	{
		x -= otherVector.x;
		y -= otherVector.y;
		z -= otherVector.z;

		return *this;
	}

	bool operator==(const Vector3<T>& otherVector) const
	{
		return x == otherVector.x && y == otherVector.y && z == otherVector.z;
	}

	bool operator!=(const Vector3<T>& otherVector) const
	{
		return x != otherVector.x || y != otherVector.y || z != otherVector.z;
	}

	Vector3<T> operator*(T value) const
	{
		return Vector3<T>(x * value, y * value, z * value);
	}

	Vector3<T>& operator*=(T value)
	{
		x *= value;
		y *= value;
		z *= value;

		return *this;
	}

	Vector3<T> operator/(T value) const
	{
		assert(value != 0);

		float inv = (float)1 / value;

		return Vector3<T>(x * inv, y * inv, z * inv);
	}

	Vector3<T>& operator/=(T value)
	{
		assert(value != 0);

		float inv = (float)1 / value;

		x *= inv;
		y *= inv;
		z *= inv;

		return *this;
	}

	Vector3<T>& operator-() const
	{
		return Vector3<T>(-x, -y, -z);
	}

	T operator[](int index) const
	{
		assert(index >= 0 && index <= 2);

		if (index == 0) return x;
		if (index == 1) return y;

		return z;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index <= 2);

		if (index == 0) return x;
		if (index == 1) return y;

		return z;
	}

	float LengthSquared() const
	{
		return x * x + y * y + z * z;
	}

	float Length() const 
	{
		return std::sqrt(LengthSquared());
	}

	bool HasNaNs()
	{
		return std::isnan(x) || std::isnan(y) || std::isnan(z);
	}

public:
	T x;
	T y;
	T z;
};
