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

const int V = 25;
int Bi[V];
int cnt = 0;
long long sum = 0;

void dfs(int target,int v,int start)
{
	//终止条件判断区
	if (sum >= target)
	{
		if (sum == target) cnt++;
		return;
	}

	for (int i = start; i < v; i++)
	{
		if (sum + Bi[i] <= target)
		{
			sum += Bi[i];
			dfs(target, v, i);
			sum -= Bi[i]; //恢复现场
		}
		else return;
	}
}

int main()
{
	int v,n;
	cin >> v >> n;
	for (int i = 0; i < v; i++)
	{
		cin >> Bi[i];
	}
	sort(Bi, Bi + v);

	dfs(n,v,0);

	cout << cnt << endl;

	return 0;
}