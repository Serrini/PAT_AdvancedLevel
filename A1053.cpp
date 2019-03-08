#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int N, M, S;
int path[maxn];

struct NODE
{
	int weight;
	vector<int >child;
}node[maxn];

 bool cmp(int a, int b){
	return node[a].weight > node[b].weight;
}

void DFS(int index, int numnode, int sum){
	//index为当前结点，numnode为path上的结点个数，sum为当前权值和
	if(sum > S) return;
	if(sum == S){
		if(node[index].child.size() !=0 ) return;
		//还未到叶子结点，不输出，直接返回
		//到达叶子结点，输出path路径存储的结点权值
		for (int i = 0; i < numnode; i++)
		{
			printf("%d", node[path[i]].weight);
			if(i != numnode - 1) printf(" ");
			else printf("\n");
		}
		return; //返回
	}

	for (int i = 0; i < node[index].child.size(); i++)
	{
		//枚举当前结点所有的子结点
		int child = node[index].child[i];
		path[numnode] = child;
		//numnode++;
		//sum += node[child].weight;
		//DFD(child, numnode, sum);
		//is WRONG!
		DFS(child, numnode+1, sum+node[child].weight); //递归调用DFS函数

	}
}

int main(){
	scanf("%d%d%d", &N, &M, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &node[i].weight);
	}
	int ID, K;
	int child;
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &ID, &K);
		for (int j = 0; j < K; j++)
		{
			scanf("%d", &child);
			node[ID].child.push_back(child);
		}
		sort(node[ID].child.begin(), node[ID].child.end(), cmp);
	}

	path[0] = 0;
	DFS(0, 1, node[0].weight);

	return 0;
}