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

//  һ���Ϊn��ʱ��   ����������Ϣʱ����ܿ���  ��ʵ����ֻ��Ҫ ��������ƴ����һ��  Ȼ��
// ��ÿ��ĵ�һ�� 10 ֮��ʼͳ�� һֱͳ�Ƶ� �ڶ���ĵ�һ��  10 ���紦����

//�ǳ��򵥵�ģ����
const int N = 400010;
int w[N];


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		// ���ҵ���һ�� 10�����
		int flag = 0;
		int p = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> w[i];
			if (flag == 0 && i != 0 && w[i - 1] == 1 && w[i] == 0) p = i, flag = 1;
		}
		// �ӳ�һ���ʱ��
		for (int i = n; i < n + p; i++)
		{
			w[i] = w[i - n];
		}
		// �� p�� n+p��ʱ����  Ѱ�������Ϣʱ��
		int res = INT_MIN;
		int tempres = 0;
		for (int i = p; i < n + p; i++)
		{
			if (w[i] == 1) tempres++;
			else
			{
				res = max(res, tempres);
				tempres = 0; //���
			}
		}
		cout << max(res, tempres) << endl;

	}


	return 0;
}