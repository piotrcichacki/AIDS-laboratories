#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node* parent;
};

Node* newNode(Node* parent, int key)
{
    Node* node = new Node[1];

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;

    return node;
}

void insertElement(Node* root, int key)
{
    if (root->key == -1)
    {
        root->key = key;
        return;
    }
    else
    {
        if (key <= root->key)
        {
            if (root->left == NULL)
            {
                root->left = newNode(root, key);
                return;
            }
            else
            {
                insertElement(root->left, key);
                return;
            }
        }
        else
        {
            if (root->right == NULL)
            {
                root->right = newNode(root, key);
                return;
            }
            else
            {
                insertElement(root->right, key);
                return;
            }
        }
    }
}

void findElement(Node* root, int key, int* isElement)
{
    if (root->key == key) *isElement = 1;

    if (root->left != NULL && root->right != NULL)
    {
        if (key < root->key)
            findElement(root->left, key, isElement);
        else
            findElement(root->right, key, isElement);
    }
    else
    {
        if (root->left != NULL)
            findElement(root->left, key, isElement);
        if (root->right != NULL)
            findElement(root->right, key, isElement);
    }
}

Node* findElement(Node* root, int key)
{
    if (root->key == key) return root;

    if (root->left != NULL && root->right != NULL)
    {
        if (key < root->key)
            findElement(root->left, key);
        else
            findElement(root->right, key);
    }
    else
    {
        if (root->left != NULL)
            findElement(root->left, key);
        if (root->right != NULL)
            findElement(root->right, key);
    }

    return NULL;

}

int findMinimum(Node* root)
{
    Node* tmp = root;
    int minimum;
    while (tmp->left != NULL)
        tmp = tmp->left;

    minimum = tmp->key;
    tmp = NULL;
    delete[] tmp;
    return minimum;
}

int findMaximum(Node* root)
{
    Node* tmp = root;
    int maximum;
    while (tmp->right != NULL)
        tmp = tmp->right;

    maximum = tmp->key;
    tmp = NULL;
    delete[] tmp;
    return maximum;
}

Node* findMinimumNode(Node* root)
{
    Node* tmp = root;

    while (tmp && tmp->left != NULL)
        tmp = tmp->left;

    return tmp;
}


Node* deleteElement(Node* root, int key)
{
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteElement(root->left, key);

    else if (key > root->key)
        root->right = deleteElement(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            Node* tmp = root->right;
            delete[] root;
            return tmp;
        }
        else if (root->right == NULL)
        {
            Node* tmp = root->left;
            delete[] root;
            return tmp;
        }

        Node* tmp = findMinimumNode(root->right);
        root->key = tmp->key;
        root->right = deleteElement(root->right, tmp->key);
    }

    return root;
}

void freeTree(Node* root)
{
    if (root->left != NULL)
    {
        freeTree(root->left);
        root->left = NULL;
    }
    if (root->right != NULL)
    {
        freeTree(root->right);
        root->right = NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        root->parent = NULL;
        delete[] root;
    }
}


int main()
{
    int key, isElement = 0;
    char input;
    Node* root = newNode(NULL, -1);

    cin >> input;

    while (input != 'q')
    {
        switch (input)
        {
        case '+':
            cin >> key;
            insertElement(root, key);
            break;

        case '-':
            cin >> key;
            root = deleteElement(root, key);
            break;

        case '?':
            cin >> key;
            findElement(root, key, &isElement);
            cout << isElement << endl;
            isElement = 0;
            break;

        case 'm':
            cout << findMinimum(root) << endl;
            break;

        case 'M':
            cout << findMaximum(root) << endl;
            break;
        }

        cin >> input;
    }

    freeTree(root);

    return 0;
}