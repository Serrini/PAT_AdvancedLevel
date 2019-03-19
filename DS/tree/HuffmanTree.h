#include "heap.h"
const int defaultsize = 20; //缺省权值集合大小
struct HuffmanNode
{
	//树结点的类定义
	float data;                                                 //结点数据
	HuffmanNode *lchild, *rchild, *parent;
	HuffmanNode():lchild(NULL), rchild(NULL), parent(NULL){}    //构造函数
	HuffmanNode(float elem, HuffmanNode* left = NULL,
		HuffmanNode* right = NULL, HuffmanNode* pr = NULL)
		: data(elem), lchild(left), rchild(right), parent(pr){} //构造函数
	bool operator <= (HuffmanNode& R){return data <= R.data;}
	bool operator > (HuffmanNode& R){return data > R.data;}
};

class HuffmanTree
{
//Huffman树类定义
public:
	HuffmanTree(float w[], int n);                              //构造函数
	~HuffmanTree(){delete Tree(root);}                          //析构函数

protected:
	HuffmanTree* root;                                          //Huffman树的根
	void deleteTree(HuffmanNode* t);                            //删除以t为根的子树
	void mergeTree(HuffmanNode& ht1, HuffmanNode& ht2,
		 HuffmanNode*& parent){};								//合并二叉树
	
};