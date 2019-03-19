#include <iostream.h>
#include "HuffmanTree.h"
#include "MinHeap.cpp" //.h or .cpp ???
HuffmanTree::HuffmanTree(float w[], int n){
	MinHeap hp;											//使用最小堆存放森林
	HuffmanNode* parent, first, second, work;
	for (int i = 0; i < n; i++)
	{
		//森林各树初始化
		work.data = w[i];
		work.lchild = NULL;
		work.rchild = NULL;
		work.parent = NULL;
		hp.insert(work);								//插入到最小堆中去
	}
	for (int i = 0; i < n-1; i++)
	{
		//做n-1趟，形成HuffmanTree
		hp.removemin(first);							//选择根的权值最小的树
		hp.removemin(second);							//选择根的权制次小的树
		merge(first, second, parent);					//合并
		hp.insert(*parent);								//重新插入到最小堆中去
	}
	root = parent;										//建立根结点
}

void HuffmanTree::mergeTree(HuffmanNode& bt1,
		HuffmanNode& bt2, HuffmanNode*&parent){			//合并两棵树
	parent = new HuffmanNode;							//新建父结点，合并后作为bt1和bt2的共同根结点
	parent -> lchild = &bt1;
	parent -> rchild = &bt2;
	parent -> data = bt1.root -> data + bt2.root->data;
	bt1.root -> parent = bt2.root -> parent = parent;
};