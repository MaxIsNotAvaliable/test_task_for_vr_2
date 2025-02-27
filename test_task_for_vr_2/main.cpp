#include "objects.h"
#include "autotests.h"

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

#pragma region OBJECT_UTILS

void SortObjects(std::vector<std::unique_ptr<IObject>>& objects)
{
	std::sort(objects.begin(), objects.end(), [](const auto& a, const auto& b) { return *a < *b; });
}

void PrintObjects(const std::vector<std::unique_ptr<IObject>>& objects)
{
	for (size_t i = 0; i < objects.size(); i++)
	{
		printf("[%lld]\t%s\t\tarea %.3f\n", i, objects[i]->GetName().c_str(), objects[i]->GetArea());
	}
}

#pragma endregion // OBJECT_UTILS

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "russian");

	std::vector<std::unique_ptr<IObject>> objects;

	objects.emplace_back(std::make_unique<Sphere>(5));
	objects.emplace_back(std::make_unique<Rectangle>(10, 20));
	objects.emplace_back(std::make_unique<Triangle>(3, 4, 5));

	PrintObjects(objects);

	printf("--- SORT ---\n");
	SortObjects(objects);

	PrintObjects(objects);

	autotests::RunTests();
	return 0;
}