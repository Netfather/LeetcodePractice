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

//
//2. 
//3.
//4. ע�⵽ һ�����ڲ��������� �ͻ�����ֹͣ����  ���Ǵ����ģ����� �ض��ᳬʱ
//5. ע�⵽  ��չ������ x�� w/x Ҳ����ֻҪ����չ �Ǳض�����չw[i]�Ĵ�С
// ��˿������¹��� ��wά��ÿ�γ���x֮����̣���org_wά���ʼ����Ľ����ÿ�δ�ͷ��ʼ����������w�����������w �͸���w Ȼ��������org_w����
typedef unsigned long long ULL;
const int N = 100010;
int w[N];
int org_w[N];


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		ULL res = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> w[i];
			org_w[i] = w[i];
			res += w[i];
		}
		int flag = 0;
		while (1)
		{
			for (int i = 0; i < n; i++)
			{
				if (w[i] % x != 0)
				{
					flag = 1;
					break;
				}
				res += org_w[i];
				w[i] = w[i] / x;
			}
			if (flag) break;
		}
		cout << res << endl;
	}
	return 0;
}