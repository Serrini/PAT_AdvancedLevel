#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 1010;
int arr[maxn];
stack<int> st;
int main(int argc, char const *argv[])
{
	int M, N, T;
	scanf("%d %d %d", &M, &N, &T);
	while(T--){
		while(!st.empty()){
			st.pop();
		}
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &arr[i]);
		}
		int current = 1;
		bool flag = true;
		for (int i = 1; i <= N; i++)
		{
			st.push(i);
			if (st.size() > M)
			{
				flag = false;
				break;
			}
			while(!st.empty() && st.top() == arr[current]){
				st.pop();
				current++;
			}
		}
		if (st.empty() && flag)
		{
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}