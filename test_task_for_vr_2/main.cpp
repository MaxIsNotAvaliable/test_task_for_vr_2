#include <iostream>
#include <memory>
#include <cmath>
#include <vector>
#include <string>
#include <format>
#include <algorithm>

/*
Цель:
Создать простое консольное приложение C++, которое реализует классы геометрических
объектов (круг, треугольник, прямоугольник), наследуемых от абстрактного класса.
Приложение должно соответствовать следующим требованиям:
•	В каждом классе должен быть реализован метод расчета площади
•	Должна быть реализована сортировка массива геометрических фигур по площади
•	Реализованы автотесты (желательно Gtest) с разными тестовыми данными,
	демонстрирующими работу приложения при различных граничных условиях задачи
*/

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

int main(int argc, char* argv[])
{
	std::vector<std::unique_ptr<IObject>> objects;

	objects.emplace_back(std::make_unique<Rectangle>(10, 20));
	objects.emplace_back(std::make_unique<Shere>(5));
	objects.emplace_back(std::make_unique<Triangle>(3, 4, 5));

	for (const auto& obj : objects)
	{
		printf("%s area %.6f\n", obj->GetName().c_str(), obj->GetArea());
	}

	printf("--- SORT ---\n");
	std::sort(objects.begin(), objects.end(), [](const auto& a, const auto& b) { return *a < *b; });

	for (const auto& obj : objects)
	{
		printf("%s area %.6f\n", obj->GetName().c_str(), obj->GetArea());
	}

	return 0;
}