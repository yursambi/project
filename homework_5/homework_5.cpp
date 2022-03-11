#include <iostream> 
//#include <cmath> 

void PrintHello()
{
    std::cout << "              Здравствуйте, Дмитрий!" << std::endl;
}

bool PrintArray(double arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "  " << arr[i] << "\t";
    }

    return true;
}

bool СhangeArray(int ten[], int size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << "  " << ten[i] << "  ";
    std::cout << "         - задаём массив ten из нулей и едениц" << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        ten[i] = ten[i] == 0 ? 1 : 0;
        std::cout << "  " << ten[i] << "  ";
    }
    return true;
}

bool EightArray(int* eight, int size)
{
    std::cout << "  _    _    _     _     _     _     _     _";
    std::cout << "                - задаём пустой массив eight " << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        if (i == 0)
            eight[i] = 1;
        else
            eight[i] = eight[i - 1] + 3;
        std::cout << "  " << eight[i] << "  ";
    }
    return true;
}

bool ShiftArray(int* shift, int size, int & n, int & savedElement)
{
    for (size_t i = 0; i < size; i++)
        std::cout << "  " << shift[i] << "  ";
    std::cout << "     - задаём целочисленный массив shift" << std::endl;
    std::cout << std::endl;
    std::cout << " Сдвигаем элементы массива shift на n позиций" << std::endl;
    std::cout << " (влево: +n или вправо: -n): введите любое целое число       n = ";
    std::cin >> n;
    std::cout << std::endl;
    std::cout << std::endl;

    if (n > 0)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < 8; i++)
            {
                if (i == 0)
                {
                    savedElement = shift[i];
                }
                shift[i] = shift[i + 1];
            }
            shift[8] = savedElement;
        }
    }
    else if (n <= 0 && n >= -9)
    {
      n = 9 + n;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < 8; i++)
            {
                if (i == 0)
                {
                    savedElement = shift[i];
                }
                shift[i] = shift[i + 1];
            }
            shift[8] = savedElement;
        }
    }
    else if (n < -9)
    {
      n = 9 + (n % 9);
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < 8; i++)
            {
                if (i == 0)
                {
                    savedElement = shift[i];
                }
                shift[i] = shift[i + 1];
            }
            shift[8] = savedElement;
        }
    }
    for (size_t i = 0; i < size; i++)
        std::cout << "  " << shift[i] << "  ";

    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << std::endl;
    PrintHello();
    std::cout << std::endl;

    const int mysize = 7;
    double myarr[] = { 5.16, 8.13, 2.41, 10.87, 7.42, 2.67, 3.81 };
    if (PrintArray(myarr, mysize))
    {
        std::cout << "   - массив double чисел успешно напечатан" << std::endl;
    }
    std::cout << std::endl;

    const int tensize = 10;
    int myten[] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
    if (СhangeArray(myten, tensize))
    {
        std::cout << "         - массив ten успешно изменён" << std::endl;
    }
    std::cout << std::endl;
    
    const int eightsize = 8;
    int myeight[eightsize];
    if (EightArray(myeight, eightsize))
    {
        std::cout << "              - массив eight успешно заполнен" << std::endl;
    }
    std::cout << std::endl;

    const int shiftsize = 9;
    int myshift[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 }, n, savedElement;
    if (ShiftArray(myshift, shiftsize, n, savedElement))
    {
        std::cout << "     - массив shift успешно изменён" << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}



