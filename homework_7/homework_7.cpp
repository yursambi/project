#include <iostream>
#include <algorithm>
#include "mylib.h"

#define RANGE(c, d) (c >= 0 && c < d)
#define ARR_DIMENSION 10
#define SWAP_INT(a, b) (std::swap(arr[j + 1], arr[j]))

void PrintHello()
{
    std::cout << "              Здравствуйте, Дмитрий!" << std::endl;
}
//
void bubbleSort(int* arr)  // Сортировка элементов массива методом пузырька
{
    for (int i = 0; i < (ARR_DIMENSION - 1); ++i)
    {
        for (int j = 0; j < (ARR_DIMENSION - 1); ++j)
        {
            if (arr[j + 1] < arr[j])
                SWAP_INT(a, b);
        }
    }
}
//
void PrintSort(int* arr)  //  Вывод элементов массива после сортировки на экран
{
    for (int i = 0; i < ARR_DIMENSION; i++)
        std::cout << arr[i] << "  ";
    std::cout << std::endl;
}
//
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    std::cout << std::endl;
    PrintHello();
    std::cout << std::endl;
    std::cout << " Выделяем память под одномерный массив типа float." << std::endl;
    std::cout << std::endl;
    std::cout << " Задайте размер вашего массива:     size = ";
    int size;
    std::cin >> size;
    std::cout << std::endl;
    float* ptrArr =0;
    ptrArr = new (std::nothrow) float[size];
    if (ptrArr != 0)
    {
        std::cout << " Инициализируем этот массив и выводим на экран" << std::endl;
        MyLib::InitArray(ptrArr, size);
        std::cout << std::endl;
        MyLib::PrintArray(ptrArr, size);
        std::cout << std::endl;
        std::cout << " Считаем количество положительных и отрицательных элементов" << std::endl;
        MyLib::TallyElem(ptrArr, size);

        delete[] ptrArr;
        ptrArr = 0;
    }
    std::cout << std::endl;
 //
    std::cout << " Проверяем, входит ли введённое пользователем число в заданный" << std::endl;
    std::cout << " диапазон (c >= 0 и c < d), ипользуя макрокоманду через директиву define" << std::endl;
    std::cout << std::endl;
    int c, d;
    std::cout << " Введите любое целое число:          c = ";
    std::cin >> c;
    std::cout << " Введите следующее целое число:      d = ";
    std::cin >> d;
    std::cout << std::endl;

    if (RANGE(c, d))
        std::cout << "                                     true" << std::endl;
    else
        std::cout << "                                     false" << std::endl;
    std::cout << std::endl;
//
    std::cout << " Задаём массив bubbleArr типа int через ввод с клавиатуры" << std::endl;
    std::cout << std::endl;
    int bubbleArr[ARR_DIMENSION]{};

    for (int i = 0; i < ARR_DIMENSION; i++) 
    {
        std::cout << "     bubbleArr[" << i << "]= ";
        std::cin >> bubbleArr[i];
    }
    std::cout << std::endl;
    std::cout << " Массив bubbleArr инициализирован:  ";

    for (int i = 0; i < ARR_DIMENSION; i++) 
        std::cout << bubbleArr[i] << "  ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << " Сортируем элементы массива" << std::endl;
    std::cout << " bubbleArr методом пузырька:        ";
    int* arr = bubbleArr;
    bubbleSort(arr);
    PrintSort(arr);

    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}

