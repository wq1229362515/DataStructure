#include "Tree.h"
#include<stdio.h>
#include <assert.h>
#include <malloc.h>
#include<string.h>
BTNode* BuyTreeNode(BTDataType data){
	BTNode * TreeNode = (BTNode*)malloc(sizeof(BTNode));
	if (TreeNode == NULL){
		assert(0);
	}
	TreeNode->data = data;
	TreeNode->left = NULL;
	TreeNode->right = NULL;
	return TreeNode;
}


BTNode * BinTreeCreat(BTDataType *arr, int size,int* index){
	BTNode *Root = NULL;
	if (*index < size &&  '#'!= arr[*index]){
		//创建根节点
		Root = BuyTreeNode(arr[*index]);
		
		//根的左子树
		//递归起来创建
		//一个索引
		(*index)++;
		Root->left = BinTreeCreat(arr, size,index);
		

		//根的右子树
		(*index)++;
		Root->right= BinTreeCreat(arr, size,index);
		//递归出口???  index<size	

	}
	
	return Root;

}


//后序销毁树
void BinTreeDestroy(BTNode** root){
	if (*root){
		BinTreeDestroy(&(*root)->left);
		BinTreeDestroy(&(*root)->right);
		free(*root);
		(*root) = NULL;
	}
}

int  GetBinTreeLeaf(BTNode *root){
	if (NULL == root){
		return 0;
	}
	if (root->left == NULL &&root->right){
		//这个节点就是叶子
		return 1;
	}
	return GetBinTreeLeaf(root->left) + GetBinTreeLeaf(root->right) + 1;
}

void TestTree(){
	BTDataType * str = "ABD###CE##F";
	int index = 0;
	BTNode* root = BinTreeCreat(str,strlen(str),&index);
}
int main(){

	TestTree();
	return 0;
}