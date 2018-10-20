#pragma once

#include "Vector2.h";
#include "Vector3.h";

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;

typedef Vector3<int> Vector3i;
typedef Vector3<float> Vector3f;

template <typename T> 
inline Vector3<T> operator*(T value, const Vector3<T>& vector)
{
	return vector * value;
}

template <typename T> 
Vector3<T> Abs(const Vector3<T>& vector)
{
	return Vector3<T>(std::abs(vector.x), std::abs(vector.y), std::abs(vector.z));
}

template <typename T> 
inline T Dot(const Vector3<T>& vector, const Vector3<T> otherVector)
{
	return (vector.x * otherVector.x) + (vector.y * otherVector.y) + (vector.z * otherVector.z);
}

template <typename T> 
inline T AbsDot(const Vector3<T>& vector, const Vector3<T>& otherVector)
{
	return std::abs(Dot(vector, otherVector));
}

