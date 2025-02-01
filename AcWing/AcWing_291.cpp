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

// ���е�֮��ը�����������һ����
// ���ȹ���״̬ѹ��dp��������Ҫ���� ״̬ѹ��֮���Խ�״̬ѹ�����ǰ�ĳ��״̬��һ��������ʾ
// ��������⣬���ǽ�ĳһ�ж��������һС����Ϊ1��û���������Ϊ0�� �ö����ƹ���һ��״̬��
// ������ dp״̬�ǹ̶��ģ�f[i][j] ��ʾ  ǰi-1���Ѿ���ȫ��ã�Ȼ�󿴵�i�У��������С����״̬Ϊj�����з�������
// ����״̬���㣬 ��ô ���кϷ����ܹ��� f[i-1][k] �ߵ�  f[i][j] ��ΪĿ������
// ����������Ҫ���ǵľ���  ��i-2���Ѿ���ȫ���кã������С����״̬Ϊk  �����   ת�Ƶ� i-1���Ѿ���ȫ���кã����������С����״̬Ϊj

// ��ô���ģ�⼸��������ǿ�������
// 1.���k״̬�����С���ӣ���ô j״̬��Ȼ���������С���ӣ�����ͻ��и��ӷǷ��ڷ���  �� i& j == 0
// 2.���k״̬���еط�û�����С���ӣ���j״̬Ҳû�����С���ӣ���ζ�Ŵ�ʱֻ�ܰڷ����ŵ�С����
//				��ô��Щ�ط��������ϵ�����������ż��������Ҳ�ǷǷ��ġ�

// ���ϣ�������Ҫ ����Ԥ����һ�����п��ܵ�״̬���ж�����0�ĸ����Ƿ�Ϊż��
// Ȼ�����ǻ���Ҫ��ÿ��j ����һ�� ��Щk�ܹ��Ϸ����ߵ�j״̬����
const int N = 12, M = 1 << N; // ö��һ�����̵ĳ����Լ����е�״̬��
long long f[N][M];
bool st[M]; //����Ԥ����  ����0�ĸ����Ƿ�Ϊż��
vector<int> state[M]; // ���ڼ�¼��Щk�ܹ��Ϸ����ߵ�j״̬����


int main()
{
	int n, m;
	while (cin >> n >> m && n != 0 && m != 0)
	{
		//Ԥ��������   ʹ�ö�����ö�ٵķ������õ�ÿһλ�� 0 1
		// ����0Ϊż�� Ϊtrue ����Ϊfalse
		memset(st, false, sizeof st);
		for (int i = 0; i < 1 << n; i++)
		{
			int cnt = 0; //��¼����0�ĸ���
			bool is_valid = true; //��¼�������Ƿ�Ϸ�
			for (int j = 0; j < n; j++)
			{
				//���i����jλΪ1 ��ô���ж�һ�µ�ǰcnt
				if (i >> j & 1)
				{
					if (cnt % 2)
					{
						is_valid = false;
						break;
					}
					else cnt = 0;
				}
				else cnt++;
			}
			//����һ��β��
			if (cnt % 2) is_valid = false;
			st[i] = is_valid;
		}

		// Ԥ����һ�� ����״̬k��ת�Ƶ�״̬j
		//ö��״̬j
		for (int i = 0; i < 1 << n; i++)
		{
			state[i].clear();
			for (int j = 0; j < 1 << n; j++)
			{
				//��ǰ����   j �� i ��ͬʱΪ1  ����  j i��Ϊ0�ĵط� ����0�ĸ���Ϊż�� Ϊһ�ֺϷ�״̬
				if ((i & j) == 0 && st[i | j])
				{
					state[i].push_back(j); //˵���ܴ�״̬ j ת�Ƶ�״̬i
				}
			}
		}

		// ����dp
		memset(f, 0, sizeof f);
		// ��ʼ��
		// ���ڲ�����-1�� ���f[0][x] ��ʾһ�����鶼���� ��Ҳ��һ�ַ���  ���Ϊ1
		// Ȼ�����������״̬ ȫ���ǷǷ��ģ� ���Ϊ0
		for (int i = 1; i < 1 << n; i++) f[0][i] = 0;
		f[0][0] = 1;
		
		for (int i = 1; i < m + 1; i++)
		{
			for (int j = 0; j < 1 << n; j++)
			{
				//����������ת�Ƶ�״̬j��״̬   
				for (auto k : state[j])
				{
					f[i][j] += f[i - 1][k];
				}
			}
		}

		cout << f[m][0] << endl;
	}
	return 0;
}