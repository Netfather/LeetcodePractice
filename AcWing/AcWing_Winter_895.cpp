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

// �ǳ��ǳ������ ��������������⣬
// ͬʱ��������������е��ر���� ���� һһ��Ӧ�Ĺ�ϵ
const int N = 1010;
int w[N];
int f[N]; //��iΪ�յ������������еĳ���


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	// ��iΪ0ʱ�򣬲�����Ԫ�� ��˳���Ϊ0
	f[0] = 0;
	int res = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		f[i] = 1; //���ٰ����Լ�
		for (int j = 1; j < i; j++)
		{
			if (w[i] > w[j]) f[i] = max(f[j] + 1, f[i]);
		}
		res = max(res, f[i]);
	}
	cout << res << endl;
	return 0;
}