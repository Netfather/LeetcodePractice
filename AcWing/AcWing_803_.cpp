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

//����ϲ����⣬ ���Ȱ����������������Ȼ������õ�����һһ������Ȼ��ͨ�� l �� r����ȷ��
// ÿ��rȡȡ������������Ҷ˵� �� ����������ֵ�нϴ��һ��
// ��� ���� ȡ��������Ե���˵� ���� ���ڴ洢��r ��ô˵��һ�������Ѿ��ϲ���ɡ�
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
			//����l �� r
			l = a[i].first, r = a[i].second;
		}
	}
	//��󻹻�ʣ�����һ������
	cout << ++res << endl;

	return 0;
}