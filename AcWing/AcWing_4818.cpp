//˼·��
// Ԥ����һ�� moeny����  ���������Ϊ ��ȡѧ�ѵ�ֵ
// money[ci] ��ʾ����ȡ ci��ѧ��ʱ �ж���ͷ��ţ��Ը��֧���۸��
// ��������һ��ʼ��ci�������  �޷���O(n)ʱ���ڴ����moeny����
// ����Ӧ��������  Ȼ�����һ�鼴�� ʱ�临�Ӷ�Ϊ nlgn

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
typedef unsigned long long LL;
LL res = 0;

int main()
{
	int n;
	cin >> n;
	vector<LL> w(n, 0);
	int res_2 = 0;
	for (int i = 0; i < n; i++) cin >> w[i];
	//Quick_Sort(0, n - 1);
	sort(w.begin(), w.end());

	for (int i = 0; i < n; i++)
	{
		LL tmp = w[i] * (n - i);
		if (res < tmp)
		{
			res = tmp;
			res_2 = w[i];
		}
	}
	cout << res << " " << res_2;
	return 0;
}