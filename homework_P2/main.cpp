#include <iostream>
#include <string>

void PrintHello()
{
    std::cout << "           Hello, Michael!" << std::endl;
}

// task_1 ---------------------------------------------------------------

class Person
{
private:
    std::string m_name;
    int m_age;
    std::string m_gender;
    double m_weight;

public:
    Person(std::string name = "", int age = 0, std::string gender = "", double weight = 0.0) :
        m_name(name), m_age(age ), m_gender(gender), m_weight(weight)
    {
    }

    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }
    std::string getGender() const { return m_gender; }
    double getWeight() const { return m_weight; }
};

class Student : public Person
{
private:
    int m_yearStudy;
    static int s_idGenerator;
    int m_id;

public:
    Student(std::string name = "", int age = 0, std::string gender = "", double weight = 0.0,
        int yearStudy = 0, int id = 0) : Person(name, age, gender, weight),
        m_yearStudy(yearStudy), m_id(id)
    {
        m_id = s_idGenerator++;
    }

    int getYearStudy() const { return m_yearStudy; }
    int getID() const { return m_id; }
};

int Student::s_idGenerator = 1;

void studentDataOutput(Student any)
{
    std::cout << " Student:" << any.getID();
    std::cout << "  Name:   " << any.getName() << std::endl;
    std::cout << "            Age:    " << any.getAge() << " years" << std::endl;
    std::cout << "            Gender: " << any.getGender() << std::endl;
    std::cout << "            Weight: " << any.getWeight() << " kg" << std::endl;
    std::cout << "            Study:  " << any.getYearStudy() << " year" << std::endl;
    std::cout << std::endl;
}

// task_2 ---------------------------------------------------------------

class Fruit
{
private:
    std::string m_name;
    std::string m_color;

public:
    Fruit(std::string name, std::string color) : m_name(name), m_color(color)
    {
    }

    std::string getName() { return m_name; }
    std::string getColor() { return m_color; }
};

class Apple : public Fruit
{
protected:
    Apple(std::string name, std::string color) : Fruit(name, color)
    {
    }

public:
    // an apple can be any color
    Apple(std::string color="colourful") : Fruit("apple", color)
    {
    }
};

class Banana : public Fruit
{
public:
    // the banana can be yellow, green or red
    Banana(std::string color="yellow") : Fruit("banana", color)
    {
    }
};

class GrannySmith : public Apple
{
public:
    // Granny Smith's apple is almost always green
    GrannySmith() : Apple("Granny Smith apple", "green")
    {
    }
};

int main()
{
    PrintHello();
    std::cout << std::endl;

// task_1 ---------------------------------------------------------------
    std::cout << " Implementation of the Person and Student classes." << std::endl;
    std::cout << std::endl;

    Student first("Evgeny Zhukov", 19, "male", 74.2, 2);
    studentDataOutput(first);

    Student second("Anna Efimova", 21, "female", 61.9, 3);
    studentDataOutput(second);

    Student third("Vladimir Kuznetsov", 22, "male", 79.5, 5);
    studentDataOutput(third);

// task_2 ---------------------------------------------------------------
    std::cout << " Implementation of the Fruit, Apple, Banana and GrannySmith classes.";
    std::cout << std::endl << std::endl;

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << " My " << a.getName() << " is " << a.getColor() << "." << std::endl;
    std::cout << " My " << b.getName() << " is " << b.getColor() << "." << std::endl;
    std::cout << " My " << c.getName() << " is " << c.getColor() << "." << std::endl;

return 0;
}

