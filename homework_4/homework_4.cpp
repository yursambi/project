#include <iostream> 
//#include <cmath> 


int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "              Здравствуйте, Дмитрий!" << std::endl;
    std::cout << std::endl;

    std::cout << "              Проверяем, что сумма двух чисел лежит в пределах от 10 до 20 включительно." << std::endl;
    std::cout << std::endl;
    std::cout << "Введите любое число:                                      ";
    double a;
    std::cin >> a;

    std::cout << "Введите следующее число:                                  ";
    double b;
    std::cin >> b;

    if ( a + b  >= 10 )
    {
        if (a + b <= 20)
           std::cout << "                                                       true";
        else
           std::cout << "                                                      false";
    }
    else
    {
        std::cout << "                                                     false";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Выводим на экран строку “true”, если два цисла либо оба равны десяти сами по себе, либо их сумма равна десяти." << std::endl;
    std::cout << std::endl;
    std::cout << "Введите любое целое число:                                 ";
    int c;
    std::cin >> c;
    std::cout << "Введите следующее целое число:                             ";
    int d;
    std::cin >> d;

    if (c + d == 10)
    {
        std::cout << "                                                         true";
    }
    else if (c == 10)
    {
            if (d == 10)
              std::cout << "                                                       true";
            else
                std::cout << "                                             false";
    }
    else
    {
        std::cout << "                                                         false";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "                       Выводм на экран список всех нечетных чисел от 1 до 50." << std::endl;
    std::cout << std::endl;
    for (int i = 1; i < 50; i = i + 2)
    {
        std::cout << i << "  " ;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "                        Проверяем, является ли некоторое число - простым." << std::endl;
    std::cout << std::endl;
    std::cout << "Введите любое натуральное (целое положительное) число:       ";
    unsigned long long f;
    std::cin >> f;
    std::cout << std::endl;

    if (f == 2 || f == 3)
    {
        std::cout << "                                         Это число простое";
    }
    else if (f == 1)
    {
        std::cout << "                                      Это число не простое";
    }
    else if ((f * f) % 24 == 1)
    {
        std::cout << "                                         Это число простое";
    }
    else if ((f * f) % 24 != 1)
    { 
        std::cout << "                                      Это число не простое";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "                    Определяем  является ли введённый пользователем год високосным." << std::endl;
    std::cout << std::endl;
    std::cout << "Введите любое целое число от 1 до 3000:                      ";
    int g;
    std::cin >> g;
    std::cout << std::endl;
    
        if ((g % 4 == 0 && g % 100 != 0) || (g % 400 == 0))
        {
        std::cout << "                                           Это  високосный год";
        }
        else 
        {
           std::cout << "                                        Это не високосный год";
        } 
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "                 Заполняем диагональные элементы квадратной матрицы единицами." << std::endl;

        std::cout << std::endl;
        std::cout << std::endl;

        int Box[7][7] = { 0 };

        for (int row = 0; row < 7; ++row)
            for (int col = 0; col < 7; ++col)

            {
                Box[row][col] = (row + col == 6) ? 1 : ((row - col == 0) ? 1 : 0);
            }

        for (int row = 0; row < 7; ++row)
        {
            for (int col = 0; col < 7; ++col)

                std::cout << "     " << Box[row][col] << "\t";

            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
        }
        
        std::cout << std::endl;
        return 0;
} 