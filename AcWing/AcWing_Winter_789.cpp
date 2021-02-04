//˼·�������еľ��䣬������ͬ�Ķ���ģ�壬ʵ�ʶ�ӦѰ�ҵ���������ͬ��ȷ�磬�ڴ�ͬʱ��Ӧ��checkҲ����ͬ
// check���׷���true����false������ֱ�ӿ�����������������mid����ֵ�����ĸ����䣬��ô��Ӧ������������� >=�������Ҫ��

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
	if (a[mid] >= num) return true;  //�۲�mid���������r���䣬˵����ʱ������ǶԵģ���ô�����������ұߣ�ͬʱ��������
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