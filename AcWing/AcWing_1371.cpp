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

//const int V = 25;
//int Bi[V];
//int cnt = 0;
//long long sum = 0;
//
////�˷��mȻ�Y�����_ ���ǳ��r
////ʹ�ñ��������ǲ��m�ϵġ�
//void dfs(int target,int v,int start)
//{
//	//��ֹ�����ж���
//	if (sum >= target)
//	{
//		if (sum == target) cnt++;
//		return;
//	}
//
//	for (int i = start; i < v; i++)
//	{
//		if (sum + Bi[i] <= target)
//		{
//			sum += Bi[i];
//			dfs(target, v, i);
//			sum -= Bi[i]; //�ָ��ֳ�
//		}
//		else return;
//	}
//}

//ʹ��dp����}
const int V = 30;
const int N = 10010;

long long dp[V][N];
//�@��dp��ʾ ��1����i��؛�ţ������x��ʹ�üӺ͞�N�ķ����ж��ٷN��

int main()
{
	int v,n;
	cin >> v >> n;
	dp[0][0] = 1;//�@һ�N������ʾʲ�N�����x
	for (int i = 1; i <= v; i++)
	{
		int v;
		cin >> v;
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j]; //�ȰѲ�������ǰݔ��Ĕ�����ʹ�üӺ͞�j�Ĕ�������
			//Ȼ���Д࣬�����ǰݔ��Ĕ�����jС���f����ǰ�Ĕ��������ۼӣ��˕r�����ϱ��εļӺ�
			if (j >= v) dp[i][j] += dp[i][j - v];
		}
	}
	cout << dp[v][n] << endl;
	return 0;
}