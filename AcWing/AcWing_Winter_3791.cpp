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

//������  ���߷�֯  ������֯һ�¼��� �ǳ���
// �鼸��ʵ��  ��֪������Ӧ����ô����
// ����˼·�� s��λȡ Ȼ��  �Խ����c  ���м������߽��и�ֵ


int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = "?" + s;
	string c = s;

	int k = n / 2;
	// ���� �� k��ʼ  ÿ�θ������ĵ� ���и�ֵ
	if (n % 2)
	{
		c[n / 2 + 1] = s[1]; //���ĵ㸳ֵ
		for (int i = 2; i <= n; i++)
		{
			c[k] = s[i];
			i++;
			c[n + 1 - k] = s[i];
			k--;
		}
	}
	else
	{
		//ż�����������ĵ㸳ֵ
		for (int i = 1; i <= n; i++)
		{
			c[k] = s[i];
			i++;
			c[n + 1 - k] = s[i];
			k--;
		}
	}
	for (int i = 1; i <= n; i++) cout << c[i];


	return 0;
}