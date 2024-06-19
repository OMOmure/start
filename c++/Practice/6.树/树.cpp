#include<iostream>
using namespace std;

typedef int BTDataType;
typedef struct SinaryTreeNode
{
    struct SinaryTreeNode* Lnode;
    struct SinaryTreeNode* Rnode;
    BTDataType _data;
}BiTree;

BiTree* CreateNode(BTDataType data)
{
    BiTree* newNode = new BiTree();
    newNode->Lnode = NULL;
    newNode->Rnode = NULL;
    newNode->_data = data;
    return newNode;
}

//搜索二叉树
BiTree* InsertNode(BiTree* root, BTDataType data)
{
    if (root == NULL) // 如果根节点为空，直接创建一个新节点作为根节点
        return CreateNode(data);
    
    if (data < root->_data) // 如果插入的数据小于当前节点的数据，插入到左子树
        root->Lnode = InsertNode(root->Lnode, data);
    else if (data > root->_data) // 如果插入的数据大于当前节点的数据，插入到右子树
        root->Rnode = InsertNode(root->Rnode, data);
    
    return root;
}

//pre find 
void PreOrderTraverse(BiTree *T)
{
    if(T == NULL) return;
    cout<<T->_data<<"  ";
    PreOrderTraverse(T->Lnode);
    PreOrderTraverse(T->Rnode);
}

void InOrderTraverse(BiTree *T)
{
    if(T == NULL) return;
    InOrderTraverse(T->Lnode);
    cout<<T->_data<<"  ";
    InOrderTraverse(T->Rnode);
}

void PostOrderTraverse(BiTree *T)
{
    if(T == NULL) return;
    PostOrderTraverse(T->Lnode);
    PostOrderTraverse(T->Rnode);
    cout<<T->_data<<"  ";
}

int TreeSize(BiTree *root)
{
    int size = 0;
    if(root == NULL)    return 0;
    else    size++;
    TreeSize(root->Lnode);
    TreeSize(root->Rnode);
    return size;
}

int TreeLeafSize(BiTree *root)
{
    if(root==NULL)  return 0;
    if(root->Lnode==NULL &&root->Rnode==NULL)
    return 1;

    return TreeLeafSize(root->Lnode)+TreeLeafSize(root->Rnode);
}

void PrintLeaves(BiTree *BT)
{
    if(BT)
    {   
        if(!BT->Lnode&& !BT->Rnode)
        cout<< BT->_data<<"  ";
        PrintLeaves(BT->Lnode);
        PrintLeaves(BT->Lnode); 
    }
}

int main()
{
    BiTree* root = NULL;

    // 在树中插入节点
    root = InsertNode(root, 50);
    InsertNode(root, 30);
    InsertNode(root, 20);
    InsertNode(root, 40);
    InsertNode(root, 70);
    InsertNode(root, 60);
    InsertNode(root, 80);

    // 测试各个函数
    cout << "PreOrderTraverse: ";
    PreOrderTraverse(root);
    cout << endl;

     cout << "InOrderTraverse: ";
    InOrderTraverse(root);
    cout << endl;

    cout << "PostOrderTraverse: ";
    PostOrderTraverse(root);
    cout << endl;

    cout << "TreeSize: " << TreeSize(root) << endl;

    cout << "TreeLeafSize: " << TreeLeafSize(root) << endl;

    cout << "Leaves: ";
    PrintLeaves(root);
    cout << endl;

    return 0;
}