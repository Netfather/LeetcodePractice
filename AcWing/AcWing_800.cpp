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
int a[N];
int b[N];

// �����˼·�Ĺؼ������� �����ƶ�l ֱ������ A + B  > x
// Ȼ�����ƶ�r ֱ������ A+ B < x
// ����м��� == ��ֱ���������
// ��Ϊ��Ŀ��֤��Ψһ�⣬ ������������������ǿ���ͨ����֤��֤����ͨ��������� һ�������ҵ�Ψһ�������ʹ����������
// ������֮���� ��b�ϵ�ָ�� ���Բ��������ˣ�����Ψһ���⵽�ƻ�
int main()
{
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int l = 0, r = m - 1;
	while (l < n)
	{
		while (a[l] + b[r] < x) l++;
		while ((r >= 0) && (a[l] + b[r] > x)) r--;
		if (a[l] + b[r] == x)
		{
			cout << l << " " << r << endl;
			break;
		}
	}
	return 0;
}