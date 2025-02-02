//思路：经典中的经典，两个不同的二分模板，实际对应寻找的是两个不同的确界，于此同时对应的check也不相同
// check到底返回true还是false，我们直接看如果这个条件成立，mid被赋值到了哪个区间，那么对应区间的条件就是 >=这个很重要！

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

bool check_1(int mid, vector<int> &a, int num)
{
	if (a[mid] >= num) return true;  //观察mid被分配给了r区间，说明这时候如果是对的，那么搜索区间在右边，同时包含自身
	return false;
}

int bsearch_1(int l, int r, vector<int> &a, int num)
{
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check_1(mid, a, num)) r = mid;
		else l = mid + 1;
	}
	return l;
}

bool check_2(int mid, vector<int> &a, int num)
{
	if (a[mid] <= num) return true;
	return false;
}


int bsearch_2(int l, int r, vector<int> &a, int num)
{
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check_2(mid, a, num)) l = mid;
		else r = mid - 1;
	}
	return l;
}


int main()
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n, -1);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < q; i++)
	{
		int num;
		cin >> num;
		if (num < a[0] || num > a[n - 1]) cout << -1 << " " << -1 << endl;
		else if (num == a[0]) cout << 0 << " " << bsearch_2(0, n - 1, a, num) << endl;
		else if (num == a[n - 1])cout << bsearch_1(0, n - 1, a, num) << " " << n - 1 << endl;
		else
		{
			int leftbound = bsearch_1(0, n - 1, a, num);
			int rightbound = bsearch_2(0, n - 1, a, num);
			if ((a[leftbound] != num) || (a[rightbound] != num))
			{
				cout << -1 << " " << -1 << endl;
			}
			else cout << bsearch_1(0, n - 1, a, num) << " " << bsearch_2(0, n - 1, a, num) << endl;
		}
	}
	return 0;
}