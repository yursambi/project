#include <iostream>
//#include <cmath>

int recursTranslation(int number)
{
    if(number > 1)
        recursTranslation(number /2);
    std::cout << number % 2;
    return number;
}

int recursPow(int a, unsigned int b)
{
    if (b != 0)
        return (a*recursPow(a, b - 1));
    else
        return 1;
}

int binPow(int c, unsigned int d)
{
    if (d == 0)
        return 1;
    if (d % 2 == 1)
        return binPow(c, d - 1) * c;
    else
    {
        int f = binPow(c, d / 2);
        return f * f;
    }
}

int main()
{
    std::cout << "                 Hello, Denis!" << std::endl << std::endl;

//task 1
    std::cout << " Converting a number from decimal to binary using recursion." << std::endl << std::endl;
    std::cout << " Enter a natural number:                  ";
    int number;
    std::cin >> number;
    std::cout << " The entered number in binary notation:   ";
    recursTranslation(number);
    std::cout << std::endl << std::endl;

//task 2
    std::cout << " Raising the number [a] to the power of [b] using recursion." << std::endl << std::endl;
    int a, result1;
    unsigned int b;
    std::cout << " Enter the number [a]:  ";
    std::cin >> a;
    std::cout << " Enter the number [b]:  ";
    std::cin >> b;
    result1 = recursPow(a, b);
    std::cout << " Calculation result:    " << a << "^" << b << " = " << result1 << std::endl << std::endl;

//task 3
    std::cout << " Raising the number [c] to the power of [d] is recursive," << std::endl;
    std::cout << " using the degree parity property." << std::endl << std::endl;
    int c, result2;
    unsigned int d;
    std::cout << " Enter the number [c]:  ";
    std::cin >> c;
    std::cout << " Enter the number [d]:  ";
    std::cin >> d;
    result2 = binPow(c, d);
    std::cout << " Calculation result:    " << c << "^" << d << " = " << result2 << std::endl << std::endl;

//task 4


    return 0;
}
