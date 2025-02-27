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
����:
������� ������� ���������� ���������� C++, ������� ��������� ������ ��������������
�������� (����, �����������, �������������), ����������� �� ������������ ������.
���������� ������ ��������������� ��������� �����������:
�	� ������ ������ ������ ���� ���������� ����� ������� �������
�	������ ���� ����������� ���������� ������� �������������� ����� �� �������
�	����������� ��������� (���������� Gtest) � ������� ��������� �������,
	���������������� ������ ���������� ��� ��������� ��������� �������� ������
*/



int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "russian");

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

	autotests::RunTests();
	return 0;
}