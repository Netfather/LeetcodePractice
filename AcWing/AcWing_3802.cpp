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

// �ǳ��򵥵�һ������ ������Ŀ��������Ƶķǳ��ϸ� �������鳤�ȷǳ�С  �������ǿ����ñ��ѵķ�ʽ�����
// ����һ����־����  �����ǰԪ�ضԱ�ǰһ��ԭʼ������  ��Ϊ1 ����Ϊ0
// ����һ������n ��n��ʼ �鿴 ���ȫΪ1  ��ֱ�����n
// ��� ��ȫΪ1  �Ǿͼ�������  Ȼ�󲻶ϼ��� ֱ���ҵ���ȷ�Ĵ𰸡�
const int N = 21;
int flag[N];
int s_flag[N]; //�����ж�
int a[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (i == 1) flag[i] = 1;
			else
			{
				if (a[i] >= a[i - 1]) flag[i] = 1;
				else flag[i] = 0;
			}
		}
		//����һ��ǰ׺��
		for (int i = 1; i <= n; i++) s_flag[i] = s_flag[i - 1] + flag[i];
		//ö�����п��ܵĽ��
		if (s_flag[n] - s_flag[0] == n) cout << n << endl;
		else if (n / 2 != 0 && (s_flag[n] - s_flag[n / 2] == n / 2 || s_flag[n / 2] - s_flag[0] == n / 2)) cout << n / 2 << endl;
		else if (n / 4 != 0 &&
			(s_flag[n] - s_flag[n / 4 * 3] == n / 4
				|| s_flag[n / 4 * 3] - s_flag[n / 2] == n / 4
				|| s_flag[n / 2] - s_flag[n / 4] == n / 4
				|| s_flag[n / 4] - s_flag[0] == n / 4)) cout << n / 4 << endl;
		else if (n / 8 != 0 &&
			(s_flag[n] - s_flag[n / 8 * 7] == n / 8
				|| s_flag[n / 8 * 7] - s_flag[n / 8 * 6] == n / 8
				|| s_flag[n / 8 * 6] - s_flag[n / 8 * 5] == n / 8
				|| s_flag[n / 8 * 5] - s_flag[n / 8 * 4] == n / 8
				|| s_flag[n / 8 * 4] - s_flag[n / 8 * 3] == n / 8
				|| s_flag[n / 8 * 3] - s_flag[n / 8 * 2] == n / 8
				|| s_flag[n / 8 * 2] - s_flag[n / 8 * 1] == n / 8
				|| s_flag[n / 8 * 1] - s_flag[0] == n / 8)) cout << n / 8 << endl;
		else cout << 1 << endl;

	}
	return 0;
}