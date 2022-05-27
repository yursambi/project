#include <iostream>
#include <string>
#include <cmath>

void PrintHello()
{
    std::cout << "           Hello, Michael!" << std::endl;
}

// task_1 ---------------------------------------------------------------

class Figure
{
private:
    std::string m_shape;

public:
    Figure(std::string shape) : m_shape(shape)
    {
    }

    std::string getShape() { return m_shape; }
    virtual double area() = 0;
};

class Parallelogram: public Figure
{
private:
    double m_base;
    double m_height;

protected:
     Parallelogram(std::string shape) : Figure(shape)
     {
     }

public:
    Parallelogram(double base, double height) :
        Figure("Parallelogram"), m_base(base), m_height(height)
    {
    }

    virtual double area() { return (m_base * m_height); }
};

class Circle: public Figure
{
private:
    double m_radius;

public:
    Circle(double radius) : Figure("Circle"), m_radius(radius)
    {
    }

    virtual double area() { return (3.14 * pow(m_radius, 2)); }
};

class Rectangle: public Parallelogram
{
private:
    double m_length;
    double m_width;

public:
    Rectangle(double length, double width) :
        Parallelogram("Rectangle"), m_length(length), m_width(width)
    {
    }

    virtual double area() { return (m_length * m_width); }
};

class Square: public Parallelogram
{
private:
    double m_side;

public:
    Square(double side) : Parallelogram("Square"), m_side(side)
    {
    }

    virtual double area() { return pow(m_side, 2); }
};

class Rhombus: public Parallelogram
{
private:
    double m_diagonal_a;
    double m_diagonal_b;

public:
    Rhombus(double diagonal_a, double diagonal_b) :
        Parallelogram("Rhombus"), m_diagonal_a(diagonal_a), m_diagonal_b(diagonal_b)
    {
    }

    virtual double area() { return (m_diagonal_a * m_diagonal_b) / 2; }
};

int main()
{
    PrintHello();
    std::cout << std::endl;

// task_1 ---------------------------------------------------------------
    std::cout << " Implementation of an abstract class." << std::endl;
    std::cout << std::endl;

    Circle c(5);
    std::cout << " The area of the " << c.getShape() << " is " << c.area() << '\n';

    Parallelogram p(6.3, 7.5);
    std::cout << " The area of the " << p.getShape() << " is " << p.area() << '\n';

    Rectangle r(6.6, 3.1);
    std::cout << " The area of the " << r.getShape() << " is " << r.area() << '\n';

    Square s(3.7);
    std::cout << " The area of the " << s.getShape() << " is " << s.area() << '\n';

    Rhombus rh(6.4, 7.7);
    std::cout << " The area of the " << rh.getShape() << " is " << rh.area() << '\n';

    return 0;
}
