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

//�ǳ��������ֱ��ͼ�������ε���Ŀ ������leetcode�м���
// ˼·��ö��  ���ǰѵ�ǰ���ڵ�ֱ��ͼ��Ϊ��Сֵ����������չ �����ҵ� ���ܹ��ﵽ�������롣 Ȼ��ö��ÿ��Ԫ�ؾͿ����ҵ����ֵ��
// ���������Ҫ����Ԥ����� �������� �ֱ���� ĳ��Ԫ���������С�ĵ�һ��Ԫ��  �� ĳ��Ԫ�����ұ���С�ĵ�һ��Ԫ��
// Լ�� -1 ��ʾ�Ҳ��� ����һֱȡ����ͷ���β
typedef unsigned long long ULL;
int n;
const int N = 1000010;
ULL w[N];  //ע������ͼ�߶Ⱥܴ� �п��ܱ�int
int r[N];
int l[N];


int main()
{
	while (cin >> n && n != 0)
	{
		memset(w, 0, sizeof w);
		ULL res = 0;
		for (int i = 0; i < n; i++) cin >> w[i];
		//Ԥ������߱���С�ĵ�һ��Ԫ��
		stack<int> s;  //�洢�������ݵ��±�
		for (int i = 0; i < n; i++)
		{
			while (!s.empty() && w[s.top()] >= w[i]) s.pop();
			if (s.empty()) l[i] = -1;
			else l[i] = s.top();
			s.push(i);
		}
		// Ԥ�����ұ߱���С�ĵ�һ��Ԫ��
		stack<int> s_r;
		for (int i = n - 1; i >= 0; i--)
		{
			while (!s_r.empty() && w[s_r.top()] >= w[i]) s_r.pop();
			if (s_r.empty()) r[i] = -1;
			else r[i] = s_r.top();
			s_r.push(i);
		}

		// ö��ÿ��Ԫ��
		for (int i = 0; i < n; i++)
		{
			ULL tmp = 0;
			// ����֮���Բ����� l[i] == -1����������� ��ʱ��-1���ü�ȥ������� ��Ч�ڼ�1  û������
			if (r[i] == -1) tmp = (n - l[i] - 1) * w[i];
			else tmp = (r[i] - l[i] - 1) * w[i];
			res = max(res, tmp);
		}
		cout << res << endl;
	}
	return 0;
}