#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TreeDataType char

/**二叉树数据结构定义**/
typedef struct BiTreeNode {
	char data;
	struct BiTreeNode *left;
	struct BiTreeNode *right;
} BiTreeNode, *BiTree;

/**二叉树的建立--按照先序方式建立--插入**/
void CreateBiTree(BiTree *T);

/**先序遍历  根左右**/
void PreOrderTravel(BiTree T);

/**中序遍历 左根右**/
void InOrderTravel(BiTree T);

/**后序遍历 左右根**/
void TailOrderTravel(BiTree T);