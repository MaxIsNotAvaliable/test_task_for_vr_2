#pragma once

#ifndef OBJECTS_H
#define OBJECTS_H

#include <cmath>
#include <string>
#include <algorithm>

const float pi = acosf(0) * 2;

class IObject
{
private:

public:
	virtual const float GetArea() const = 0;
	virtual const std::string GetName() const = 0;

	const bool operator<(const IObject& other) const
	{
		return this->GetArea() < other.GetArea();
	}
	const bool operator>(const IObject& other) const
	{
		return this->GetArea() > other.GetArea();
	}
	const bool operator==(const IObject& other) const
	{
		return this->GetArea() == other.GetArea();
	}

	virtual ~IObject() = default;
};

class Sphere : public IObject
{
private:
	float radius;

public:
	Sphere(float radius) : radius(radius) {}

	const float GetArea() const override
	{
		return pi * radius * radius;
	}

	const std::string GetName() const override
	{
		char buf[0x100] = { '\0' };
		sprintf_s(buf, 0x100, "Sphere\t\tr%.2f\t", radius);
		return std::string(buf);
	}
};

class Triangle : public IObject
{
private:
	float lenA, lenB, lenC;

public:
	Triangle(float lenA, float lenB, float lenC) : lenA(lenA), lenB(lenB), lenC(lenC) {}

	const float GetPerimetr() const
	{
		return lenA + lenB + lenC;
	}

	const float GetArea() const override
	{
		float halfPer = GetPerimetr() / 2.f;
		return sqrtf(halfPer * (halfPer - lenA) * (halfPer - lenB) * (halfPer - lenC));
	}

	const std::string GetName() const override
	{
		char buf[0x100] = { '\0' };
		sprintf_s(buf, 0x100, "Triangle\t%.2fx%.2fx%.2f", lenA, lenB, lenC);
		return std::string(buf);
	}
};

class Rectangle : public IObject
{
private:
	float lenA, lenB;

public:

	Rectangle(float lenA, float lenB) : lenA(lenA), lenB(lenB) {}

	const float GetArea() const override
	{
		return lenA * lenB;
	}

	const std::string GetName() const override
	{
		char buf[0x100] = { '\0' };
		sprintf_s(buf, 0x100, "Rectangle\t%.2fx%.2f", lenA, lenB);
		return std::string(buf);
	}
};

#endif // OBJECTS_H
