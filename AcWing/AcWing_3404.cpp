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

// ����ʱ�临�Ӷȷǳ���  ֻ��Ҫ�򵥱���ö����������Ϳ�����
const int N = 210;
int st[N]; //��ʾ �� i���� ��ϲ�����ǵڼ�����  trueΪϲ�� falseΪ��ϲ��

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> st[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int res = 0;
		for (int j = 1; j <= n; j++)
		{
			if (j == i) continue;
			if (st[j] == st[i]) res++;
		}
		if (res)	cout << res << endl;
		else cout << "BeiJu" << endl;
	}
	return 0;
}