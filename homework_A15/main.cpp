#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iomanip>

void PrintHello()
{
    std::cout << "           Hello, Denis!" << std::endl;
}

void fillIntRandom(int* array, int size, int border)
{
    //srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < size; i++)
        *(array + i) = rand() % border;
}

typedef struct OneLinkNode
{
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;

#define T char

typedef int K;
typedef int htIndex;

int htSize;

// Building a hash table using the chain method------------------------------------------

htIndex Hash(T data)
{
    return data % htSize;
}

bool insertNode(OneLinkNode **table, K data)
{
    OneLinkNode *p, *p0;

    htIndex bucket = Hash(data);
    p = (OneLinkNode*) std::malloc(sizeof(OneLinkNode));
    if (p == NULL)
    {
        std::cout << " Out of memory!" << std::endl;
        return false;
    }

    p0 = table[bucket];
    table[bucket] = p;
    p->next = p0;
    p->dat = data;
    return true;
}

OneLinkNode* findNode(OneLinkNode **table, K data)
{
    OneLinkNode *p = table[Hash(data)];
    while (p && !(p->dat == data))
        p = p->next;
    return p;
}

void deleteNode(OneLinkNode **table, K data)
{
    OneLinkNode *parent, *current;
    parent = NULL;
    htIndex bucket = Hash(data);
    current = table[bucket];
    while (current && !(current->dat == data))
    {
        parent = current;
        current = current->next;
    }

    if (!current)
    {
        std::cout << " Value not found!" << std::endl;
        return;
    }

    if (parent)
        parent->next = current->next;
    else
        table[bucket] = current->next;
    std::free(current);
}

void printTable(OneLinkNode **table, int size)
{
    OneLinkNode *p;
    for (int i = 0; i < size; i++)
    {
        p = table[i];
        while (p)
        {
            std::cout << std::setw(5) << p->dat;
            //printf("%5d", p->dat);
            p = p->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printOneLinkIntNode(OneLinkNode *n)
{
    if (n == NULL)
    {
        std::cout << "[  ]";
        return;
    }
    std::cout << "[" << n->dat << "]";
}

// We calculate the sum of the symbol codes of the entered string-----------------------------

unsigned int hashSymbolString(char *Str)
{
    unsigned int sign = 0;
    while (*Str != '\0')
    {
        sign += (int)(*Str);
        Str++;
    }
    return sign;
}

// A set of a given amount with a minimum number of coins-------------------------------------

void quantityCaculation(int *mass, int Sum, int Num)
{
    int temp ;

    while (Sum > 0)
    {
        if (Sum >= mass[Num])
        {
            temp =0;
            while(Sum >= mass[Num])
            {
                temp++;
                Sum -= mass[Num];
            }
            std::cout << " " << temp << "  coins by  " << std::setw(2) << mass[Num]  << "  kopeck" << std::endl;
        }
        Num--;
    }
}

int main()
{
    PrintHello();
    std::cout << std::endl;
//----------------------------------------------------------------------------------------------
    std::cout << " Building a hash table using the chain method." << std::endl << std::endl;

    htSize = 8;
    int* arr;
    const int SZ = 20;
    arr = (int*) std::malloc(sizeof(int) * SZ);
    fillIntRandom(arr, SZ, 100);

    OneLinkNode **hashTable = (OneLinkNode**) std::calloc(htSize, sizeof(OneLinkNode*));

    for (int i = 0; i < SZ; i++)
    {
        insertNode(hashTable, arr[i]);
    }
    printTable(hashTable, htSize);

    std::cout << "  ";
    printOneLinkIntNode(findNode(hashTable, 64));
    std::cout << " ";
    printOneLinkIntNode(findNode(hashTable, 45));
    std::cout << std::endl << std::endl ;

    for (int i = 0; i < SZ / 2; i++)
    {
        deleteNode(hashTable, arr[i]);
    }
    printTable(hashTable, htSize);

    std::cout << "  ";
    printOneLinkIntNode(findNode(hashTable, 64));
    std::cout << " ";
    printOneLinkIntNode(findNode(hashTable, 45));
    std::cout << std::endl << std::endl ;
// task1---------------------------------------------------------------------------------------------
    std::cout  << " We calculate the sum of the symbol codes of the entered string." << std::endl << std::endl;
    const int sizeLine = 100;
    char Line[sizeLine] = { 0 };
    std::cout << " Enter string:  ";
    std::cin.getline(Line, sizeLine);
    std::cout << " Sum of codes:  " << hashSymbolString(Line) << std::endl;
//task2----------------------------------------------------------------------------------------------
    std::cout  << std::endl;
    std::cout  << " A set of a given amount with a minimum number of coins." << std::endl << std::endl;
    std::cout  << " Enter the amount to calculate the number of coins:  ";
    int mass[] = {1, 2, 5, 10, 50};
    int Sum;
    int Num = 4;
    std::cin >> Sum;
    quantityCaculation(mass, Sum, Num);


    std::cout << std::endl;
    return 0;
}

