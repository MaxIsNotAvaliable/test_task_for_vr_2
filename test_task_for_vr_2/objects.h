#pragma once

#ifndef OBJECTS_H
#define OBJECTS_H

#include <cmath>
#include <string>
#include <format>
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

class Shere : public IObject
{
private:
	float radius;

public:
	Shere(float radius) : radius(radius) {}

	const float GetArea() const override
	{
		return pi * radius * radius;
	}

	const std::string GetName() const override
	{
		return std::format("Sphere r{}", radius);
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
		return std::format("Triangle {}x{}x{}", lenA, lenB, lenC);
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
		return std::format("Rectangle {}x{}", lenA, lenB);
	}
};

#endif // OBJECTS_H
