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

// 0 �� 1   1��ʾ��һ�����Ͽ���   0 ��ʾ����Ϣ��

// ���ȿ���  ��һ���Ͽ��� �� ���һ���Ͽ���  
// ������ض�   ������ǰ��� �������Ӷ����ÿ���
const int N = 110;
int w[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> w[i];
		//������һ���Ͽ���
		int start = 0;
		for (int i = 0; i < n; i++)
		{
			if (w[i] == 1)
			{
				start = i;
				break;
			}
		}
		//�������һ���Ͽ���
		int end = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (w[i] == 1)
			{
				end = i;
				break;
			}
		}
		//�ҵ�֮�� ���һ��
		int res = 0; 
		int cnt_zero = INT_MAX; //ͳ������1֮�� 0�ĸ���
		if (start > end) cout << 0 << endl;
		else
		{
			for (int i = start; i <= end; i++)
			{
				if (w[i] == 1)
				{
					if (cnt_zero == 1) res++; //���ҽ����м�Ϊһ��1��ʱ�� ��Ҫ������һ��
					res++;
					cnt_zero = 0; //��������
				}
				else cnt_zero++;
			}
			cout << res << endl;
		}
	}
	return 0;
}