#include <iostream>
#include <cstdlib>
//#include <stack>

void PrintHello()
{
    std::cout << "           Hello, Denis!" << std::endl << std::endl;
}

#define T char
#define true 1 == 1
#define false 1 != 1


typedef struct Node
{
    int dat;
    T dt;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int size;
} List;

//  Implementation of a singly linked list--------------------------------------------

void initOneList(List *lst)
{
    lst->head = NULL;
    lst->size = 0;
}

void insList(List *lst, int data)
{
    Node *NEW = (Node*) std::malloc(sizeof(Node));
    NEW->dat = data;
    NEW->next = NULL;

    Node *current = lst->head;
    if (current == NULL)
    {
        lst->head = NEW;
        lst->size++;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = NEW;
        lst->size++;
    }
}

Node *rmList(List *lst, int data)
{
    Node *current = lst->head;
    Node *parent = NULL;

    if (current == NULL)
        return NULL;

    while (current->next != NULL && current->dat != data)
    {
        parent = current;
        current = current->next;
    }
    if (current->dat != data)
        return NULL;
    if (current == lst->head)
    {
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    lst->size--;
    return current;
}

void printNode(Node *n)
{
    if (n ==NULL)
    {
        std::cout << "[ ]";
        return;
    }
    std::cout << "[" << n->dat << "]";
}

void printList(List *lst)
{
    Node *current = lst->head;
    if (current == NULL)
    {
       printNode(current);
    }
    else
    {
        do
        {
            printNode(current);
            current = current->next;
        }
        while (current != NULL);
    }
    std::cout << " Size: " << lst->size << "\n";
}

//  Implementing a doubly linked list---------------------------------------------

void initTwoList(List *lst)
{
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}

void pushFront(List *lst, int data)
{
    Node *NEW = (Node*) std::malloc(sizeof(Node));
    NEW->dat = data;
    NEW->prev = NULL;
    NEW->next = lst->head;
    if (lst->head != NULL)
        lst->head->prev = NEW;
    if (lst->tail == NULL)
        lst->tail = NEW;
    lst->head = NEW;
    lst->size++;
}

void pushBack(List *lst, int data)
{
    Node *NEW = (Node*) std::malloc(sizeof(Node));
    NEW->dat = data;
    NEW->next = NULL;
    NEW->prev = lst->tail;
    if (lst->tail != NULL)
        lst->tail->next = NEW;
    if (lst->head == NULL)
        lst->head = NEW;
    lst->tail = NEW;
    lst->size++;
}

Node *rmFront(List *lst)
{
    if (lst->head == NULL)
        return NULL;
    Node *tmp = lst->head;
    lst->head = lst->head->next;
    if (lst->head != NULL)
        lst->head->prev = NULL;
    if (tmp == lst->tail)
        lst->tail = NULL;
    lst->size--;
    return tmp;
}

Node *rmBack(List *lst)
{
    if (lst->tail == NULL)
        return NULL;
    Node *tmp = lst->tail;
    lst->tail = lst->tail->prev;
    if (lst->tail != NULL)
        lst->tail->next = NULL;
    if (tmp == lst->head)
        lst->head = NULL;
    lst->size--;
    return tmp;
}

//  Implementation of a cyclic list-----------------------------------

void insCycList (List *lst, int data)
{
    Node *NEW = (Node*) std::malloc(sizeof(Node));
    NEW->dat = data;
    NEW->next = lst->head;

    Node *current = lst->head;
    if (current == NULL)
    {
        lst->head = NEW;
        NEW->next = lst->head;
        lst->size++;
        return;
    }
    else
    {
        while (current->next != lst->head)
        {
            current = current->next;
        }
        current->next = NEW;
        lst->size++;
    }
}

Node *rmCycList(List *lst, int data)
{
    Node *current = lst->head;
    Node *parent = NULL;

    if (current == NULL)
        return NULL;

    while (current->next != lst->head && current->dat != data)
    {
        parent = current;
        current = current->next;
    }
    if (current->dat != data)
        return NULL;
    if (current == lst->head)
    {
        if (current->next == lst->head)
        {
            lst->head = NULL;
            lst->size--;
            return current;
        }
        else
        {
            Node *tmp = current;
            while (current->next != lst->head)
            {
                current = current->next;
            }
            lst->head = tmp->next;
            current->next = lst->head;
            lst->size--;
            return tmp;
        }
    }
    parent->next = current->next;
    lst->size--;
    return current;
}

void printCycList(List *lst)
{
    Node *current = lst->head;
    if (current == NULL)
    {
        printNode(current);
    }
    else
    {
        do
        {
            printNode(current);
            current = current->next;
        }
        while (current != lst->head);
    }
    std::cout << " Size: " << lst->size << "\n";
}

//  Stack based on a singly linked list------------------------------------

void initStkList(List *stk)
{
    stk->head = NULL;
    stk->size = 0;
}

bool pushStack(List *stk, T value)
{
    Node *tmp = (Node*) std::malloc(sizeof(Node));
    if (tmp == NULL) {
        std::cout << "Stack overflow";
        return false;
    }
    tmp->dt = value;
    tmp->next = stk->head;

    stk->head = tmp;
    stk->size++;
    return true;
}

T popStack(List *stk) {
    if (stk->size == 0) {
        std::cout << "Stack is empty";
        return -1;
    }
    Node *tmp = stk->head;
    T data = stk->head->dt;
    stk->head = stk->head->next;
    std::free(tmp);
    stk->size--;
    return data;
}

void printCharNode(Node *n)
{
    if (n == NULL)
    {
        std::cout << "[ ]";
        return;
    }
    std::cout << "[" << n->dt << "]";
}

void printCharStack(List *stk)
{
    Node *current = stk->head;
    if (current == NULL)
    {
        printCharNode(current);
    }
    else
    {
        do
        {
            printCharNode(current);
            current = current->next;
        }
        while (current != NULL);
    }
    std::cout << " Size: " << stk->size << "\n";
}

//  A queue based on a doubly linked list------------------------------------

bool Enqueue(List *que, T value)
{
    Node *tmp = (Node*) std::malloc(sizeof(Node));
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

T Dequeue(List *que)
{
    if (que->size == 0)
    {
        std::cout << "Queue is empty";
        return -1;
    }
    Node *tmp = que->head;
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

void printCharQueue(List *que)
{
    Node *current = que->head;
    if (current == NULL)
    {
        printCharNode(current);
    }
    else
    {
        do
        {
            printCharNode(current);
            current = current->next;
        }
        while (current != NULL);
    }
    std::cout << " Size: " << que->size << "\n";
}

int main()
{
    PrintHello();

//  A singly linked list ---------------------------------------------------

    List *lst = (List*) std::malloc(sizeof(List));
    initOneList(lst);
    //printList(lst);
    insList(lst, 1);
    printList(lst);
    insList(lst, 10);
    printList(lst);
    insList(lst, 100);
    printList(lst);
    printNode(rmList(lst, 1)); std::cout << "<-- removed node" << "\n";
    printList(lst);
    printNode(rmList(lst, 3)); std::cout << "<-- removed node" << "\n";
    printList(lst);

//A doubly linked list---------------------------------------------------------

    std::cout << std::endl;
    //List *lst = (List*) std::malloc(sizeof(List));
    initTwoList(lst);
    //printList(lst);
    pushFront(lst, 20);
    pushFront(lst, 10);
    pushBack(lst, 30);
    pushBack(lst, 40);
    printList(lst);
    printNode(rmFront(lst)); std::cout << "<-- removed node" << "\n";
    printList(lst);
    printNode(rmBack(lst)); std::cout << "<-- removed node" << "\n";
    printList(lst);
    printNode(rmFront(lst)); std::cout << "<-- removed node" << "\n";
    //printNode(rmFront(lst)); std::cout << "<-- removed node" << "\n";
    printList(lst);

//  Cyclic list --------------------------------------------------------

    std::cout << std::endl;
    //List *lst = (List*) std::malloc(sizeof(List));
    initOneList(lst);
    //printCycList(lst);
    insCycList (lst, 1);
    insCycList (lst, 10);
    insCycList (lst, 20);
    printCycList(lst);
    printNode(rmCycList(lst, 1)); std::cout << "<-- removed node" << "\n";
    printCycList(lst);
    printNode(rmCycList(lst, 2)); std::cout << "<-- removed node" << "\n";
    printCycList(lst);
    insCycList (lst, 30);
    printCycList(lst);
    printNode(rmCycList(lst, 10)); std::cout << "<-- removed node" << "\n";
    printNode(rmCycList(lst, 20)); std::cout << "<-- removed node" << "\n";
    //printNode(rmCycList(lst, 30)); std::cout << "<-- removed node" << "\n";
    printCycList(lst);

//  Stack based on a singly linked list------------------------------------

    std::cout << std::endl;
    List *stk = (List*) std::malloc(sizeof(List));
    initStkList(stk);
    //printCharStack(stk);
    pushStack(stk, 'a');
    pushStack(stk, 'b');
    pushStack(stk, 'c');
    pushStack(stk, 'd');
    pushStack(stk, 'e');
    pushStack(stk, 'f');
    printCharStack(stk);
    std::cout << "[" << popStack(stk) << "]" << "<-- removed node" << "\n";
    printCharStack(stk);
    std::cout << "[" << popStack(stk) << "]" << "<-- removed node" << "\n";
    printCharStack(stk);
    std::cout << "[" << popStack(stk) << "]" << "<-- removed node" << "\n";
    printCharStack(stk);
    std::cout << "[" << popStack(stk) << "]" << "<-- removed node" << "\n";
    std::cout << "[" << popStack(stk) << "]" << "<-- removed node" << "\n";
    std::cout << "[" << popStack(stk) << "]" << "<-- removed node" << "\n";
    printCharStack(stk);
    std::cout << popStack(stk) << "\n";

//  A queue based on a doubly linked list------------------------------------

    std::cout << std::endl;
    List *que = (List*) std::malloc(sizeof(List));
    initTwoList(que);
    //printCharQueue(que);
    Enqueue(que, 'a');
    Enqueue(que, 'b');
    Enqueue(que, 'c');
    Enqueue(que, 'd');
    Enqueue(que, 'e');
    Enqueue(que, 'f');
    printCharQueue(que);
    std::cout << "[" << Dequeue(que) << "]" << "<-- removed node" << "\n";
    std::cout << "[" << Dequeue(que) << "]" << "<-- removed node" << "\n";
    std::cout << "[" << Dequeue(que) << "]" << "<-- removed node" << "\n";
    printCharQueue(que);
    std::cout << "[" << Dequeue(que) << "]" << "<-- removed node" << "\n";
    std::cout << "[" << Dequeue(que) << "]" << "<-- removed node" << "\n";
    std::cout << "[" << Dequeue(que) << "]" << "<-- removed node" << "\n";
    printCharQueue(que);
    std::cout << Dequeue(que) << "\n";


    //std::cout << std::endl;
    return 0;
}
