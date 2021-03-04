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
int w[N];

//���ţ� ����������㣬����������һ������õ���keyֵ������������ڵ��������ֻ��ֳ��������ߣ���ͬʱ��֤���������Ϊ��
void QuickSort(int l, int r)
{
	if (l >= r) return; //�ݹ���ֹ����������
	int key = w[l + r >> 1];

	int start = l - 1, end = r + 1; //ָ��˫ָ���������ʼ��
	while (start < end)
	{
		while (w[++start] < key) {};
		while (w[--end] > key) {};
		if (start < end) swap(w[start], w[end]);
	}

	QuickSort(l, end);
	QuickSort(end + 1, r);
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
	QuickSort(1, n);
	for (int i = 1; i <= n; i++)
	{
		cout << w[i] << " ";
	}
	return 0;
}