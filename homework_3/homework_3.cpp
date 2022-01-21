
#include <iostream>

extern int a, b, c, d, f, g;

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Здравствуйте, Дмитрий!" << std::endl;
    std::cout << std::endl;

    std::cout << "Вычисляем выражение a * (b + c /d) и выводим результат с плавающей точкой." << std::endl;
    std::cout << std::endl;

    std::cout << "Введите любое целое число:                            a = ";
    std::cin >> a;
    std::cout << "Введите ненулевое целое число:                        b = ";
    std::cin >> b;
    /*std::cout << std::endl;

    std::cout << "                                                  a + b = " << a + b << std::endl;
    std::cout << "                                                  a - b = " << a - b << std::endl;
    std::cout << "                                                  a * b = " << a * b << std::endl;
    std::cout << "                                                  a / b = " << double (a) / b << std::endl;//Шесть знаков после запятой
    std::cout << std::endl;*/

    std::cout << "Введите любое целое число:                            c = ";
    std::cin >> c;
    std::cout << "Введите ненулевое целое число:                        d = ";
    std::cin >> d;
   

    //В обоих вариантах - три или два знака после запятой! Почему?
    float h = a * (b + float (c) / d);
    std::cout << "                                        a * (b + c / d) = " << h << std::endl;;

    //std::cout << "                                        a * (b + c / d) = " << double (a * (b + double(c) / d)) << std::endl;
    std::cout << std::endl;

    std::cout << "Вычисляем выражение f - 21 или (f - 21)*2 с использованием тернарного оператора." << std::endl;
    std::cout << "Если f меньше или равно 21, то: g = f - 21" << std::endl;
    std::cout << "Если f больше 21, то: g = (f - 21) * 2" << std::endl;
    std::cout << std::endl;
    std::cout << "Введите любое целое число:                            f = ";
    std::cin >> f;
    
    g = (f <= 21) ? (f - 21) : (2 * (f - 21));

    std::cout << "Итоговое значение                                     g = " << g << std::endl;
    std::cout << std::endl;


    std::cout << "Создаём трёхмерный целочисленный массив и указатель на значения внутри массива." << std::endl;

    int Cube[3][3][3] = {0}, *pCube;

    std::cout << "Значения элементов массива:" << std::endl;

    for (int row = 0; row < 3; ++row)
        for (int col = 0; col < 3; ++col)
            for (int vert = 0; vert < 3; ++vert)
                
    {  
             Cube[row][col][vert] = row + col + vert;                                       
    }
    
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            for (int vert = 0; vert < 3; vert++)
    
    { 
            std::cout << "                                          Cube[" << row << "][" << col << "][" << vert << "] = " << Cube[row][col][vert] << std::endl;
    }
    std::cout << std::endl;

    pCube = &Cube[1][1][1];

    std::cout << "То есть, значение центральной ячейки куба:                " << *pCube << std::endl;
    
    std::cout << "Адрес центральной ячейки куба:                            " << pCube << std::endl;
    
    *pCube = 225;

    std::cout << "Изменённое с помощью указателя" << std::endl; 
    std::cout << "значение центральной ячейки куба:                         " << Cube[1][1][1] << std::endl;

    std::cout << std::endl;

    return 0;
}