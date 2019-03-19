#include <cstdio>
#include <stdlib.h>

struct node
{
	int data;
	node* next;
};

//创建列表
node* create(int Array[]){
	node *p, *pre, *head;
	head = new node; //新建头节点
	head->next = NULL; //头节点没有数据域，指针域初始化为NULL
	pre = head; //头节点创建完毕，此时前驱节点可设为头节点，并开始循环创建节点
	for (int i = 0; i < 6; i++)
	{
		p = new node;
		p->data = Array[i];
		p->next = NULL; //新节点指针域设为NULL
		pre->next = p; //p已创建完毕，可与前驱节点相连
		pre = p; //p节点为前驱节点，用于创建下一个节点，使循环继续
	}
	free(p); //?
	return head; //返回头节点指针
}

//查找元素
int search(node* head, int x){
	int count = 0;
	node* p;
	p = head->next;
	while(p != NULL){
		if (p->data == x)
		{
			count ++;
		}
			p = p->next;
	}
	return count;
}

//插入元素
//将x插入到以head为头节点的第pos个位置上
void insert(node *head, int pos, int x){
	node* p;
	p = new node;
	p = head;
	for (int i = 0; i < pos-1; i++)
	{
		p = p->next;
	}
	//此时p在pos前一个节点的位置
	node* q = new node;
	q -> data = x;
	q -> next = p -> next; //先让新节点指针域next指向p的后继节点，及原pos位置的节点
	p -> next = q; //再把原pos前一个节点指针指向新q
}

//删除元素
//删除以head为头节点的链表中所有数据域为x的节点
void del(node* head, int x){
	node* p = head -> next; //定义指针p为第一个节点	
	node* pre = head; //pre此时为头节点指针，头节点是p的前驱节点

	while(p != NULL){
		if (p -> data == x)
		{
			pre -> next = p -> next; //先让要删除节点的前驱节点指针域指向后继节点
			delete(p); //释放p节点内存，即删除
			p = pre -> next; //使p后移一位，以便遍历链表推出循环
		}else{
			//把pre和p都往后移一位
			pre = p;
			p = p -> next;

		}
	}
}

int main()
{
	int Array[6] = {5, 3, 6, 1, 2, 1,};
	node* L = create(Array); //调用create函数，并把头指针返回给L
	printf("%d\n", search(L, 1));//查找
	insert(L, 3, 4);//将4插入到以L为头节点指针的第3个位置上
	del(L, 6); //删除所有数据域为6的节点

	L = L->next; //第一个节点开始有data，可输出
	while(L != NULL){
		printf("%d\n", L->data);
		L = L->next;
	}

//2 5 3 4 1 2 1

	return 0;
}