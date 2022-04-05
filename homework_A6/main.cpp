#include <iostream>
#include <cmath>

//using namespace std;

int** initArrey(int** arrey, const int row, const int col)
{
    arrey = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; i++)
    {
        *(arrey + i) = (int*) calloc(sizeof(int), col);
    }
    return arrey;
}

void fillArrey(int** arrey, const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            *((*(arrey + i)) + j) = rand() %100; //  (i + 1) * (j + 1)
    }
}

void printArrey(int** arrey, const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            std::cout << "  " << *((*(arrey + i)) + j) << "\t";
            std::cout << std::endl << std::endl;
    }
}

void bubbleSort(int** arrey, const int row, const int col)
{
    int tmp;
    for (int k = 0; k < row; k++)
    {
        for (int r = 0; r < col; r++)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (*((*(arrey + i)) + j) > *((*(arrey + k)) + r))
                    {
                    tmp = *((*(arrey + i)) + j);
                    *((*(arrey + i)) + j) = *((*(arrey + k)) + r);
                    *((*(arrey + k)) + r) = tmp;
                    }
                }
            }
        }
    }
}

// func(x) = sqrt(fabs(x)) + 5 * pow(X, 3)
double tpkFunc(double x)
{
    return  sqrt(fabs(x)) + 5 * pow(x, 3);
}

int main()
{
    std::cout << "                 Hello, Denis!" << std::endl;

//task1
    std::cout << "  Initialize a two-dimensional array with pseudo-random numbers." << std::endl << std::endl;
    const int row = 4;
    const int col = 3;
    int** arr = initArrey(arr, row, col);
    fillArrey(arr, row, col);
    printArrey(arr, row, col);
    std::cout << "  We sort this array using the bubble method." << std::endl << std::endl;
    bubbleSort(arr, row, col);
    printArrey(arr, row, col);

//task2
    std::cout << "  Implementation of the Trabb Prado-Knuth algorithm." << std::endl;
    const int sizeSeq = 11;
    const int maxResult = 400;
    double Seq[sizeSeq] = {0};
    double y;
    std::cout << "  Enter any eleven numbers:" << std::endl;
    for (int i = 0; i < sizeSeq; i++)
    {
        std::cout << "  Seq[" << i << "] = ";
        std::cin >> Seq[i];
    }
    std::cout << std::endl;
    std::cout << "  Sequence Seq:  ";
    for (int i = 0; i < sizeSeq; i++)
    {
        std::cout << Seq[i] << "  ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "  Inverted Seq:  ";
    for (int i = sizeSeq - 1; i >= 0; i--)
    {
        std::cout << Seq[i] << "  ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "  We calculate by the formula: sqrt(fabs(X)) + 5 * pow(X, 3)" << std::endl << std::endl;
    for (int i = sizeSeq - 1; i >= 0; i--)
    {
        y = tpkFunc(Seq[i]);
        if (y > maxResult)
            std::cout << "  The result of calculations exceeds 400 !" << std::endl;
        else
            std::cout << "  y = " << y << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
