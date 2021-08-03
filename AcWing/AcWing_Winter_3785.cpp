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

// ����ս������ض��� ��ĳ������ռ��1�����ӣ����  ��ս���Ǻ��ŷŵ�ʱ��   ������ʼ����ȫ���ܵģ�Ҳ���Ǹ��ѿ���
// ��ô����ͨ�����·�ʽִ������   
// �Ⱥ�������  ���������� . ����  ����
// ������  < k  ���޷�����  
// ������  >= k   <  2k - 1 ������ȫ�����  ��ʱ ��Ҫ ���� [ ĩβ - k + 1       , base + k - 1 ] ���ֱ�ֵ
// ������ >= 2k -1  �� [base + k - 1, ĩβ  - k + 1]  ���ֱ�ֵ
// Ȼ��������������������� ͬ��ִ����������

// ������ƺ�ֻ�� ������һ�� ������һ�� Ȼ������ܵĴ�С 
const int N = 110;
typedef pair<int, int> PII;
int res[N][N];  //�洢ÿ����ķ�����
int n, k;
string g[N];  //�洢 �����ͼ

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> g[i];
		g[i] = "?" + g[i]; //��Ӷ����ڱ�
	}
	//ͳ�ƺ����������.�ĸ���
	for (int i = 1; i <= n; i++)
	{
		int base = 0; //��ʼλ��
		int cnt = 0; //��¼.�ĸ���
		for (int j = 1; j <= n; j++)
		{
			if (g[i][j] == '.') cnt++;
			else
			{
				base = base + 1;
				if (cnt >= k && cnt < 2 * k - 1)  //��ʱ ������  1 2 3 4 5 ����4�Ĵ��� �����  1 2 2 2 1
				{
					int temp_cnt = 1;
					for (int u = base; u < j - k; u++) res[i][u] += temp_cnt, temp_cnt++;
					for (int u = j - k; u <= base + k - 1; u++)  res[i][u] += temp_cnt;
					--temp_cnt;
					for (int u = base + k; u < j; u++) res[i][u] += temp_cnt, temp_cnt--;
				}
				else if (cnt >= 2 * k - 1) //��ʱ ������  1 2 3 4 5 6����3�Ĵ��� ����� 1 2 3 3 2 1 
				{
					int temp_cnt = 1;
					for (int u = base; u < base + k - 1; u++) res[i][u] += temp_cnt, temp_cnt++;
					for (int u = base + k - 1; u <= j - k; u++)  res[i][u] += temp_cnt;
					--temp_cnt;
					for (int u = j - k + 1; u < j; u++) res[i][u] += temp_cnt, temp_cnt--;
				}
				base = j; //������ʼλ��
				cnt = 0; //��� �ۼ���
			}
		}
		//����һ��β��
		if (cnt)
		{
			base = base + 1;
			int j = n + 1;
			if (cnt >= k && cnt < 2 * k - 1)
			{
				int temp_cnt = 1;
				for (int u = base; u < j - k; u++) res[i][u] += temp_cnt, temp_cnt++;
				for (int u = j - k; u <= base + k - 1; u++)  res[i][u] += temp_cnt;
				--temp_cnt;
				for (int u = base + k; u < j; u++) res[i][u] += temp_cnt, temp_cnt--;
			}
			else if (cnt >= 2 * k - 1)
			{
				int temp_cnt = 1;
				for (int u = base; u < base + k - 1; u++) res[i][u] += temp_cnt, temp_cnt++;
				for (int u = base + k - 1; u <= j - k; u++)  res[i][u] += temp_cnt;
				--temp_cnt;
				for (int u = j - k + 1; u < j; u++) res[i][u] += temp_cnt, temp_cnt--;
			}
		}
	}

	//ͳ�������������.�ĸ���  ������߼���������߼�����ȫһ����  ͬ���������ڶ����ʱ��ʹ�����  �����Ͳ�����ô����
	for (int j = 1; j <= n; j++)
	{
		int base = 0; //��ʼλ��
		int cnt = 0; //��¼.�ĸ���
		for (int i = 1; i <= n; i++)
		{
			if (g[i][j] == '.') cnt++;
			else
			{
				base = base + 1;
				if (cnt >= k && cnt < 2 * k - 1)
				{
					int temp_cnt = 1;
					for (int u = base; u < i - k; u++) res[u][j] += temp_cnt, temp_cnt++;
					for (int u = i - k; u <= base + k - 1; u++)  res[u][j] += temp_cnt;
					--temp_cnt;
					for (int u = base + k; u < i; u++) res[u][j] += temp_cnt, temp_cnt--;
				}
				else if (cnt >= 2 * k - 1)
				{
					int temp_cnt = 1;
					for (int u = base; u < base + k - 1; u++) res[u][j] += temp_cnt, temp_cnt++;
					for (int u = base + k - 1; u <= i - k; u++)  res[u][j] += temp_cnt;
					--temp_cnt;
					for (int u = i - k + 1; u < i; u++) res[u][j] += temp_cnt, temp_cnt--;
				}
				base = i; //������ʼλ��
				cnt = 0; //��� �ۼ���
			}
		}
		//����һ��β��
		if (cnt)
		{
			base = base + 1;
			int i = n + 1;
			if (cnt >= k && cnt < 2 * k - 1)
			{
				int temp_cnt = 1;
				for (int u = base; u < i - k; u++) res[u][j] += temp_cnt, temp_cnt++;
				for (int u = i - k; u <= base + k - 1; u++)  res[u][j] += temp_cnt;
				--temp_cnt;
				for (int u = base + k; u < i; u++) res[u][j] += temp_cnt, temp_cnt--;
			}
			else if (cnt >= 2 * k - 1)
			{
				int temp_cnt = 1;
				for (int u = base; u < base + k - 1; u++) res[u][j] += temp_cnt, temp_cnt++;
				for (int u = base + k - 1; u <= i - k; u++)  res[u][j] += temp_cnt;
				--temp_cnt;
				for (int u = i - k + 1; u < i; u++) res[u][j] += temp_cnt, temp_cnt--;
			}
		}
	}

	//�ҵ�res�������Ǹ� ������λ�ü�Ϊ����
	PII loc = { 1,1 };
	int len_res = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (res[i][j] > len_res)
			{
				loc = { i,j };
				len_res = res[i][j];
			}
		}
	}

	cout << loc.first << " " << loc.second;



	return 0;
}