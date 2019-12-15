#include<iostream>
using namespace std;
typedef char TypeData;

typedef struct Tree
{
	TypeData _val;
	Tree* left;
	Tree* right;
}BiTreeNode;
//BiTreeNode* Tree;
void CreateBiTree(BiTreeNode** T)
{//
	TypeData val;
	scanf("%c", &val);

	if (val == '#')
	{
		*T = NULL; //null表示为空枝
	}
	else
	{
		*T = (BiTreeNode*)malloc(sizeof(BiTreeNode));
		(*T)->_val = val;
		CreateBiTree(&(*T)->left);
		CreateBiTree(&(*T)->right);
	}
}

void InOrderTravel(BiTreeNode* T)
{
	if (T == NULL)
		return;
	InOrderTravel(T->left);
	printf("%c ", T->_val);
	InOrderTravel(T->right);
}
int main()
{
	//注意如果要在外面对二叉树的节点进行更改，需要传二级指针，如果只进行访问，只需传一级指针即可
	BiTreeNode* T;
	T = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	CreateBiTree(&T);
	InOrderTravel(T);
	return 0;
}