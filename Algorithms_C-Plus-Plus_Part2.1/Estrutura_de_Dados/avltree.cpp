#include <iostream>
#include <queue>

using namespace std;

typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
}node;

int max(int a, int b)
{
    return a > b ? a : b;
}

//Returns a new Node

node *creatNode(int data)
{
    node *nn = new node();
    nn->data = data;
    nn->height = 0;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

// Returns height of tree

int height(node *root)
{
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Returns difference between height of left and rigth subtree

int getBalance(node *root)
{
    return height(root->left) - height(root->right);
}

// Reurns Node after Rigth Rotation

node *rigthRotate(node *root)
{
    node *t = root->left;
    node *u = t->right;
    t->right = root;
    root->left = u;
    return t;
}

// Returns Node after Left Rotation

node * leftRotate(node *root)
{
    node *t = root->right;
    node *u = t->left;
    t->left = root;
    root->right = u;
    return t;
}

// returns node with minimum value in the tree

node *minValue(node *root)
{
    if(root->left == NULL)
        return root;
    return minValue(root->left);
}

// balanced insertion

node *insert(node *root, int item)
{
    node *nn = creatNode(item);
    if (root == NULL)
        return nn;
    if (item < root->data)
        root->left = insert(root->left, item);
    else
        root->right = insert(root->right, item);
    int b = getBalance(root);
    if(b > 1)
    {
        if(getBalance(root->left) < 0)
            root->left = leftRotate(root->left);
        return rigthRotate(root);
    }
    else if(b < -1)
    {
        if(getBalance(root->right) > 0)
            root->right = rigthRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

//balanced deletion

node *dleteNode(node *root, int key)
{
    if(root == NULL)
        return root;
    if(key < root->data)
        root->left = dleteNode(root->left, key);
    else if(key > root->data)
        root->right = dleteNode(root->right, key);
    
    else
    {
        // Node to be deleted is leaf node or have only one Child
        if(!root->right)
        {
            node *temp = root->left;
            delete (root);
            root = NULL;
            return temp;
        }
        else if (!root->left)
        {
            node *temp = root->right;
            delete (root);
            root = NULL;
            return temp;
        }
        // Node to be deleted have both left and rigth subtrees
        node *temp = minValue(root->right);
        root->data = temp->data;
        root->right = dleteNode(root->right, temp->data);
    }
    // Balancing Tree after deletion
    return root;
}

//LevelOrder (Breadth First Search)

void levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        cout << root->data << " ";
        q.pop();
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
    }
}

int main()
{
    // Testing AVL Tree
    node *root = NULL;
    int i;
    for (i = 1; i <= 7; i++)
        root = insert(root, i);
    cout << "LevelOrder: ";
    levelOrder(root);
    root = dleteNode(root, 1); // Deleting key with value 1
    cout << "\nLevelOrder: ";
    levelOrder(root);
    root = dleteNode(root, 4); // Deleting key with value 4
    cout << "\nLevelOrder: ";
    levelOrder(root);
    root = dleteNode(root, 7);
     cout << "\nLevelOrder: ";
    levelOrder(root);
    cout << endl;
    return 0;
}