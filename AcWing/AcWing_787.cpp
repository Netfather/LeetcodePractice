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

const int N = 100010;
int w[N], tmp[N];

void MergeSort(int start, int end)
{
	//��ֹ�����ж�
	if (start >= end) return;
	// ��������������
	int m = start + end >> 1;
	// �ֱ���й鲢
	MergeSort(start, m);
	MergeSort(m + 1, end);
	//��ɹ鲢���������
	int l_1 = start, l_2 = m + 1;
	int cur = 0;
	// ����˫ָ�룬���������������Ԫ�رȽϣ����ȽϽ������tmp��
	while (l_2 <= end && l_1 <= m)
	{
		if (w[l_1] >= w[l_2])
		{
			tmp[cur++] = w[l_2++];
		}
		else if (w[l_1] < w[l_2])
		{
			tmp[cur++] = w[l_1++];
		}
	}
	// �ٲ�ȱ��©���������ֿ������У�����û�����������ӵ�tmp����
	while (l_1<= m) tmp[cur++] = w[l_1++];


	while (l_2 <= end) tmp[cur++] = w[l_2++];


	//������õ������ŵ�����
	for (int i = start, k = 0;i <= end; i++,k++)
	{
		w[i] = tmp[k];
	}

	return;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	MergeSort(1, n);
	for (int i = 1; i <= n; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;



	return 0;
}