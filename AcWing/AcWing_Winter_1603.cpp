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
int S[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> S[i];
	}
	//����Ҫ����ʹ�� n1-n2������С����ô��n��ż��֪����
	//Ȼ���������־����ܴ����ǿ���ͨ����֤��֤��
	//����һ���Ѿ�����õ����飬ʹ���������ֵĺ;����ܴ�Ļ��֣�����ǰ��԰��
	sort(S, S + n);
	int S1 = 0, S2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (i <= n / 2-1) S1 += S[i];
		else S2 += S[i];
	}
	cout << n % 2 << " " << S2 - S1 << endl;
	return 0;
}