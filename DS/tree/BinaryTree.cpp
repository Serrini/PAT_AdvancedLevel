#include <iostream.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "stack.h"									//首先到当前目录下找stack.h

template<class T>
void BinaryTree<T>::destroy(BinaryTree<T> *& subTree){
	//私有函数：若指针subtree不为空，则删除根为subtree的子树
	//删除结点
	if (subTree != NULL)
	{
		destroy(subTree -> lchild);
		destroy(subTree -> rchild);
		delete subTree;
	}
};

template<class T>
BinaryTree<T> *parent(BinaryTree<T> *subTree; BinaryTree<T> *current){
	//私有函数：从结点subtree开始寻找结点currenr的父节点，找到则返回父结点地址，否则函数返回NULL
	//返回父结点
	if (subTree == NULL)
	{
		return NULL;
	}
	if (subTree -> lchild == current || subTree -> rchild == current)
	{
		return subTree;
	}
	BinaryTree<T> *p;
	p = parent(subTree -> lchild, current);

	if (p != NULL)
	{
		return p;
	}else{
		return parent(subTree -> rchild, current);
	}
};

template<class T>
void BinaryTree<T>::traverse(BinaryTree<T> *subtree, ostream& out){
	//私有函数：搜索并输出根为subtree的二叉树
	if (subtree != NULL)
	{
		out << subtree -> data << ' ';
		traverse(subtree -> lchild, out);
		traverse(subtree -> rchild, out);
	}
};

template<class T>
istream& operator >> (istream& in, BinaryTree<T> &Tree){
	//重载函数：输入并建立一颗二叉树Tree，in是输入流
	CreateBinTree(in, Tree.root);
	return in;
};

templat<class T>
ostream& operator << (ostream& out, BinaryTree<T> &Tree){
	//重载函数：输出一颗二叉树Tree，out是输出流
	out << "二叉树的前序遍历/n";
	Tree.traverse(Tree.root, out);
	out << endl;
	return out;
};

//输入广义表建立二叉树
void BinaryTree<T>::CreateBinTree(istream& in, BinaryTreeNode<T> *& BT){
	//从输入流in输入二叉树的广义表表示建立对应的二叉链表
	Stack<BinaryTreeNode<char>* >s;
	BT = NULL; 								//置空二叉树
	BinaryTree<char> *p, *t, int k;
	char ch;
	in >> ch;								//从in顺序读入一个字符
	while(ch != RefValue){
		//逐个字符处理
		switch(ch){
			default:
				p = new BinTreeNode(ch);	//新建一个结点，结点值为ch
				if (BT == NULL)
				{
					BT = p;					//如果数为空则p为根节点
				}else if (k == 1)
				{
					s.getTop(t);
					t -> lchild = p;		//链入*t的左孩子
				}else{
					s.getTop(t);
					t -> rchild = p;		//链入*t的右孩子
				}
			case'(':
				s.push(p); k = 1; break;	//进入子树
			case')':
				s.pop(t); break;			//退出子树
			case',':
				k = 2; break;
		}
	}
};

template<class T>
void BinaryTree<T>::preorder(BinaryTreeNode<T> *subtree,
				 void( *visit)(BinaryTree) *p){
	//前序遍历
	if (subtree != NULL)
	{

		//subtree == NULL 是递归终止条件
		visit(subtree);
		preorder(subtree -> lchild, visit);
		preorder(subtree -> rchild, visit);
	}

};

template<class T>
void BinaryTree<T>::inorder(BinaryTreeNode<T> *subtree,
				 void( *visit)(BinaryTree<T> *p)){
	//中序遍历
	if (subtree != NULL)
	{
		//subtree == NULL 是递归终止条件
		inorder(subtree -> lchild, visit);
		visit(subtree);
		inorder(subtree -> rchild, visit);
	}
};

template<class T>
void BinaryTree<T>::postorder(BinaryTreeNode<T> *subtree,
				 void( *visit)(BinaryTree<T> *p)){
	//后序遍历
	if (subtree != NULL)
	{
		//subtree == NULL 是递归终止条件
		postorder(subtree -> lchild, visit);
		postorder(subtree -> rchild, visit);
		visit(subtree);
	}
};

template<class T>
int BinaryTree<T>::size(BinaryTreeNode<T> *subtree){
	//私有函数：计算以*subtree为根结点的二叉树的所有结点数
	if (subtree == NULL)
	{
		//递归边界
		return 0;
	}else{
		return 1+size(subtree -> lchild)+size(subTree -> rchild);
	}

};

template<class T>
int BinaryTree<T>::height(BinaryTreeNode<T> *subtree){
	//私有函数：计算以*subtree为根结点的二叉树的高度或深度
	if (subtree == NULL)
	{
		//递归边界
		return 0;
	}else{
		int i = height(subtree -> lchild);
		int j = height(subtree -> rchild);
		return((i>j) ? i+1: j+1;)
	}
};











