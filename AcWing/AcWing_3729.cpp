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


// ����������ϲ� ����ά��һ������ l r ��������ʾ��ǰ  ��l��r��Ԫ�ض���Ҫ��Ϊ1
// ʲôʱ����Ҫ�����л����� �����µ������޷�����������νӵ�ʱ��  ����Ҫ����Ϊ�µ����� ���Ѷ�Ӧ���丳ֵΪ1


const int N = 200010;
int w[N];
int res[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		memset(res, 0, sizeof res);
		for (int i = 1; i <= n; i++) cin >> w[i];

		int l = 0, r = 0; //ά������
		for (int i = 1; i <= n; i++)
		{
			int tmp_l = 0, tmp_r = 0;
			if (w[i])
			{
				if (w[i] >= i) tmp_l = 1, tmp_r = i;
				else tmp_l = i - w[i] + 1, tmp_r = i;

				//��鱾�������Ƿ���ϴ������н���
				if (tmp_l <= r) l = min(l, tmp_l), r = max(l, tmp_r);
				else
				{
					for (int j = l; j <= r; j++) res[j] = 1;
					l = tmp_l;
					r = tmp_r;
				}
			}
		}
		for (int j = l; j <= r; j++) res[j] = 1;
		for (int i = 1; i <= n; i++) cout << res[i] << " ";
		cout << endl;
	}

	return 0;
}