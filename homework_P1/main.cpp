#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdint>

void PrintHello()
{
    std::cout << "           Hello, Michael!" << std::endl;
}

// task_1 ---------------------------------------------------------

class Power
{
//private:

    int m_num1 = 2;
    int m_num2 = 3;

public:

    void Set(int num1, int num2)
    {
        m_num1 = num1;
        m_num2 = num2;
    }

    void Calculate()
    {
        std::cout << " Pow(" << m_num1 << "," << m_num2 << ")" << " = ";
        std::cout << pow(m_num1, m_num2) << std::endl;
    }
};

// task_2 ---------------------------------------------------------

class RGBA
{
//private:

    std::uint8_t m_red;
    std::uint8_t m_green;
    std::uint8_t m_blue;
    std::uint8_t m_alpha;

public:

    RGBA(std::uint8_t red=0, std::uint8_t green=0, std::uint8_t blue=0, std::uint8_t alpha=255) :
        m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
    {
    }

    void Print()
    {
        std::cout << " red = " << std::setw(3) << static_cast<int>(m_red);
        std::cout << "  green = " << std::setw(3) << static_cast<int>(m_green);
        std::cout << "  blue = " << std::setw(3) << static_cast<int>(m_blue);
        std::cout << "  alpha = " << std::setw(3) << static_cast<int>(m_alpha) << std::endl;
    }
};

// task_3 ---------------------------------------------------------

class Stack
{
//private:

    int m_line[10];
    int m_next;

public:

    void Reset()
    {
        m_next = 0;
        for (int i = 0; i < 10; i++)
            m_line[i] = 0;
    }

    bool Push(int value)
    {
        if (m_next == 10)
        {
            std::cout << " The stack is already full!" << std::endl;
            return false;
        }
        else
        {
            m_line[m_next++] = value;
            return true;
        }
    }

    int Pop()
    {
        if (m_next == 0)
        {
            std::cout << " The stack is already empty!" << std::endl;
            return 0;
        }
        else
        {
            int value = m_line[m_next-1];
            --m_next;
            return value;
        }
    }

    void Print()
    {
        std::cout << " ( ";
        for (int i = 0; i < m_next; i++)
            std::cout << m_line[i] << " ";
        std::cout << ")" << std::endl;
    }
};

int main()
{

    PrintHello();
    std::cout << std::endl;

    // task_1 ---------------------------------------------------------

    std::cout << " Implementation of the Power class." << std::endl;

    Power pow;
    pow.Calculate();
    pow.Set(3, 4);
    pow.Calculate();
    pow.Set(4, 5);
    pow.Calculate();

    std::cout << std::endl;

    // task_2 ---------------------------------------------------------

    std::cout << " Implementation of the RGBA class." << std::endl;

    RGBA color;
    color.Print();
    RGBA color1(75, 115, 135);
    color1.Print();
    RGBA color2(35, 125, 155, 215);
    color2.Print();

    std::cout << std::endl;

    // task_3 ---------------------------------------------------------

    std::cout << " A class that implements stack functionality." << std::endl;

    Stack stk;

    stk.Reset();
    stk.Print();

    stk.Push(3);
    stk.Push(7);
    stk.Push(5);
    stk.Print();

    stk.Pop();
    stk.Print();

    stk.Pop();
    stk.Pop();
    stk.Print();

    for (int i = 0; i < 10; i++)
        stk.Push(i + 1);
    stk.Print();

    stk.Push(11);

    stk.Pop();
    stk.Print();

    stk.Push(11);
    stk.Print();

    for (int i = 0; i < 10; i++)
        stk.Pop();
    stk.Print();

    stk.Pop();

    return 0;
}
