#include <iostream>
//#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;
struct node
{
	double num;
	char op;
	bool flag;//flag为true为数字，false则为操作符
};

string str;
stack<node> s;//操作符栈
queue<node> q;//后缀表达式的队列
map<char, int>op;//key是操作符，value是优先级

void change(){
	double num;
	node temp;

	for (int i = 0; i < str.length(); )
	{
		if (str[i] >= '0' && str[i] <= '9')//如果是数字
		{
			temp.flag = true;
			temp.num = str[i]-'0';//转换成数字，且为第一位
			while(i < str.length() && str[i] >= '0' && str[i] <= '9')//while循环计算得到num操作数
			{
				temp.num = temp.num * 10 + (str[i] - '0');
				i++;
			}
			q.push(temp);//将操作数加入后缀表达式的队列
		}else{	//如果是操作符
			temp.flag = false;
			while(!s.empty() && op[str[i]] <= op[s.top().op])//s不为空且当前操作符优先级小于等于栈顶操作符优先级
			{	//则将s中栈顶操作符拿到q中去,并用pop使栈顶元素出栈
				q.push(s.top());
				s.top();
			}
			//s为空或当前操作符优先级大于栈顶操作符优先级则退出while循环
			temp.op = str[i];
			s.push(temp);//则将该操作符压入s操作符栈
			i++;//循环继续
		}
	}
	while(!s.empty()){
			q.push(s.top());//将s栈顶元素加入到q队列中去
			s.pop();//抛出s栈顶元素
		}
}

double cal(){	//计算后缀表达式
	double temp1,temp2;//temp1为第一位操作数，temp2为第二位操作数
	node cur,temp;//cur为队首元素
	while(!q.empty()){
			if (cur.flag == true)
		{	//如果队首元素是操作数则直接入栈
			s.push(cur);
		}else{
			//如果是操作符,则开始运算
				temp2 = s.top().num;
				s.pop();
				temp1 = s.top().num;
				s.pop();
				temp.flag = true;//临时记录操作数、
				if(cur.op == '+')	temp.num = temp1 + temp2;
				else if(cur.op == '-')	temp.num = temp1 - temp2;
				else if(cur.op == '*')	 temp.num = temp1 * temp2;
				else temp.num = temp1 / temp2;
				s.push(temp);//将该操作数压入栈
		}
	}
	return  s.top().num;//最后剩下一个栈顶元素则为后缀表达式的值
}

int main(){
	op['*'] = op['/'] = 1;
	op['+'] = op['-'] = 0;
	while(getline(cin,str), str != "0"){
		for (string::iterator it = str.end(); it != str.begin(); it--)//str::iterator is WRONG
		{
			if (*it == ' ')
			{
				str.erase(it);
			}
		}
		while(!s.empty())
			s.pop();
		change();
		printf("%.2f\n", cal());
	}
	return 0;
}



