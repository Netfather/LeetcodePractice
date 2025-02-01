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

const int N = 12;
bool st[N]; // 记录某个数字是否被用过
int n;
int w[N];  // 记录当前的结果


void dfs(int step)
{
	if (step > n)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << w[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!st[i])
		{
			st[i] = true;
			w[step] = i;
			dfs(step + 1);
			w[step] = 0;
			st[i] = false;
		}
	}
	return;
}



int main()
{
	cin >> n;
	dfs(1);

	return 0;
}