#ifndef MINHEAP_H
#define MINHEAP_H

#define DefaultSize 10;
enum bool{flase, true}
template <class E>
class MinHeap: public PQueue<E>{							//继承关系
public:
	MinHeap(int sz = defaultsize);							//构造函数，建立空堆
	MinHeap(E arr[], int n);								//构造函数，通过一个数组建堆
	~MinHeap(delete []heap); 								//析构函数
	bool insert(const E& x); 								//将x插入到堆中去
	bool removemin(const E$ x); 							//删除堆顶上的最小元素
	bool isempty()const 									//判断是否为空，空为1不空为0
		{return (currentsize == 0) ? true: flase;} 
	bool isfull()const										//判断是否已满，满为1不满为0
		{return (currentsize == maxheapsize) ? true: flase;}
	void makeempty(){currentsize = 0;} 						//置空堆

private:
	E* heap;
	int currentsize;
	int maxheapsize;
	void shiftdown(int start, int m);
	void shiftup(int start);
}

#endif