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

// ���ʹ����ֱ�ӵı����ⷨ  ʱ��϶��ᳬʱ
// ע�⵽ ��Ŀ��˵������֤���е��λ�ø�����ͬ
// ������� Ӧ���� ��һ����  Ȼ��ȥ��  ֮�� �� ͳ��ÿ�����г��ֹ�����
// ֮��ֻ��Ҫ�Գ���һ�ε�����ͳ�ƾͿ����ˡ�
// ͬʱע�⵽  ����ƽ������� ��� ������ȫ���԰� x �� y ��������


// ��������ͬ����ʱ  ��ֻ��ʹ��vector������  �������Բ�������  ֱ����O(n)ʱ����ʵ��ȥ�غ� ����

// ����ʹ���� unorderd���ǳ�ʱ ������ʾ���ƹ�ʽ����
// Ӧ���� ʹ�ù�ʽ�Ƶ��ķ�ʽ ���Ⱦ���͹�ʽ���Է�Ϊ  ƽ���Ͳ��� �� ����˻�����
// ƽ���Ͳ����ڶ������ݵ�ʱ��Ϳ���ֱ�����   �������� ����˻�����
// ͨ��һ���������Ƶ� ���ǿ��Է��� ����ɼ�������ʵ��  �� ��Ԫ��1��ʼһֱ�� n-1  �������¹�ʽ  x[i] * (s_x[n] - s_x[i])
// ����Ҳ������O(n) ʱ���� �õ����

// �������������  �������������и�  Ϊ�˱������������LL  ��Ҫ�õ�ULL �����������и�
// �������ǽ�ԭʼ����  ����һ����ƫ���� �������� �����������  ��Ծ����ƽ���� ����������������ƫ�ƶ����ս����û��Ӱ���

typedef unsigned long long ULL;
const int N = 100010;
ULL x[N];
ULL y[N];
ULL s_x[N];
ULL s_y[N];

int main()
{
	ULL res = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		x[i] += 10001;
		y[i] += 10001;
		res += (n - 1) * x[i] * x[i];
		res += (n - 1) * y[i] * y[i];
		s_x[i] = s_x[i - 1] + x[i];
		s_y[i] = s_y[i - 1] + y[i];
	}

	for (int i = 1; i < n; i++)
	{
		res -= 2 * x[i] * (s_x[n] - s_x[i]);
		res -= 2 * y[i] * (s_y[n] - s_y[i]);
	}


	cout << res << endl;

	return 0;
}