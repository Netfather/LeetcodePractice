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

// ���������������ж���������ֱ��ģ��
// ���� ai����С�ڵ���m 
// ���Ψһ��������� ����ĳЩ�༶����  ʹ��  ai + ai+1 + aj <= m ��ô��Щ�������һ��������
// ���༶�ֱ��밴��˳�����  �������� �ܼ� ����ѭ�� �ڲ�ѭ�������¼ ���γ��ӵĸ������
const int N = 110;
int a[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];

		int res = 0;

		for (int i = 1; i <= n;)
		{
			int t = m; // ��ʱ����ʣ������Ϊ m�� 
			while ( i <= n &&  t >= a[i])
			{
				t = t - a[i];
				i++;
			}
			res++;
		}
		cout << res << endl;
	}
	return 0;
}