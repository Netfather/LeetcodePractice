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

//����⿼��ľ��Ǹ���һ�����У���εõ�������һ���ֵ���
//���幹��˼·Ϊ: 
// 1. �����һ������ǰɨ�裬���һֱ������ģ�˵����ʱ�Ѿ����ܹ����޸���
// 2. ֱ��ɨ�赽��һ������ģ����Ǹ�����ĺ���ߵ�һ���������������λ��
// 3. Ȼ���ٰѺ������ȫ�������������reverse ע��C++��reverse������ҿ�������
	
const int N = 10010;
int P[N];

void Next_dictionary(int n)
{
	int index_1 = n-1; //���ڴ洢��һ�������Ľ���λ��
	for (int i = n-1; i >= 1; i--)
	{
		//�洢��һ������λ�ã�Ȼ���˳�ѭ��
		if (P[i] < P[i + 1])
		{
			index_1 = i;
			break;
		}
	}
	// Ȼ��ȥѰ�ұ����λ�ô�ĵ�һ������
	int index_2 = index_1+1;
	for (; index_2 <= n; index_2++)
	{
		if (P[index_2] < P[index_1])
		{
			swap(P[index_1], P[index_2 - 1]);
			break;
		}
		else
		{
			if (index_2 == n) swap(P[index_1],P[n]);
		}
	}
	reverse(P + index_1 + 1, P + n+1);
	return;
}


int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> P[i];
	}

	for (int i = 1; i <= m; i++)
	{
		Next_dictionary(n);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << P[i] << " ";
	}
	cout << endl;

	return 0;
}