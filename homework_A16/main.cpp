#include <iostream>
#include <string>
#include <fstream>

void PrintHello()
{
    std::cout << "           Hello, Denis!" << std::endl << std::endl;
}

int CaesarEncryption(int shift)
{
    std::ifstream input("source.txt");
    const int numLetters = 26;
    char buff;
    int iter;

    if (!input.is_open())
    {
        std::cout << "  The source file cannot be opened!" << std::endl;
        return 0;
    }
    else
    {
        std::ofstream output("encrypted.txt");
        while (!input.eof())
        {
            buff = input.get();
            if (buff == ' ')
                output << ' ';
            if (buff == '\n')
                output << '\n';
            if (buff == ',')
                output << ',';
            if (buff == '.')
                output << '.';
            if (buff >= 'A' && buff <= 'Z')
            {
                iter = int(buff) - int('A');
                iter = (iter + shift) % numLetters;
                iter += (int)'A';
                output << char(iter);
            }
            if (buff >= 'a' && buff <= 'z')
            {
                iter = int(buff) - int('a');
                iter = (iter + shift) % numLetters;
                iter += (int)'a';
                output << char(iter);
            }
        }
        output.close();
    }
    input.close();

    std::ifstream input1("source.txt");
    std::cout << "  Initial text" << std::endl << std::endl;
    while (!input1.eof())
    {
        std::string strInput;
        getline(input1, strInput);
        std::cout << strInput << std::endl;
    }
    input1.close();
    std::cout << std::endl;

    std::ifstream input2("encrypted.txt");
    std::cout << "  Encrypted text" << std::endl << std::endl;
    while (!input2.eof())
    {
        std::string strOutput;
        getline(input2, strOutput);
        std::cout << strOutput << std::endl;
    }
    input2.close();
    std::cout << std::endl;

    return 0;
}

int CaesarDecryption(int shift)
{
    std::ifstream input1("source.txt");
    std::ifstream input("encrypted.txt");
    const int numLetters = 26;
    char buff;
    int iter;

    if (!input.is_open() || !input1.is_open())
        return 0;
    else
    {
        std::ofstream output("decrypted.txt");
        while (!input.eof())
        {
            buff = input.get();
            if (buff == ' ')
                output << ' ';
            if (buff == '\n')
                output << '\n';
            if (buff == ',')
                output << ',';
            if (buff == '.')
                output << '.';
            if (buff >= 'A' && buff <= 'Z')
            {
                iter = int(buff) - int('A');
                iter = (iter - shift + numLetters) % numLetters;
                iter += (int)'A';
                output << char(iter);
            }
            if (buff >= 'a' && buff <= 'z')
            {
                iter = int(buff) - int('a');
                iter = (iter - shift + numLetters) % numLetters;
                iter += (int)'a';
                output << char(iter);
            }
        }
        output.close();
    }
    input1.close();
    input.close();

    std::ifstream input2("decrypted.txt");
    std::cout << "  Decrypted text" << std::endl << std::endl;
    while (!input2.eof())
    {
        std::string strOutput;
        getline(input2, strOutput);
        std::cout << strOutput << std::endl;
    }
    input2.close();

    return 0;
}

int main()
{
    PrintHello();

    std::cout << "  Caesar's Cipher" << std::endl << std::endl;
    const int minShift = 1;
    const int maxShift = 25;
    int shift = 0;
    std::cout << "  Enter the shift size (from 1 to 25):  ";
    std::cin >> shift;
    std::cout << std::endl;

    if (shift < minShift || shift > maxShift)
    {
        std::cout << "  Incorrect shift size!" << std::endl;
        return 0;
    }
    else
    {
        CaesarEncryption(shift);
        CaesarDecryption(shift);
    }

    return 0;
}
