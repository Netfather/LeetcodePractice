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

// ���ȶ�������һ�����֣����������Ķ�����λ�� ֻ��Ҫ������������ƾͿ�����
// Ȼ���ж���һλ��ĩβ�Ƿ���1 ֻ��Ҫ������ ��1 ��һ��ȡ�Ϳ�����
const int N = 100010;
int w[N];

int main()
{
	int n;
	cin >> n;


	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < n; i++)
	{
		// ����һ ���ʹ�ʽλ num  >> k  & 1
		//int res = 0;
		//int num = w[i];
		//while (num)
		//{
		//	if (num & 1) res++;
		//	num = num >> 1;
		//}
		//cout << res << " ";
		// ������  ʹ��lowbit��ʽ��x&(-x)�����ʽ�᷵��x ÿ��lowbit������ȡһ���������һ��1���������λ��
		//ÿ�μ�ȥlowbit�õ������֣�ֱ�����ּ���0���͵õ�������1�ĸ�����
		int res = 0;
		int num = w[i];
		int tmp = num;
		while (tmp)
		{
			res++;
			tmp = tmp - (tmp & (-tmp));
		}
		cout << res << " ";

	}

	return 0;
}