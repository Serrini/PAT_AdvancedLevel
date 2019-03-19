#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream.h>
template<class T>
struct BinTreeNode
{
	//二叉树节点类的定义
	T data; //数据域
	BinTreeNode<T> *lchild, *rchild; //lchild, rchild是指针，链域
	BinTreeNode(): lchild(NULL), rchild(NULL){} //构造函数
	BinTreeNode(T x, BinTreeNode<T> *l = NULL, BinTreeNode<T> *r = NULL) //构造函数
		:data(x), lchild(l), rchild(r){}
};

template<class T>
class BinaryTree
{
public:
	BinaryTree(): root(NULL){} //构造函数
	BinaryTree(T value): RefValue(value), root(NULL){} //构造函数
	BinaryTree(BinaryTree<T>& s); //复制构造函数
	~BinaryTree(){delete(root);} //析构函数
	
	bool isempty(){return (root == NUll) ? true:false;} //判断树是否为空
	BinaryTree<T> *parent(BinaryTree<T> *current) //返回父节点
		{return (current != NULL || root == current) ? 
			NULL:parent(root, current);}
	BinaryTree<T> *rchild(BinaryTree<T> *current) //返回右子女
		{return (current != NULL) ? current->rchild:NULL;}
	BinaryTree<T> *lchild(BinaryTree<T> *current) //返回左子女
		{return (current != NULL) ? current->lchild:NULL;}

	int height(){return height(root);} //返回树高度
	int size(){return size(root);} //返回结点数

	BinaryTree<T> *getroot() const {return root;} //取根结点
	void preorder(void(*visit)(BinaryTree<T> *p))
		{preorder(root, visit);}
	void inorder(void(*visit)(BinaryTree<T> *p))
		{inorder(root, visit);}
	void postorder(void(*visit)(BinaryTree<T> *p))
		{postorder(root, visit);}
	void levelorder(void(*visit)(BinaryTree<T> *p))
		{levelorder(root, visit);}

	int insert(const T& item);
	BinaryTree<T> *find(T& item)const;

protected:
	BinaryTree<T> *root; //二叉树的根指针
	T RefValue; //数据读入停止标志
	void CreateBinTree(istream& in, BinaryTree<T> *& subTree); //从文件读入建树
	bool insert(BinaryTree<T> *& subTree, const T& x); //插入
	void destroy(BinaryTree<T> *& subTree); //删除
	bool Find(BinaryTree<T> *& subTree, const T& x)const; //查找
	BinaryTree<T> *copy(BinaryTree<T> *origin); //复制

	int height(BinaryTree<T> *subTree); //返回树高度
	int size(BinaryTree<T> *subTree); //返回树结点数

	BinaryTree<T> *parent(BinaryTree<T> *subTree; BinaryTree<T> *current); //返回父结点
	BinaryTree<T> *find(BinaryTree<T> *subTree, const T& x)const; //搜寻x

	void traverse(BinaryTree<T> *subTree, ostream& out); //	前序遍历输出
	void preorder(BinaryTree<T>& subTree,
				 void( *visit)(BinaryTree<T> *p)); //前序遍历
	void inorder(BinaryTree<T>& subTree,
				 void( *visit)(BinaryTree<T> *p)); //中序遍历
	void postorder(BinaryTree<T>& subTree,
				 void( *visit)(BinaryTree<T> *p)); //后序遍历

	friend istream& operator >> (istream& in, BinaryTree<T> & Tree); //操作符重载，输入
	friend ostream& operator << (ostream& out, BinaryTree<T> & Tree); //操作符重载，输出

};

#endif











