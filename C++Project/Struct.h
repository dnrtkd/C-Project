#pragma once
#include <vector>
#include <string>

struct Vector3
{
	float x, y, z;

	Vector3() : x(0), y(0), z(0) { };

	Vector3(float _x, float _y)
		: x(_x), y(_y), z(0) { };

	Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) { };

	// 현재 벡터와 벡터 b의 거리를 반환 하는 함수
	float getDistance(const Vector3& V1)
	{
		return sqrt((x - V1.x)*(x - V1.x) + (y - V1.y) * (y - V1.y));
	}

	Vector3 getDIrection(const Vector3& V1)
	{
		float distance = getDistance(V1);
		return Vector3(x / distance, y / distance);
	}

	Vector3 operator-(const Vector3& _V1)
	{
		return Vector3(x - _V1.x, y - _V1.y, z - _V1.z);
	}

	Vector3 operator+(const Vector3& _V1)
	{
		return Vector3(x + _V1.x, y + _V1.y, z + _V1.z);
	}

	Vector3 operator+=(const Vector3& _V1)
	{
		return Vector3(x += _V1.x, y += _V1.y, z += _V1.z);
	}

	Vector3 operator/(float _Value)
	{
		return Vector3(x / _Value, y / _Value, z / _Value);
	}

	Vector3 operator*(float _Value)
	{
		return Vector3(x * _Value, y * _Value, z * _Value);
	}
};

struct Transform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
	Vector3 Direction;
};

struct Texture
{

	vector<string> texture;
	int color;

	void intPutTexture(const char* st)
	{
		texture.push_back(st);
	}

	 int getYsize()const { return texture.size(); }
	 int getXsize()const { return texture[0].size(); }

	 Texture() { color = 15; }
};















