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
#include <climits>
using namespace std;

bool cmp(vector<int> a, vector<int> b)
{ 
	if (a[0] != b[0]) return a[0] < b[0];
	else return a[1] < b[1];
}

bool cmp(vector<int> a, vector<int> b)
{
	if (a[0] != b[0]) return a[0] < b[0];
	else return a[1] < b[1];
}
int find(int x, vector<int> &f) { return f[x] == x ? x : f[x] = find(f[x],f); }
int unite(int x, int y, vector<int> &f) {
	int fa = find(x, f), fb = find(y, f);
	if (fa == fb)	return 0;
	else	f[fb] = f[fa];
	return 1;
}

int res(int n, int m, vector<vector<int>> &plan, unordered_map<int, int> &visted)
{
	sort(plan.begin(), plan.end(), cmp);
	vector<int> f(n + 1, 0);
	for (int i = 1; i <= n; ++i)	f[i] = i;
	for (auto sub : plan)
	{

		if (unite(sub[0], sub[1], f))
		{
			++visted[sub[0]];
			++visted[sub[1]];
		}
	}
	int res = 0;
	for (unordered_map<int, int>::iterator temp = visted.begin(); temp != visted.end(); ++temp)
	{
		res = max(res, temp->second);
	}
	return res;
}

//Test
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		unordered_map<int, int> visted;
		vector<vector<int>> plan(m, vector<int>(3, 0));
		for (int i = 0; i < m; i++)
		{
			cin >> plan[i][0] >> plan[i][1];
			if (plan[i][0] > plan[i][1])
			{
				int temp = plan[i][0];
				plan[i][0] = plan[i][1];
				plan[i][1] = temp;
			}
		}
		cout << res(n, m, plan, visted);
	}
	system("Pause");
	return 0;
}

//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			int n, m, x, y;
//			cin >> n >> m >> x >> y;
//			if (x - y <= 0) cout << m;
//			else
//			{
//				int temp1 = (n - x) / (x - y);
//				if (temp1 >= m) cout << m;
//				else
//				{
//					int res_mana = n - temp1 * (x - y);
//					int count = temp1-1;
//					while (temp1++ <= m)
//					{
//						res_mana = min(n,res_mana+ y);
//						if (res_mana >= x)
//						{
//							++count;
//							res_mana -= x;
//						}
//					}
//					cout << count;
//				}
//			}
//		}
//	}
//	return 0;
//}