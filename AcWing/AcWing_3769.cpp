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

// ����������� ���ֻ���������ӣ�  ���һ��һ���� �Ѻ���������ʱ�����1������Ҫ 3������
// ������� ��3��2  �ٴ�2��1 ֻ��Ҫ2���������ɡ��������ֲ����ض������Ų���
// ��ô�ƹ㵽 n�����ӵ���������Եõ����ۣ� �����ܵĲ��� �ض��Ǵ���Զ�� ������һ�������͹����ġ�
// ����  û���������������ֲ������Լ۱ȸ��ߡ� ���  �Ľ�


// ���ϴ���  ��Ŀÿ���ƶ� ֻ���ƶ� 1��ʯͷ
// ���������   ��������ʽ��   �� a2������ʯͷ��ȫ�ƶ���a1 ��Ҫ���� 1* a2�Ĳ���
// ��˽� an���Ӽ���֮ǰ����������ʯͷ��ȫ�ƶ���a1 ��Ҫ���� 1*a2 + 2 * a3 + 3 * a4 + .... + (n-1) * an ����
// ���ĳ��nʹ�� ǡ�õ��� d  ��ô a2 + a3 �� an��Ϊ��
// ���ĳ��n ʹ��  �� f(n-1) < d < f(n) ��ô�𰸾�Ϊ����������� / an������

const int N = 110;
int a[N];
int s[N]; //����һ��ǰ׺��

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
		}

		//����һ���ҵ����������fn
		int fn = 0;
		int p = 2;
		for (; p <= n; p++)
		{
			fn += (p - 1) * a[p];
			if (fn >= d) break;
		}
		if (fn == d) cout << s[p] - s[0] << endl;
		else if (fn > d) cout << s[p - 1] - s[0] + (d - (fn - (p - 1) * a[p])) / (p - 1) << endl;
		else
		{
			//����˵�� û��ͨ��break ����  ȫ�����������
			cout << s[n] - s[0] << endl;
		}

		//

	}

	return 0;
}