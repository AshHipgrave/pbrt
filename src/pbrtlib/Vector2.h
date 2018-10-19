#pragma once

#include <ostream>
#include <cassert>

template <typename T> class Vector2
{
public:
	Vector2()
	{
		x = y = 0;
	}

	Vector2(T xVal, T yVal)
		: x(xVal), y(yVal)
	{
		assert(!HasNaNs());
	}

	explicit Vector2(const Point2<T>& point);
	explicit Vector2(const Point3<T>& point);

#ifndef NDEBUG
	Vector2(const Vector2<T>& otherVector)
	{
		assert(!otherVector.HasNaNs());

		x = otherVector.x;
		y = otherVector.y;
	}

	Vector2<T>& operator=(const Vector2<T>& otherVector)
	{
		assert(!otherVector.HasNaNs());

		x = otherVector.x;
		y = otherVector.y;
	}
#endif

	friend std::ostream& operator<<(std::ostream& outputStream, const Vector2<T>& vector)
	{
		outputStream << "[" << vector.x << ", " << vector.y << "]";

		return outputStream;
	}

	Vector2<T> operator+(const Vector2<T>& otherVector) const
	{
		assert(!otherVector.HasNaNs());

		return Vector2(x + otherVector.x, y + otherVector.x);
	}

	Vector2<T>& operator+=(const Vector2<T>& otherVector)
	{
		assert(!otherVector.HasNaNs());

		x += otherVector.x;
		y += otherVector.x;

		return *this;
	}

	Vector2<T> operator-(const Vector2<T>& otherVector) const
	{
		assert(!otherVector.HasNaNs());

		return Vector2(x - otherVector.x, y - otherVector.y);
	}

	Vector2<T>& operator-=(const Vector2<T>& otherVector)
	{
		assert(!otherVector.HasNaNs());

		x -= otherVector.x;
		y -= otherVector.y;

		return *this;
	}

	bool operator==(const Vector2<T>& otherVector) const
	{
		return x == otherVector.x && y == otherVector.y;
	}

	bool operator!=(const Vector<T>& value) const
	{
		return x != value.x || y != value.y;
	}

	Vector2<T> operator*(T value) const
	{
		return Vector2<T>(x * value, y * value);
	}

	Vector2<T>& operator*=(T value)
	{
		assert(!std::isnan(value));

		x *= value;
		y *= value;

		return *this;
	}

	Vector2<T> operator/(T value) const
	{
		assert(value != 0);

		float inv = (float)1 / value;

		return Vector2<T>(x * inv, y * inv);
	}

	Vector2<T>& operator/=(T value)
	{
		assert(value != 0);

		float inv = (float)1 / value;

		x *= inv;
		y *= inv;

		return *this;
	}

	Vector2<T> operator-() const
	{
		return Vector2<T>(-x, -y);
	}

	T operator[](int index)
	{
		assert(index >= 0 && index <= 1);

		if (index == 0) return x;

		return y;
	}

	float LengthSquared() const
	{
		return x * x + y * y;
	}

	float Length() const
	{
		return std::sqrt(LengthSquared());
	}

	bool HasNaNs() const
	{
		return std::isnan(x) || std::isnan(y);
	}

public:

	T x;
	T y;
};