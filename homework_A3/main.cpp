#include <iostream>
#include <cmath>

int main()
{
    std::cout << "             Hello, Denis!" << std::endl;
    std::cout << std::endl;
    std::cout << "    We check whether some number is prime." << std::endl;
    std::cout << std::endl;
    std::cout <<  "Enter any natural (positive integer) number:  ";
    unsigned long long f, i;
    bool isPrime = true;
    std::cin >> f;
    std::cout << std::endl;

    if (f == 1 || f == 0)
    {
        isPrime = false;
    }
    else if (f == 2 || f == 3 || f == 5)
    {
        isPrime = true;
    }
    else if (f % 2 == 0) // любое чётное число
    {
        isPrime = false;
    }
    else if (f % 5 == 0) // числа, оканчивающиеся на 5
    {
        isPrime = false;
    }
    else
    {
        for (i = 3; i <= round(sqrt(f)); i += 2) //  проверяем только нечётные числа
        {
            if (f % i == 0)
            {
                isPrime = false;
                break;
            }
        }
    }

    if (isPrime)
    {
        std::cout << "                   This is a prime number";
    }
    else
    {
        std::cout << "               This is not a prime number";
    }
    std::cout << std::endl;

    return 0;
}
