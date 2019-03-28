#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1010;
char Next[maxn] = {0};
char text[maxn] = {0};
char pattern[maxn] = {0};

void getNext(char s[], int len){
	int j = -1; //初始化j
	Next[0] = -1; //初始化Next[]数组
	for (int i = 0; i < len; i++)
	{
		while(j!=-1 && s[i]!=s[j+1]){
			j = Next[j];
			//不断令j=next[j]，直到j回退到-1或是s[i]==s[j+1]
		}
		if (s[i] == s[j+1])
		{
			//如果s[i]==s[j+1]，则Next[i]=j+1
			j++;
		}
		Next[i] = j;
	}
}

bool KMP(char text[], char pattern[]){
	int n = strlen(text);
	int m = strlen(pattern);
	getNext(pattern, m); //计算pattern的next数组
	int j = -1; //初始化j为-1
	for (int i = 0; i < n; i++)
	{
		while(j!=-1 && text[i] != pattern[j+1]){
			j = Next[j];
			//不断回退，直到j回退到-1或者text[i]==pattern[j+1]
		}
		if (text[i] == pattern[j+1])
		{
			j++; //如果匹配成功，则令j++
		}
		if (j == m-1)
		{
			//完全匹配，是子串
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	cin >> text;
	cin >> pattern;

	printf("%d\n", KMP(text, pattern));
	return 0;
}