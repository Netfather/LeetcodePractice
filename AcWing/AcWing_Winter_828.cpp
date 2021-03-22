//思路：

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
//非常简单的一道题，对于栈这种后进先出的结构，我们只需要一个队尾计数器来计算目前尾部在哪里即可
const int N = 100010;
int s[N]; //存储对应位置的栈
int st = 0; //表示栈尾所在的位置

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