#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>

namespace MyLib
{
    bool InitArray(float* ptrArr, int size)  //  Инициализация массива псевдослучайными числами
    {
        //float base = -1.1f;
        float min = -10.251f;
        float max = 10.384f;
        srand(static_cast<unsigned int>(time(0)));

        for (size_t i = 0; i < size; i++)
            //ptrArr[i] = float(pow(base, i));
            ptrArr[i] = (float)rand() / RAND_MAX * (max - min) + min;

        return true;
    }


    void PrintArray(float* ptrArr, int size)  //  Вывод элементов массива на экран
    {
        std::cout << std::setprecision(7);

        for (int i = 0; i < size; i++)
            std::cout << " " << ptrArr[i] << " ";
        std::cout << std::endl;     
    }


    void TallyElem(float* ptrArr, int size)  //  Подсчёт количества положительных и отрицательных элементов
    {
        int a = 0, b = 0;
        for (int i = 0; i < size; i++)
        {
            if (ptrArr[i] > 0)
                a = a + 1;
            else
                b = b + 1;
        }
        std::cout << std::endl;
        std::cout << " Положительных элементов:   " << a << std::endl;
        std::cout << " Отрицательных элементов:   " << b << std::endl;
    }
}