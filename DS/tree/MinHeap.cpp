#include <iostream.h>
#include "MinHeap.h"

template <class E>
MinHeap<E>::MinHeap(int sz){
	maxheapsize = (defaultsize < sz) ? sz: defaultsize;
	heap = new E[maxheapsize];
	if (heap == NULL)
	{
		cerr<<"堆内存分配失败！"<<endl; exit(1);
	}
	currentsize = 0;
};

template <class E>
MinHeap<E>::MinHeap(E arr[], int n){
	maxheapsize = (defaultsize < n) ? n: defaultsize;
	heap = new E[maxheapsize];
	if (heap == NULL)
	{
		cerr<<"堆内存分配失败！"<<endl; exit(1);
	}
	for (int i = 0; i < n; i++)
	{
		heap[i] = arr[i];
	}
	currentsize = n; 									//n为结点总数，从0开始，最大编号为n-1；
	int currentpos = (currentsize - 2)/2;				//起始位置要求2x+1<=n-1,n为结点总数
	while(currentpos >= 0){								//自下而上逐步扩大形成堆
		siftdown(currentpos, currentsize-1);			//局部自上向下下滑调整，编号最大为currentsize-1
		currentpos--;
	}
};

template<class E>
void MinHeap<E>::siftdown(int start, int m){			//最小堆的下滑调整算法
//私有函数：从结点start到m为止，自下向上比较，如果子女小于父结点，则上浮，继续向下层比较，局部调整为最小堆
	int i = start;
	int j = 2*i+1;
	E temp =. heap[i];
	while(j <= m){										//检查是否到最后位置
		if (j < m && heap[j] > heap[j+1])				//让j指向子女中小的那个
		{
			j++;
		}
		if (temp <= heap[j])							//如果父结点小则不作调整
		{
			break;
		}else{
			heap[i] = heap[j];							//否则小者上移，ij下降
			i = j;
			j = 2*j+1;									//j=2*i+1 ??
		}
	}
	heap[i] = temp;										//回放temp中暂存的元素
};

template<class E>
void MinHeap<E>::siftup(int start){
//私有函数：从结点start开始到结点0为止，自下向上比较，如果子女小于父结点则交换，将集合重新调整为最小堆
//关键码比较符“<=”在模版E中定义
	int j = start;
	int i = (j-1)/2;									//i为j的父结点
	E temp = heap[j];
	while(j > 0){
		if (heap[i] <= temp)
		{
			//父结点值小于子女结点，不需要调整
			break;
		}else{
			heap[j] = heap[i];							//ij值交换
			j = i;										//ij交换
			i = (i-1)/2;								//i=(j-1)/2 ??
		}
	}
	heap[j] = temp;										//回送
};

template<class E>
bool MinHeap<E>::insert(const E& x){
//公共函数：将x插入到最小堆中去
	if (currentsize == maxheapsize)
	{
		//堆满
		cerr<<"Heap Full"<<endll;
		return flase;
	}
	heap[currentsize] = x;								//插入x到堆中去
	siftup[currentsize];								//想上调整
	currentsize++;										//堆计数加一
	return true;
}；

template<class E>
bool MinHeap<E>::removemin(const E& x){
	if (!currentsize)
	{
		//堆为空，返回false
		cerr<<"Heap Empty"<<endl;
		return flase;
	}
	x = heap[0];										//删除堆顶元素，赋值给x
	heap[0] = heap[currentsize-1];						//最后元素填补到根结点
	currentsize--;										//当前结点树减1
	siftdown(0, currentsize-1);							//自上向下调整为堆
	return true;										//返回最小元素
};












