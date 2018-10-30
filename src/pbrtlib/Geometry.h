#pragma once

#include <ostream>
#include <cassert>

template <typename T>
inline bool isNaN(const T value) 
{
	return std::isnan(value);
}

template <typename T>
class Vector2 
{
public:

	Vector2() 
	{ 
		x = 0;
		y = 0;
	}

	Vector2(T xValue, T yValue) 
		: x(xValue), y(yValue)
	{ 
		assert(!HasNaNs()); 
	}
	
	bool HasNaNs() const 
	{ 
		return isNaN(x) || isNaN(y); 
	}
	
	explicit Vector2(const Point2<T>& point);
	explicit Vector2(const Point3<T>& point);

#ifndef NDEBUG

	Vector2(const Vector2<T>& vector) 
	{
		assert(!vector.HasNaNs());

		x = vector.x;
		y = vector.y;
	}

	Vector2<T>& operator=(const Vector2<T>& vector)
	{
		assert(!vector.HasNaNs());
		
		x = vector.x;
		y = vector.y;
		
		return *this;
	}

#endif

	Vector2<T> operator+(const Vector2<T>& vector) const
	{
		assert(!vector.HasNaNs());

		return Vector2(x + vector.x, y + vector.y);
	}

	Vector2<T>& operator+=(const Vector2<T>& vector)
	{
		assert(!v.HasNaNs());

		x += vector.x;
		y += vector.y;
		
		return *this;
	}

	Vector2<T> operator-(const Vector2<T>& vector) const
	{
		assert(!vector.HasNaNs());
		
		return Vector2(x - vector.x, y - vector.y);
	}

	Vector2<T>& operator-=(const Vector2<T>& vector)
	{
		assert(!vector.HasNaNs());

		x -= vector.x;
		y -= vector.y;
		
		return *this;
	}

	bool operator==(const Vector2<T>& vector) const
	{ 
		return x == vector.x && y == vector.y;
	}
	
	bool operator!=(const Vector2<T>& vector) const
	{ 
		return x != vector.x || y != vector.y;
	}

	template <typename U>
	Vector2<T> operator*(U value) const
	{
		return Vector2<T>(x * value, y * value);
	}

	template <typename U>
	Vector2<T> &operator*=(U value)
	{
		assert(!isNaN(value));

		x *= value;
		y *= value;
		
		return *this;
	}

	template <typename U>
	Vector2<T> operator/(U value) const
	{
		assert(value != 0);
		
		float inv = (float)1 / value;
		
		return Vector2<T>(x * inv, y * inv);
	}

	template <typename U>
	Vector2<T> &operator/=(U value)
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
	
	T operator[](int index) const 
	{
		assert(index >= 0 && index <= 1);

		if (index == 0) return x;
		
		return y;
	}

	T& operator[](int index)
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

public:
	T x;
	T y;
};

//////
////// Vector3
//////

template <typename T>
class Vector3 
{
public:

	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3(T xValue, T yValue, T zValue)
		: x(xValue), y(yValue), z(zValue)
	{
		assert(!HasNaNs());
	}

	bool HasNaNs() const 
	{ 
		return isNaN(x) || isNaN(y) || isNaN(z);
	}

	explicit Vector3(const Point3<T>& point);
	explicit Vector3(const Normal3<T>& normal);

#ifndef NDEBUG

	Vector3(const Vector3<T>& vector) 
	{
		assert(!vector.HasNaNs());

		x = vector.x;
		y = vector.y;
		z = vector.z;
	}

	Vector3<T>& operator=(const Vector3<T>& vector)
	{
		assert(!vector.HasNaNs());

		x = vector.x;
		y = vector.y;
		z = vector.z;

		return *this;
	}

#endif

	Vector3<T> operator+(const Vector3<T>& vector) const
	{
		assert(!vector.HasNaNs());

		return Vector3(x + vector.x, y + vector.y, z + vector.z);
	}

	Vector3<T>& operator+=(const Vector3<T>& vector) 
	{
		assert(!vector.HasNaNs());

		x += vector.x;
		y += vector.y;
		z += vector.z;

		return *this;
	}

	Vector3<T> operator-(const Vector3<T>& vector) const
	{
		assert(!vector.HasNaNs());

		return Vector3(x - vector.x, y - vector.y, z - vector.z);
	}

	Vector3<T>& operator-=(const Vector3<T>& vector)
	{
		Assert(!vector.HasNaNs());

		x -= vector.x;
		y -= vector.y;
		z -= vector.z;

		return *this;
	}

	bool operator==(const Vector3<T>& vector) const 
	{
		return x == vector.x && y == vector.y && z == vector.z;
	}

	bool operator!=(const Vector3<T>& vector) const
	{
		return x != vector.x || y != vector.y || z != vector.z;
	}

	template <typename U>
	Vector3<T> operator*(U value) const 
	{
		return Vector3<T>(x * value, y * value, z * value);
	}

	template <typename U>
	Vector3<T>& operator*=(U value)
	{
		assert(!isNaN(value));

		x *= value;
		y *= value;
		z *= value;

		return *this;
	}

	template <typename U>
	Vector3<T> operator/(U value) const
	{
		assert(value != 0);

		float inv = (float)1 / value;

		return Vector3<T>(x * inv, y * inv, z * inv);
	}

	template <typename U>
	Vector3<T>& operator/=(U value)
	{
		assert(value != 0);
		
		float inv = (float)1 / value;

		x *= inv;
		y *= inv;
		z *= inv;

		return *this;
	}

	Vector3<T> operator-() const 
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

public:
	T x;
	T y;
	T z;
};



template <typename T>
inline std::ostream &operator<<(std::ostream& outputStream, const Vector2<T>& vector)
{
	outputStream << "[ " << vector.x << ", " << vector.y << "]";

	return outputStream;
}

template <typename T>
inline std::ostream &operator<<(std::ostream& outputStream, const Vector3<T>& vector)
{
	outputStream << "[ " << vector.x << ", " << vector.y << ", " << vector.z << "]";

	return outputStream;
}

/* TODO
template <>
inline std::ostream& operator<<(std::ostream& outputStream, const Vector2<float>& vector)
{
	outputStream << StringPrintf("[ %f, %f ]", vector.x, vector.y);

	return outputStream;
}

template <>
inline std::ostream& operator<<(std::ostream& outputStream, const Vector3<float>& vector)
{
	outputStream << StringPrintf("[ %f, %f, %f ]", vector.x, vector.y, vector.z);

	return outputStream;
}
*/