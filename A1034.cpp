#include <iostream>
#include <string>
#include <map>
using namespace std;
const int maxn = 2010;
const int INF = 1000000000;

map<int, string> inttostring;
map<string, int> stringtoint;
map<string, int> Gang;

int G[maxn][maxn] = {0};
int weight[maxn] = {0};
int N, K, numperson = 0;
bool vis[maxn] = {false}; //不加{} is WRONG!

int change(string str){
	if (stringtoint.find(str) != stringtoint.end())
	{
		return stringtoint[str];
	}else{
		stringtoint[str] = numperson;
		inttostring[numperson] = str;
		return numperson++; //return ++numperson is WRONG!
	}
}

void DFS(int nowvisit, int& head, int& nummember, int& totalvalue){
	nummember++; //成员数量加一
	vis[nowvisit] = true; //将当前访问结点标记为已访问
	if (weight[nowvisit] > weight[head])
	{
		head = nowvisit;
	}
	for (int i = 0; i < numperson; i++)
	{
		//枚举所有人
		if (G[nowvisit][i] > 0)
		{
			//如果当前结点可以到达i结点
			totalvalue += G[nowvisit][i]; //总边权加上当前结点到i结点的边权
			G[nowvisit][i] = G[i][nowvisit] = 0; //删除该边，防止总边权重复加和
			if (vis[i] == false)
			{
			//如果当前结点未被访问，递归调用DFS遍历该连通块
			DFS(i, head, nummember, totalvalue);
			}
		}
		
	}
}

void DFSTrave(){
	for (int i = 0; i < numperson; i++)
	{
		if (vis[i] == false)
		{
			int head = i, nummember = 0, totalvalue = 0; //定义头目，成员数，总边权并初始化为0
			DFS(i, head, nummember, totalvalue);
			if (nummember > 2 && totalvalue > K)
			{
				//找到Gang，建立map映射，key为头目string，value为成员数量int
				Gang[inttostring[head]] = nummember;
			}
		}
	}

}

int main(){
	cin >> N >> K;
	string str1, str2;
	int w;
	for (int i = 0; i < N; i++)
	{
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2);
		weight[id1] += w;
		weight[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}

	DFSTrave();
	cout << Gang.size() << endl;
	map<string, int>::iterator it; //定义迭代器
	for (it = Gang.begin(); it != Gang.end(); it++)
	{
		//输出对应的Gang头目名字和成员数量
		cout << it->first << " " <<it->second << endl; //是->，不是it.first()
	}

}