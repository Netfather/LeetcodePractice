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

//区间合并问题， 首先按照首坐标进行排序，然后将排序好的坐标一一遍历，然后通过 l 和 r进行确认
// 每次r取取出来的坐标对右端点 和 本身保存的最大值中较大的一个
// 如果 发现 取出的坐标对的左端点 大于 现在存储的r 那么说明一个区间已经合并完成。
typedef pair<int, int> PII;

vector<PII> a;


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		a.push_back({ l,r });
	}
	sort(a.begin(), a.end());
	// 	for (auto i : a) cout << i.first << " " << i.second << endl;
	int l = a[0].first, r = a[0].second;
	int res = 0;

	for (int i = 1; i < a.size(); i++)
	{
		if (a[i].first <= r) r = max(r, a[i].second);
		else
		{
			++res;
			//更新l 和 r
			l = a[i].first, r = a[i].second;
		}
	}
	//最后还会剩下最后一个区间
	cout << ++res << endl;

	return 0;
}