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


// ����һ����  �������ַ�������һ�β��� �Ƿ�ᵼ��  ����K�ı仯Ϊ2  ���ǲ���
// ���������˻�Ϊ ��ο��ٴ���һ���ַ�������������K ������������ K - target_k
int main()
{
	int t;
	cin >> t;
	for(int u = 1; u <= t; u++)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int score = 0;
		for (int i = 0; i < n / 2; i++)
		{
			if (s[i] != s[n - i - 1]) ++score;
		}
		cout << "Case #"<< u << ": ";
		cout << abs(k - score) << endl;
	}
	return 0;
}