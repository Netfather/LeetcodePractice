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

//1. �۲��֪�����������϶�����ѭ0��n�ٵ�0
//2. Ȼ������������������չֱ������0Ϊֹ
// 3.���ǿ��ǵ���ʽ���Ƶķ���
// ���Ƕ��� i j �ֱ���� ��������ܴ����ͺ�����ܴ���
// u k �ֱ���� �ڵ�ǰ��һ��������ҪԤ���Ŀո�  �Լ�  �ڵ�ǰ��һ���������������
// t���� ��Ҫ����Ĵ���  ����� C++ �г˷� �ַ����˷����� �Ϳ��Բ������ѭ��

const int N = 14;
int g[N][N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0,u = 0; i < (2 * n + 1); i++)
	{
		for (int t = 0; t < n - u; t++) cout << "  ";
		for (int j = 0,k = 0; j < (2 * u + 1); j++)
		{
			if (j < u) cout << k++ << " ";
			else cout << k-- << " ";
		}
		cout << endl;
		if (i < n) u++;
		else (u--);
	}

	return 0;
}