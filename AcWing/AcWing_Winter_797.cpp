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
int w[N];
int c[N]; // ��ʾ������飬��ʾ ��c0 �� ci �����˵�  �͵Ľ������ w[i]

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) c[i] = w[i] - w[i - 1];  //�õ��������


	while (m--)
	{
		int l, r, k;
		cin >> l >> r >> k;
		c[l] += k;
		c[r + 1] -= k;

	}
	//��ԭ����
	for (int i = 1; i <= n; i++)
	{
		c[i] = c[i] + c[i - 1];
		cout << c[i] << " ";  // �Ӳ�����黹ԭ��  ԭ����
	}
	return 0;
}