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

const int N = 100010;
int w[N];  //��ʾ�洢��ԭ����
int s[N];  //��ʾ��1��ʼ�ӵ���i��Ԫ�� ��������i�� �ĺ�

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> w[i];

 //����ǰ׺��
	for (int i = 1; i <= n; i++)
	{
		s[i] = w[i]+ s[i - 1];
	}
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		cout << s[r] - s[l - 1] << endl;

	}


	return 0;
}