#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>

#define T char
#define true 1 == 1
#define false 1 != 1

std::stack <int> Stack;

void PrintHello()
{
    std::cout << "           Hello, Denis!" << std::endl;
}

const int n = 6;

int matrix[n][n] = {{0, 1, 1, 0, 0, 0},
                    {0, 0, 0, 1, 1, 1},
                    {0, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 1, 0}};

int visited[n] = {0};

typedef struct TwoLinkNode
{
    int dat;
    T dt;
    struct TwoLinkNode *next;
    struct TwoLinkNode *prev;
} TwoLinkNode;

typedef struct
{
    struct TwoLinkNode *head;
    struct TwoLinkNode *tail;
    int size;
} TwoLinkList;

//  Traversing a graph in depth using recursion-------------------------------------

void depthTravers(int st)
{
    int r;
    std::cout << " " << st;

    visited[st] = 1;
    for (r = 0; r < n; r++)
    {
        if (matrix[st][r] == 1 && !visited[r])
            depthTravers(r);
    }
}

void resetArr()
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
}

//  Traversing a graph in width using a queue---------------------------------------

void set2dInt(int **arr, const int row, const int col, int value)
{
    *((*(arr + row)) + col) = value;
}

int **init2dIntArray(int **arr, const int row, const int col)
{
    arr = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(arr + i) = (int*) calloc(sizeof(int), col);
    }
    return arr;
}

void initTwoLinkList(TwoLinkList *lst)
{
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}

bool TwoLinkEnqueue(TwoLinkList *que, int value)
{
    TwoLinkNode *tmp = (TwoLinkNode*) std::malloc(sizeof(TwoLinkNode));
    if (tmp == NULL)
    {
        std::cout << "Out of memory";
        return false;
    }
    tmp->dt = value;
    tmp->next = NULL;
    tmp->prev = que->tail;

    if (que->tail != NULL)
    {
        que->tail->next = tmp;
    }
    if (que->head == NULL)
    {
        que->head = tmp;
    }

    que->tail = tmp;
    que->size++;
    return true;
}

T TwoLinkDequeue(TwoLinkList *que)
{
    if (que->size == 0)
    {
        std::cout << "Queue is empty";
        return -1;
    }
    TwoLinkNode *tmp = que->head;
    T data = que->head->dt;

    que->head = que->head->next;

    if (que->head != NULL)
    {
        que->head->prev = NULL;
    }
    if (tmp == que->tail)
    {
        que->tail = NULL;
    }

    std::free(tmp);
    que->size--;
    return data;
}

void clearVisited(int *arr, const int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = 0;
}

void widthTravers(int **matrix, int st, const int size)
{
    TwoLinkList *que = (TwoLinkList*) std::malloc(sizeof(TwoLinkList));
    initTwoLinkList(que);
    visited[st] = 1;
    clearVisited(visited, size);
    TwoLinkEnqueue(que, st);
    while (que->size > 0)
    {
        int index = TwoLinkDequeue(que);
        if (visited[index] == 1)
            continue;
        visited[index] = 1;
        std::cout << " " << index;
        for (int i = 0; i < size; i++)
        {
            if (matrix[index][i] == 1 && visited[i] == 0)
                TwoLinkEnqueue(que, i);
        }
    }
}

//  Traversing a graph in depth using a stack------------------------------------------

void depthStackTravers(int node)
{
     for (int i = 0; i < n; i++)
         visited[i] = 0;

     const int attended = 2;
     const int detected = 1;
     Stack.push(node);
     while (!Stack.empty())
     {
         node = Stack.top();
         Stack.pop();
         if (visited[node] == attended)
            continue;
         visited[node] = attended;
         for (int j = n - 1; j >= 0; j--)
         {
             if (matrix[node][j] == detected && visited[j] != attended)
             {
                 Stack.push(j);
                 visited[j] = detected;
             }
         }
         std::cout << " " << node;
     }
}

int main()
{
    PrintHello();

    std::cout << std::endl;
    std::cout << " Traversing a graph in depth using recursion" << std::endl;
    depthTravers(0);
    resetArr();
    std::cout << std::endl;
    depthTravers(2);
    resetArr();
    std::cout << std::endl;
    depthTravers(1);
    resetArr();
    std::cout << std::endl;
    depthTravers(3);
    resetArr();
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << " Traversing a graph in width using a queue" << std::endl;
    const int SZ = 6;
    int **adjacency = init2dIntArray(NULL, SZ, SZ);
    set2dInt(adjacency, 0, 1, 1);
    set2dInt(adjacency, 0, 2, 1);
    set2dInt(adjacency, 1, 3, 1);
    set2dInt(adjacency, 1, 4, 1);
    set2dInt(adjacency, 1, 5, 1);
    set2dInt(adjacency, 2, 5, 1);
    set2dInt(adjacency, 3, 0, 1);
    set2dInt(adjacency, 5, 4, 1);

    widthTravers(adjacency, 0, SZ);
    std::cout << std::endl;
    widthTravers(adjacency, 3, SZ);
    std::cout << std::endl;
    widthTravers(adjacency, 1, SZ);
    std::cout << std::endl;
    widthTravers(adjacency, 2, SZ);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << " Traversing a graph in depth using a stack" << std::endl;
    depthStackTravers(0);
    std::cout << std::endl;
    depthStackTravers(2);
    std::cout << std::endl;
    depthStackTravers(1);
    std::cout << std::endl;
    depthStackTravers(3);
    std::cout << std::endl;
    depthStackTravers(4);
    std::cout << std::endl;
    depthStackTravers(5);
    std::cout << std::endl;


    std::cout << std::endl;
    return 0;
}
