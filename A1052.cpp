#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct NODE
{
	int address;
	int data;
	int next;
	bool flag;
}node[maxn];

bool cmp(NODE a, NODE b)	//注意不是node
{
	if (a.flag == false || b.flag == false)
	{
		//只要a和b出现一个无效节点，就把它排到后面去
		return a.flag > b.flag;
	}else{
		//二级排序,按照data数值从小到大排序
		return a.data < b.data;
	}
}

int main(){
	for (int i = 0; i < maxn; i++)
	{
		//初始化所有flag为false
		node[i].flag = false;
	}
	int N, head;
	scanf("%d %d", &N, &head);

	int address;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &address);
		node[address].address = address;
		scanf("%d %d", &node[address].data, &node[address].next);
	}

	//连接有效节点，并将flag改为true
	int count = 0, p = head;
	while(p != -1){
		count ++;
		node[p].flag = true;
		p = node[p].next;//使循环继续下去
	}

	if (count == 0)
	{
		//有0个有效节点时
		printf("0 -1\n");
	}else{
		//对有效节点进行排序
		sort(node, node + maxn, cmp);
		printf("%d %05d\n", count, node[0].address);
		for (int i = 0; i < count; i++)
		{
			if (i != count - 1)
			{
				printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
			}else{
				printf("%05d %d -1\n", node[i].address, node[i].data);
			}
		}
	}

}