#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
const LL P = 10000019;
const int maxn = 1010;
LL powp[maxn];
LL H1[maxn] = {0};
LL H2[maxn] = {0};

vector<pair<int, int> > pr1, pr2;

void init(int len){
	powp[0] = 1;
	for (int i = 1; i < len; i++)
	{
		powp[i] = (powp[i-1] * P) % MOD;
	}
}

void calH(string &str, LL H[]){
	H[0] = str[0];
	for (int i = 1; i < str.length(); i++)
	{
		H[i] = (H[i-1] * P + str[i]) % MOD;
	}
}

int calsinglesubH(LL H[], int i, int j){
	if (i == 0)
	{
		return H[j];
	}
	return ((H[j] - H[i-1] * powp[j-i+1]) % MOD + MOD) % MOD;

}

void calsubH(LL H[], int len, vector<pair<int, int> >&pr){
	for (int i = 0; i < len; i++)
	{
		for (int j = i; j < len; j++)
		{
			int hashvalue = calsinglesubH(H, i, j);
			pr.push_back(make_pair(hashvalue, j-i+1));
		}
	}
}

int getMax(){
	int ans = 0;
	for (int i = 0; i < pr1.size(); i++)
	{
		for (int j = 0; j < pr2.size(); j++)
		{
			if (pr1[i].first == pr2[j].first)
			{
				ans = max(ans, pr1[i].second);
			}
		}
	}
	return ans;
}


int main(int argc, char const *argv[])
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	init(max(str1.length(), str2.length()));
	calH(str1, H1);
	calH(str2, H2);
	calsubH(H1, str1.length(), pr1);
	calsubH(H2, str2.length(), pr2);
	printf("%d\n", getMax());
	return 0;
}