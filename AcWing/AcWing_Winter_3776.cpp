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

// ͨ����ѧ����ʽ�Ƶ� ��������������Թ滮
// ���� ƴ��1 x��  ƴ��2 y��
// Ŀ��   e*x + f* y �����ܴ���ô��Ӧx y ����;����ܵĴ�
// ͬʱ��������Լ������
// x <= a
// y <= min(b,c)
// x + y <= d

// ����ͨ��ö��x ����ֱ��ȷ�Ͻ����  �������yȡ�����ܵ���Сֵ0  ��ô x ����С�ڵ��� min(a,d)
// ��  x Ӧ����  a,d�н�С����һ��ȡֵ��
// ������ʼ�Ǹ�ö�� ���Ǳ������е�x��ȡֵ��Χ����


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		int x = 0;
		int y = 0;
		int res = INT_MIN;
		for (; x <= min(a,d); x++)
		{
			y = min(b, min(c, d - x));
			res = max(res, e * x + f * y);
		}
		cout << res << endl;
	}
	return 0;
}