#include <iostream>
#include <cstdlib>
#include <cstdio>

void PrintHello()
{
    std::cout << "           Hello, Denis!" << std::endl << std::endl;
}

//#define T char
#define true 1 == 1
#define false 1 != 1


typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} TreeNode;

FILE *file;


//  Building a binary search tree-------------------------------------------------------

TreeNode *treeInsert(TreeNode *t, int data)
{
    TreeNode *newNode;
    newNode = (TreeNode*) std::malloc(sizeof(TreeNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    TreeNode *current = t;
    TreeNode *parent = t;
    if (t == NULL)
    {
        t = newNode;
    }
    else
    {
        while (current->key != data)
        {
            parent = current;
            if (current->key > data)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = newNode;
                    return t;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void printTree(TreeNode *root)
{
    if (root)
    {
        std::cout << root->key;
        if (root->left || root->right)
        {
            std::cout <<  "(";
            if (root->left)
                printTree(root->left);
            else
                std::cout << "NULL";
            std::cout << ",";
            if (root->right)
                printTree(root->right);
            else
                std::cout << "NULL";
            std::cout << ")";
        }
    }
}

TreeNode* getSuccessor(TreeNode *node)
{
    TreeNode *current = node->right;
    TreeNode *parent = node;
    TreeNode *s = node;

    while (current != NULL)
    {
        parent = s;
        s = current;
        current = current->left;
    }
    if (s != node->right)
    {
        parent->left = s->right;
        s->right = node->right;
    }
    return s;
}

bool treeDelete(TreeNode *root, int key)
{
    TreeNode *current = root;
    TreeNode *parent = root;
    bool isLeftChild = true;

    while (current->key != key)
    {
        parent = current;
        if (key < current->key)
        {
            current = current->left;
            isLeftChild = true;
        }
        else
        {
            current = current->right;
            isLeftChild = false;
        }
        if (current == NULL)
            return false;
    }

    if (current->left == NULL && current->right == NULL)
    {
        if (current == root)
            root = NULL;
        else if (isLeftChild)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    else if (current->right == NULL)
    {
        if (isLeftChild)
            parent->left = current->left;
        else
            parent->right = current->left;
    }
    else if (current->left == NULL)
    {
        if (isLeftChild)
            parent->left = current->right;
        else
            parent->right = current->right;
    }
    else
    {
        TreeNode *successor = getSuccessor(current);
        if (current == root)
            root = successor;
        else if (isLeftChild)
            parent->left = successor;
        else
            parent->right = successor;
        successor->left = current->left;
    }
    return true;
}

//  Recursive traversal in direct order----------------------------------------------

void preOrderTravers(TreeNode *root)
{
    if (root)
    {
        std::cout << root->key << " ";
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

//  Recursive centered traversal----------------------------------------------------

void inOrderTravers(TreeNode *root)
{
    if (root)
    {
        inOrderTravers(root->left);
        std::cout << root->key << " ";
        inOrderTravers(root->right);
    }
}

//  Recursive traversal in reverse order---------------------------------------------

void postOrderTravers(TreeNode *root)
{
    if (root)
    {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        std::cout << root->key << " ";
    }
}

//  Building a balanced tree---------------------------------------------------------

TreeNode *balancedTree(int n)
{
    TreeNode *newNode;
    int x;
    int nL;
    int nR;
    if (n == 0)
    {
        return NULL;
    }
    else
    {
        fscanf(file, "%d", &x);
        nL = n / 2;
        nR = n - nL - 1;
        newNode = (TreeNode*) std::malloc(sizeof(TreeNode));
        newNode->key = x;
        newNode->left = balancedTree(nL);
        newNode->right = balancedTree(nR);
    }
    return newNode;
}

//  Binary search in the tree-------------------------------------------------------

bool binSearch(TreeNode *root, int value)
{
    if (root == NULL)
        return false;
    if (root->key == value)
        return true;

    TreeNode *current = root;
    while (current->key != value)
    {
        if (value < current->key)
            current = current->left;
        else
            current = current->right;

        if (current == NULL)
            return false;
    }
    return true;
}

int main()
{
    PrintHello();

    /*std::cout << "Building a binary search tree" << std::endl;
    TreeNode *tree = treeInsert(NULL, 10);
    treeInsert(tree, 8);
    treeInsert(tree, 19);
    treeInsert(tree, 5);
    treeInsert(tree, 9);
    treeInsert(tree, 16);
    treeInsert(tree, 21);
    printTree(tree);*/
    std::cout << std::endl;
    /*treeDelete(tree, 5);
    printTree(tree);
    std::cout << std::endl;
    treeDelete(tree, 19);
    printTree(tree);
    std::cout << std::endl;
    treeDelete(tree, 8);
    printTree(tree);*/
    std::cout << std::endl;

    /*std::cout << " Recursive traversal in direct order" << std::endl;
    preOrderTravers(tree);
    std::cout << std::endl << std::endl;

    std::cout << " Recursive centered traversal" << std::endl;
    inOrderTravers(tree);
    std::cout << std::endl << std::endl;

    std::cout << " Recursive traversal in reverse order" << std::endl;
    postOrderTravers(tree);
    std::cout << std::endl << std::endl;*/

    std::cout << " Building a balanced tree" << std::endl;
    TreeNode *tree = NULL;
    file = fopen("C:/Users/dracotail/codeblocks/homework_A12/balance.txt", "r");
    if (file == NULL)
    {
        std::cout << " Cannot open file" << std::endl;
        return 1;
    }
    const int count = 15;
    tree = balancedTree(count);
    fclose(file);
    printTree(tree);

    /*std::cout << " Binary search in the tree" << std::endl;
    std::cout << " (1 = true; 0 = false)" << std::endl;
    std::cout << " 8 in tree -> " << binSearch(tree, 8) << std::endl;
    std::cout << " 7 in tree -> " << binSearch(tree, 7) << std::endl;
    std::cout << " 5 in tree -> " << binSearch(tree, 5) << std::endl;
    std::cout << " 88 in tree -> " << binSearch(tree, 88) << std::endl;*/


    std::cout << std::endl;
    return 0;
}
