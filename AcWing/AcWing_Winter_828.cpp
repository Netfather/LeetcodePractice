//˼·��

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <climits>
using namespace std;
//�ǳ��򵥵�һ���⣬����ջ���ֺ���ȳ��Ľṹ������ֻ��Ҫһ����β������������Ŀǰβ�������Ｔ��
const int N = 100010;
int s[N]; //�洢��Ӧλ�õ�ջ
int st = 0; //��ʾջβ���ڵ�λ��

void push(int x)
{
	s[st++] = x;
}

void pop()
{
	st--;
}

void empty()
{
	if (st == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}

void query()
{
	cout << s[st - 1] << endl;
}


int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		string Op;
		cin >> Op;
		if (Op == "push")
		{
			int x;
			cin >> x;
			push(x);
		}
		else if (Op == "pop") pop();
		else if (Op == "empty") empty();
		else query();
	}


	return 0;
}