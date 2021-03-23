//Ë¼Â·£º

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

const int N = 100010;
int q[N];
int qh, qt;

void push(int x)
{
	q[qt++] = x;
}

void pop()
{
	qh++;
}

void empty()
{
	if (qh >= qt) cout << "YES" << endl;
	else cout << "NO" << endl;
}

void query()
{
	cout << q[qh] << endl;
}


int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		string a;
		cin >> a;
		if (a == "push")
		{
			int x;
			cin >> x;
			push(x);
		}
		else if (a == "empty")
		{
			empty();
		}
		else if (a == "query")
		{
			query();
		}
		else if (a == "pop")
		{
			pop();
		}
	}
	return 0;
}