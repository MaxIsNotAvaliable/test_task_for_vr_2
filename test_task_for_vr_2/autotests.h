#pragma once

#ifndef AUTOTESTS_H
#define AUTOTESTS_H

#include "objects.h"

#include <iostream>
#include <vector>
#include <memory>

namespace autotests 
{
    bool IsSorted(const std::vector<std::unique_ptr<IObject>>& objects) 
    {
        for (size_t i = 1; i < objects.size(); ++i) 
        {
            if (*objects[i - 1] > *objects[i]) return false;
        }
        return true;
    }

    bool IsApprox(float a, float b)
    {
        return fabsf(a - b) < 0.001f;
    }

    void RunTests() 
    {
        bool failed = false;

        std::vector<std::pair<float, float>> sphereTestCases = 
        {
            {5, pi * 5 * 5},
            {1, pi * 1 * 1},
            {0, pi * 0 * 0} 
        };

        std::vector<std::tuple<float, float, float, float>> triangleTestCases = 
        {
            {3, 4, 5, 6},
            {5, 5, 8, 12}, 
            {1, 1, 1, sqrtf(3) / 4} 
        };

        std::vector<std::string> triangleTestNames = 
        {
            "Triangle: Прямоугольный треугольник",
            "Triangle: Произвольный треугольник",
            "Triangle: Равносторонний треугольник"
        };

        for (size_t i = 0; i < triangleTestCases.size(); ++i) 
        {
            const auto& [a, b, c, expectedArea] = triangleTestCases[i];
            Triangle triangle(a, b, c);
            if (!IsApprox(triangle.GetArea(), expectedArea)) 
            {
                failed = true;
                printf("Тест провален - \"%s\"! Ожидалось %.6f, получено %.6f\n", triangleTestNames[i].c_str(), expectedArea, triangle.GetArea());
            }
        }

        std::vector<std::tuple<float, float, float>> rectangleTestCases = 
        {
            {10, 20, 200},
            {5, 5, 25}, 
            {0, 10, 0}   
        };

        std::vector<std::string> rectangleTestNames = 
        {
            "Rectangle: Прямоугольник 10x20",
            "Rectangle: Квадрат 5x5",
            "Rectangle: Прямоугольник с нулевой стороной"
        };

        for (size_t i = 0; i < rectangleTestCases.size(); ++i) 
        {
            const auto& [a, b, expectedArea] = rectangleTestCases[i];
            Rectangle rectangle(a, b);
            if (!IsApprox(rectangle.GetArea(), expectedArea)) 
            {
                failed = true;
                printf("Тест провален - \"%s\"! Ожидалось %.6f, получено %.6f\n",
                    rectangleTestNames[i].c_str(), expectedArea, rectangle.GetArea());
            }
        }

        std::vector<std::unique_ptr<IObject>> objects;
        objects.emplace_back(std::make_unique<Rectangle>(10, 20));
        objects.emplace_back(std::make_unique<Sphere>(5));
        objects.emplace_back(std::make_unique<Triangle>(3, 4, 5));

        std::sort(objects.begin(), objects.end(), [](const auto& a, const auto& b) { return *a < *b; });

        if (!IsSorted(objects)) 
        {
            failed = true;
            printf("Тест провален - \"Сортировка объектов\"!\n");
        }

        if (!failed) 
        {
            printf("Тесты пройдены успешно!\n");
        }
    }

}

#endif // !AUTOTESTS_H
