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
//�����Ǻܻ�����dp���⣬���ǿ��Ժ����Եĵõ����ۣ�����վ�������е�ĳ���㣬������ֵֻ������������ߺ������еĽϴ���Ǹ�


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int r, c;
		cin >> r >> c; //����������
		vector<vector<int>> dp(r + 1, vector(c + 1, 0));
		//dp״̬���� ���ڴ洢���㴦��i��jλ��ʱ���㵱ǰ��ȡ�õ��������
		//���ڱ߽�����ȫΪ0��������ﲻ��Ҫ���б߽��ʼ��
		for (int i = 1; i <= r; i++)
		{
			for (int j = 1; j <= c; j++)
			{
				int tmp;
				cin >> tmp;
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + tmp;
			}
		}
		cout << dp[r][c] << endl;
	}
	return 0;
}