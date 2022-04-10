#include <iostream>
#include <stack>
//#include <cstdlib>

#define T char
#define SIZE 10
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

T Queue[SIZE];
int first = 0;
int ending = -1;
int items = 0;

void PrintHello()
{
    std::cout << "           Hello, Denis!" << std::endl << std::endl;
}

//  Implementing a queue through an array

bool queueEn(T data)
{
    if (items == SIZE)
    {
        std::cout << "  Queue is full" << std::endl;
        Queue[++ending] = data;
        return false;
    }
    if (ending == SIZE - 1)
        ending = -1;
    Queue[++ending] = data;
    items++;
    return true;
}

T queueDe()
{
    if (items == 0)
    {
        std::cout << "  Queue is empty" << std::endl;
        return -1;
    }
    else
    {
        char tmp = Queue[first++];
        first %= SIZE; // if (first == size) first = 0;
        items--;
        return tmp;
    }
}

void queueTest()
{
    int i = 0;
    while (i <5)
    {
        queueEn('a');
        queueEn('b');
        queueEn('c');
        queueEn('d');
        queueEn('e');
        queueEn('f');
        while (items > 0)
        {
           std::cout << " " << queueDe();
        }
        std::cout << "\n";
        i++;
    }
}

//  Priority-enabled queue

typedef struct
{
    int pr;
    int dat;
} Node;

Node* arr[SIZE];
int head;
int tail;
int elements;

void initQueue()
{
    for (int i = 0; i < SIZE; i++)
        arr[i] = NULL;
    head = 0;
    tail = 0;
    elements = 0;
}

void insQueue (int pr, int dat)
{
    Node *node = (Node*) malloc(sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flag;

    if (elements == 0)
    {
        arr[tail++] = node;
        elements++;
    }
    else if (elements == SIZE)
    {
        std::cout << "  Queue is full";
        return;
    }
    else
    {
        int i = 0;
        int idx = 0;
        Node *tmp;
        for (i = head; i < tail; i++)
        {
            idx = i % SIZE;
            if (arr[idx]->pr > pr)
                break;
            else
                idx++;
        }
        flag = idx % SIZE;
        i++;
        while (i <= tail)
        {
            idx = i % SIZE;
            tmp = arr[idx];
            arr[idx] = arr[flag];
            arr[flag] = tmp;
            i++;
        }
        arr[flag] = node;
        elements++;
        tail++;
    }
}

Node* remQueue()
{
    if (elements == 0)
    {
        return NULL;
    }
    else
    {
        int idx = head++ % SIZE;
        Node *tmp = arr[idx];
        arr[idx] = NULL;
        elements--;
        return tmp;
    }
}

void printQueue()
{
    std::cout << " [";
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] == NULL)
            std::cout << " [*; *] ";
        else
            std::cout << " [" << arr[i]->pr << "; " << arr[i]->dat << "] ";
    }
    std::cout << "]" << "\n";
}

int main()
{
    PrintHello();

//task1-------------------------------------------------------------------------------
    std::cout << " Implementing a queue through an array:" << std::endl;
    queueTest();
// -----------------------------------------------------------------------------------
    std::cout << std::endl;
    std::cout << " Priority-enabled queue:" << std::endl;
    initQueue();
    insQueue(1, 11);
    insQueue(3, 22);
    insQueue(4, 33);
    insQueue(2, 44);
    insQueue(3, 55);
    insQueue(4, 66);
    insQueue(5, 77);
    insQueue(1, 88);
    insQueue(2, 99);
    insQueue(6, 100);
    printQueue();
    std::cout << std::endl;
    std::cout << " Removing the seven elements with the highest priority:" << std::endl;
    for (int i = 0; i < 7; i++)
    {
        Node* n = remQueue();
        std::cout << " pr=" << n->pr << "; " << "dat=" << n->dat << "\n";
    }
    printQueue();
    std::cout << std::endl;
    std::cout << " Adding three elements to the queue:" << std::endl;
    insQueue(1, 110);
    insQueue(3, 120);
    insQueue(6, 130);
    printQueue();
    std::cout << std::endl;
    std::cout << " We remove five elements:" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Node* n = remQueue();
        std::cout << " pr=" << n->pr << "; " << "dat=" << n->dat << "\n";
    }
    printQueue();

// task2-------------------------------------------------------------------------------
    std::cout << std::endl;
    std::cout << " Conversion from decimal to binary number system using stack:" << std::endl;
    std::stack <int> decimal, revdecimal;
    std::cout << " Enter a number in decimal notation:   ";
    char c;
    while (std::cin.get(c)) // we read symbol by symbol
    {
        if (c == '\n')
            break;
        if (isdigit(c))
            decimal.push(c - '0'); // putting the numbers on the stack
    }
    // since the numbers are in reverse order, we transfer them to another stack
    while (!decimal.empty())
    {
        revdecimal.push(decimal.top());
        decimal.pop();
    }
    int n = 0;
    while (!revdecimal.empty())
    {
        n *= 10; // shift all the numbers one to the left
        n += revdecimal.top(); // adding another digit
        revdecimal.pop();
    }
    //std::cout << " Resulting number:  " << n << std::endl; // we output the resulting number for verification
    std::stack <bool> binary;
    while (n)
    {
        binary.push(n % 2); // adding another binary digit to the stack
        n >>= 1;  // shift all binary digits one to the right
    }
    //std::cout << std::endl;
    std::cout << " This is a number in binary notation:  ";
    while (!binary.empty())
    {
        std::cout << binary.top(); // output the next binary digit
        binary.pop();
    }

    std::cout << std::endl;
    return 0;
}

