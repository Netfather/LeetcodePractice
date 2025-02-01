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
long int res = 0;

void Nixu(int start, int end)
{
	if (start >= end) return;

	int mid = start + end >> 1;

	Nixu(start, mid);
	Nixu(mid + 1, end);

	//�鲢
	int p_1 = start, p_2 = mid + 1;
	int tmp_cur = 0;

	while (p_1 <= mid && p_2 <= end)
	{
		//�˴���������ԣ�����ÿһ�δӹ鲢�Ĺ��̣������������� ǰ������p1 �����Ϊ x1,x2,x3 ��������p2 �����Ϊ y1,y2,y3
		// ע�⵽����ÿһ��ǰ�����е����궼��С�ں������е� �������������1
		// ��ô�����ʱ��ǰ�������д���һ�� xi �����ں��������е�ĳ�� yj
		// ���Եõ� x1 < x2 < ...  < xi < yj �����ǰ������г���ͳͳΪ����Ե�����
		if (w[p_1] <= w[p_2]) tmp[tmp_cur++] = w[p_1++];
		else
		{
			res += mid - p_1 + 1;
			tmp[tmp_cur++] = w[p_2++];
		}
	}
	while (p_1 <= mid) tmp[tmp_cur++] = w[p_1++];
	while (p_2 <= end) tmp[tmp_cur++] = w[p_2++];

	for (int i = start, k = 0; i <= end; i++, k++) w[i] = tmp[k];
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
	Nixu(1, n);
	cout << res << endl;
	return 0;
}