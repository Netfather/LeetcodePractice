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

int l, r;
typedef unsigned long long ULL;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> l >> r;
		int k = r;

		//��kλ����ȷ���ʱ�� �鿴�ֵ��������
		ULL tmp = ULL((2 * l) / (2 * k + 1));
		if (tmp >= float((r + 1) / (k + 1)))
		{
			cout << "YES" << endl;
			continue;
		}

		// ��kλ����ȷ���ʱ�򣬲鿴�ֵ��������
		k = 0;
		tmp = ULL((2 * l));
		if (tmp >= (r + 1))
		{
			cout << "YES" << endl;
			continue;
		}
		// ����ȷ�綼�޷��������⣬˵���ض���������������ĵ� ��������
		cout << "NO" << endl;
	}
return 0;
}