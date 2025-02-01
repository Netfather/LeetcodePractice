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

// ������������˻�Ϊ  �ƶ�����һ��Ԫ�أ� ʹ�����ƶ��������֮�� �����ǰ�벿��֮�� Ϊĳ���̶�ֵx
// Ȼ�����ǿ��Է���  ���ֲ��� ����Ӱ����������������ԣ� 
// ��� �������·�ʽ������O(n)ʱ���ڽ�������
// �ڶ����ʱ�������ҵ�ĳ��λ��k ʹ��  a1+ a2+a3+ ak-1 < x    ��ʱ�������x��ֱ�����Yes
// a1 + a2 +a3 + ak + ak > x
//��ʱ��������� 1. ��������ƶ�����1��k֮������֣���ô��Ȼ�ƻ��������ԣ���������ֻ��һ���ƶ�һ��  ���� ����Ĳ��־Ͳ��ܶ���
//					����ʱ����������Ѿ��ų���ֻ�ܽ���������ƶ�����벿�֣���ô��ʱ������Ҫ���������ɾȥ Ȼ��������������꣬�ҵ�
//					�Ƿ��������  û�о�ֱ��break
// 2. ����ƶ����� k+1�� n�����֣���ô����ֻ��Ҫֱ��Ѱ��  �Ƿ���ĳ������ǡ�õ��� x - a1-a2 -ak  �еĻ������Yes û�о�No
// �������2�ĸ��Ӷ�Ϊ0(1) ���1�ĸ��Ӷ��Ϊ O(n - k) ����ǿ��Թ���
typedef unsigned long long LL;

const int N = 100010;
LL w[N];
LL s[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		unordered_set<LL> Table; //���ڴ洢ĳ�������Ƿ���ֹ�  ����ֻ�洢 ��벿�ֵ�����
		int n;
		cin >> n;
		LL tmp_cnt = 0; //����Ѱ��ָ����kλ��
		//�������� ͬʱԤ����ǰ׺������
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i];
			s[i] = s[i - 1] + w[i];
		}
		//����Ŀ��ֵ  �����Ϊ���� ˵�������ܴ���
		if ((s[n] - s[0]) % 2)
		{
			cout << "NO" << endl;
			continue;
		}
		LL x = (s[n] - s[0]) / 2; //���Ŀ��ֵx
		int k = -1;
		// ����һ���ҵ��ؼ�λ��k ͬʱ��k+1 ֮�����������ȫ�����ϣ��
		for (int i = 1; i <= n; i++)
		{
			tmp_cnt += w[i];
			if (tmp_cnt == x)
			{
				cout << "YES" << endl;
				break;
			}
			else if (tmp_cnt > x && k == -1)
			{
				k = i - 1; 
			}
			
			if (k != -1) Table.insert(w[i]);
			
		}
		if (tmp_cnt == x) continue;

		//���������  �ȿ����k+1��n֮�������
		// 
		bool ans = false;
		for (int i = 1; i <= k; i++)
		{
			if (Table.count(x - (s[i] - s[0])))
			{
				ans = true;
				cout << "YES" << endl;
				break;
			}
		}
		if (ans == true) continue;
		//���������  �ٿ����1��k֮�������
		k++; //����++��Ŀ���ǰ� k��λ�� ����  ��һ�� >x��λ�ã���Ϊ���滻֮ǰ�����֣���˱߽�����Ҫ������
		// �������ͨ���ܶ������� ֤�� ����  ��СΪ6  ˳��Ϊ 5 4 1 2 2 2 �����У����k = 1��û�н�� ����ʵ����ֻ��Ҫ�� 4Ų��������ȥ������
		for (int i = 1; i <= k; i++)
		{
			LL tmp = s[k] - s[0] - w[i];
			if (tmp == x)
			{
				cout << "YES" << endl;
				ans = true;
				break;
			}
			for (int j = k + 1; j <= n; j++)
			{
				tmp += w[j];
				if (tmp == x)
				{
					cout << "YES" << endl;
					ans = true;
					break;
				}
				else if (tmp > x)
				{
					ans = false;
					break;
				}
			}
			if (ans == true) break;
		}
		//�����ﻹ����trueֻ����No��
		if (ans == false) cout << "NO" << endl;

		Table.clear();  
	}
	return 0;
}