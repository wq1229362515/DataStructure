#pragma once
typedef char BTDataType;
typedef struct BinTreeNode {
	
	BTDataType data;
	struct BinTreeNode *left;
	struct BinTreeNode *right;
}BTNode;

BTNode * BinTreeCreat(BTDataType *arr, int size,int* index);
void BinTreeDestroy(BTNode** root);
int  GetBinTreeSize(BTNode *root);
int  GetBinTreeLeaf(BTNode *root);

