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

//�ǳ��򵥵�һ���� ����n�ض�Ϊż�� ����Ѿ��Ƿǳ����Ե���ʾ��
// ˵���������һ�ֶԳƵĹ���
// ������� a1 a2 a3 a4  ����b�Ĺ���Ϊ -a4 -a3 a2 a1 ���ֹ�����Ȼ = 0 �����
// �Ľ�
const int N = 110;
int a[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = n; i > n / 2; i--) cout << -a[i] << " ";
		for (int i = n / 2; i >= 1; i--) cout << a[i] << " ";
		cout << endl;
	}

	return 0;
}