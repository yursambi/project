#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Здравствуйте, Дмитрий!" << std::endl;
    std::cout << std::endl;

    //инициализируем переменные (объявление и присваивание значения), в дан.сл. локальные

    short int a = 111;
    int b = 222'333'444;
    long long c = 5.25e12;
    char d = 63;
    bool x = true;
    bool g = false;
    float y = 2.75;
    double z = 0.9E-3;
    auto h = -3.278415;
    
    std::cout << "a - это небольшое целое число:         " << a << std::endl;
    std::cout << "b - это большо целое число:            " << b << std::endl;
    std::cout << "c - это очень большое целое число:     " << c << std::endl;
    std::cout << "d - это знак вопроса:                  " << d << std::endl;
    std::cout << "x - это истина:                        " << x << std::endl;
    std::cout << "g - это ложь:                          " << g << std::endl;
    std::cout << "y - это число одинарной точности:      " << y << std::endl;
    std::cout << "z - это число двойной точности:        " << z << std::endl;
    std::cout << "h - это тоже число двойной точности:   " << h << std::endl;
    std::cout << std::endl;

    //перечисление (enum) с возможными вариантами символов для игры в крестики - нолики 
    //присваиваем им коды из таблицы  ASCII-символов

   enum Symbols
    {
        SYM_Z = 48,
        SYM_C = 88,
        SYM_S = 32,
    };

    //массив, содержащий значения такого перечисления и инициализация его 

    char game[3][3] = { {SYM_Z,SYM_C,SYM_S}, {SYM_S,SYM_C,SYM_Z}, {SYM_C,SYM_Z,SYM_S} };

    std::cout << "Первый символ массива - это:           " << game[0][0] << " (Ноль)   " << std::endl;
    std::cout << "Второй символ массива - это:           " << game[1][1] << " (Крестик)" << std::endl;
    std::cout << "Третий символ массива - это:           " << game[2][2] << " (Пробел) " << std::endl;
    std::cout << std::endl;

    //структура (struct) данных, к игре в крестики-нолики имеет мало отношения (так, тренировка) 
    //надо ещё много-много читать

    struct playfield
    {
        short rows;
        short columns;
        char cellsstatus;
    }; 
    playfield start = { 1, 2, 48 };
    playfield finish = { 3, 4, 88 };

    std::cout << "Переменная start.cellsstatus           " << start.cellsstatus << std::endl;
    std::cout << "Переменная finish.cellsstatus          " << finish.cellsstatus << std::endl;

    std::cout << std::endl;

    return 0;
}

