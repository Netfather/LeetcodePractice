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

//2. ��������������� ���ߵ����
//3. ���Ƕ�����ö��һ�����п��ܵĹ��������������ζ�Ŷ�Ӧ��URDLҪ��ȥ��Ӧ��ֵ
//4. �ڼ�ȥ��Ӧ��ֵ�� ֻҪ��֤�±߱ض��� 0 �� n-2 ֮�����ζ�űض��н� 

//4. ����ֻ��4������  �������ֻ��Ҫ����ö��һ�� �Ϳ�����

int st[4]; //��ʾ 4���߽���ӵ�Ⱦɫ���

int main()
{
	int T;
	cin >> T;
Label:	while (T--)
	{
		int n, U, R, D, L;
		cin >> n >> U >> R >> D >> L;
		int u = 4;
		for (int i = 0; i < 1 << u; i++)
		{
			memset(st, 0, sizeof st);
			int U_check = U;
			int R_check = R;
			int D_check = D;
			int L_check = L;

			for (int j = 0; j < u; j++)
			{
				if (i >> j & 1) st[j] = 1;
			}
			//����߽���ӵ����
			if (st[0] == 1) U_check--, L_check--;
			if (st[1] == 1) U_check--, R_check--;
			if (st[2] == 1) R_check--, D_check--;
			if (st[3] == 1) D_check--, L_check--;
			//�������֮�� �����ʱ�����ڵ���0 ����С�ڵ���n-2 ˵���н�
			if (U_check >= 0 && R_check >= 0 && D_check >= 0 && L_check >= 0
				&& U_check <= n - 2 && R_check <= n - 2 && D_check <= n - 2 && L_check <= n - 2	)
			{
				cout << "YES" << endl;
				goto Label;
			}
		}
		cout << "NO" << endl;
	}
	return 0;
}