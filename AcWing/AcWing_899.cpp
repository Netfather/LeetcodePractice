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

// ���ڳ��Ȳ��ᳬ��10 ��˾���ͨ����̱༭�������ж� �Ƿ�����ָ�������ڴﵽĿ���ַ���
// �������µ�dp��������
// f[i][j] ��ʾ �� 1-i �仯�� 1-j�����б仯������    ���Դ洢���� �仯�Ĵ�����Сֵ
// ����״̬ת��
// ������һ��������ͬ  ��ô���� f[i-1][j-1]
// ������һ�����ֲ���ͬ   1. ���ǲ��� ��ô���� f[i][j-1] + 1 
// 2. �����滻  ��ô���� f[i-1][j-1] + 1
// 3. ����ɾ�� ��ô���� f[i-1][j] + 1
const int N = 1010;
int f[15][15];
string str[N];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> str[i];
	while (m--)
	{
		string b;
		int cnt;
		cin >> b >> cnt;
		b = "?" + b;
		// ��ʼ�� f
		memset(f, 0x3f, sizeof f);
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			string a = str[i];
			a = "?" + a;
			for (int i = 0; i <= b.length(); i++) f[0][i] = i; //����i��
			for (int i = 0; i <= a.length(); i++) f[i][0] = i; //ɾ��i��
			for (int i = 1; i <= a.length(); i++)
			{
				for (int j = 1; j <= b.length(); j++)
				{
					if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1];
					else
					{
						f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
						f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
					}
				}
			}
			if (f[a.length()][b.length()] <= cnt) res++;
		}
		cout << res << endl;
	}
	return 0;
}
