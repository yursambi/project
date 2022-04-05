#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

void PrintHello()
{
    std::cout << "           Hello, Denis!" << std::endl << std::endl;
}

void swapInt(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void fillIntRandom(int* array, int size, int border)
{
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < size; i++)
        *(array + i) = rand() % border; // array[i]
}

void printIntArray(int* array, int size)
{
    for (int i = 0; i < size; i++)
        {
        std::cout << array[i]; // *(array + i)
        if (i != size - 1)
            std::cout << "; ";
        }
        std::cout << std::endl << std::endl;
}

void qsH(int* array, int first, int last)
{
    int i = first;
    int j = last;

    int x = array[(first + last) / 2];

    do
    {
        while(array[i] < x) i++;
        while(array[j] > x) j--;

        if (i <= j)
        {
           swapInt(&array[i], &array[j]);
           i++;
           j--;
        }
    }
    while (i <= j);

    if (i < last) qsH(array, i, last);
    if (j > first) qsH(array, first, j);
}

void qsL(int* array, int first, int last)
{
    if (first < last)
    {
        int x = array[last];
        int i = first;
        int j;
        for (j = first; j <= last - 1; j++)
        {
            if (array[j] <= x)
            {
                swapInt(&array[i], &array[j]);
                i++;
            }
        }
        swapInt(&array[i], &array[last]);
        qsL(array, first, i - 1);
        qsL(array, i + 1, last);
    }
}

void sortShells(int* array, int len)
{
    int i;
    int j;
    int step;
    int temp;

    for (step = len / 2; step > 0; step /= 2)
    {
        for (i = step; i < len; i++)
        {
            temp = array[i];
            for (j = i;j >= step; j -= step)
            {
                if (temp < array[j - step])
                {
                    array[j] = array[j - step];
                }
                else
                {
                    break;
                }
            }
            array[j] = temp;
        }
    }
}

int main()
{
    PrintHello();

//task1   Quick sorting end sorting by inserts------------------
    const int SIZE = 30;
    int arr[SIZE];
    int border = 100;
    fillIntRandom(arr, SIZE, border);
    printIntArray(arr, SIZE);
    //qsH(arr, 0, SIZE - 1);        //  Hoare Quick sorting
    //qsL(arr, 0, SIZE - 1);        //  Quick sorting of Lamuto
    //sortShells(arr, SIZE);        //  Sorting by inserts (Shell sorting)

//task2   bucketSort (block sorting)-----------------------------
    const int max = SIZE;
    const int b = 10;
    int buckets[b][max + 1];

    for (int i = 0; i < b; i++)
    {
        buckets[i][max] = 0;
    }

    for (int digit = 1; digit < 1000000000; digit *= 10)
    {
        for (int i =0; i < max; i++)
        {
            if (arr[i] % 2 == 0)
            {
                int d = (arr[i] / digit) % b;
                buckets[d][buckets[d][max]++] = arr[i];
                arr[i] = -1;
            }
        }
        int idx = 0;
        for (int i =0; i < b; i++)
        {
            for (int j =0; j < buckets[i][max]; j++)
            {
                while (arr[idx] != -1)
                {
                    idx++;
                }
                arr[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }

    printIntArray(arr, SIZE);


    return 0;
}


