#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1010;
struct mouse
{
	int weight;
	int R;
}mouse[maxn];

int main(int argc, char const *argv[])
{
	int NP, NG, order;
	scanf("%d %d", &NP, &NG);
	for (int i = 0; i < NP; i++)
	{
		scanf("%d", &mouse[i].weight);
	}
	queue<int> q;
	for (int i = 0; i < NP; i++)
	{
		scanf("%d",&order);
		q.push(order);
	}

	int temp = NP;
	int group;

	while (q.size() != 1){
			if (temp % NG == 0)
			{
				group = temp / NG;
			}else if (temp % NG != 0)
			{
				group = temp / NG + 1;
			}

			for (int i = 0; i < group; i++)
			{
				int k = q.front();
			for (int j = 0; j < NG; j++)
			{
				if(i * NG + j >= temp)	break;
				int front = q.front();
				if (mouse[front].weight > mouse[k].weight)
				{
					k = front;
				}
				mouse[front].R = group + 1;
				q.pop();
			}
			q.push(k);
		}
		temp = group;
	}
	mouse[q.front()].R = 1;
	
	for (int i = 0; i < NP; i++)
	{
		printf("%d", mouse[i].R);
		if (i < NP - 1)
		{
			printf(" ");
		}
	}

	return 0;
}