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
		//�������ڵ�
		Root = BuyTreeNode(arr[*index]);
		
		//����������
		//�ݹ���������
		//һ������
		(*index)++;
		Root->left = BinTreeCreat(arr, size,index);
		

		//����������
		(*index)++;
		Root->right= BinTreeCreat(arr, size,index);
		//�ݹ����???  index<size	

	}
	
	return Root;

}


//����������
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
		//����ڵ����Ҷ��
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