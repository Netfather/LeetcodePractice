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

// �������Ҫ�ҵ���С����ĵ�k��������ϸ˼�����������У�ÿ��ȷ������key��Ӧ��λ�ã������֪��key��Ӧ���±�֮�����ǿ���һ���ǿ���һ������
const int N = 100010;
int w[N];
// ע�������ĺ����������������������� start �� end��Χ�� ��k�����Ƕ��٣�ע�����kӦ���Ǵ�start��ʼ���𣬶���Ӧ�������������k���룬���
// 
bool QuickSortK(int start, int end, int k)
{
	if (start >= end) return true;

	auto key = w[start + end >> 1];

	int l = start - 1, r = end + 1;
	while (l < r)
	{
		while (w[++l] < key);
		while (w[--r] > key);
		if (l < r) swap(w[l], w[r]);
	}
	//���ģ� ����������Ҫ�Ƚϵ��ǣ��������˫ָ���㷨֮�� rָ��Ŀǰ��ȷλ�õ�λ�ã���r - start+ 1 �õ���Ӧ�ڵ�ǰ���飬k��λ�ã�Ȼ��������������
	// ���ʹ��� ����Ľ�r ��Ϊ��ȷλ�õ���û�н��� r - start+ 1 ���� ��������
    // ������Ҫʵʱά�� �����һ��QuickSort����֮������Ѿ�����õĳ��ȵ����ж��٣�
	if (r - start + 1 >= k) // ͳ�ƹ涨��������ж��ٸ�����
	{
		if (QuickSortK(start, r, k)) return true;
	}
	else
	{
		if (QuickSortK(r + 1, end, k - (r - start + 1))) return true;

	}

	return false;
}


int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	QuickSortK(1, n, k);
	cout << w[k] << endl;

	return 0;
}