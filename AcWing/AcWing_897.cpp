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

//��������dp���� ά������һ��dp����
// dp[i][j] ��ʾ A�ַ��� �� 1��i���Ӵ� �� B�ַ�����1��j���Ӵ�  �����Ӵ������й���������   ����Ϊ���ȵ����ֵ
// ����״̬ת��
// ������ǲ�ѡ��i��λ�ã� ��ô ���Ϊ  dp[i-1][j]
// �������ѡ��i��λ�� ��ô ���Ǿ�Ҫ��B�� ��1��jѰ�� �ҵ����� ��k ʹ�� B[k] = A[i] Ȼ��max( dp[i-1][k-1] + 1)
// ������������ᱬʱ�临�Ӷȣ���ô���ǿ����Ż��ڵ�㣬 ���� ��������һ���������ǰ����е�k���ҳ����� ����ʼ��û��Ҫ��
// ����ֻ��Ҫ�� jλ����ǰɨ���ҵ���һ����A[i]��ȵĵ㣬 ����ǰ�ĵ㶼���ظ��������⣬����Ҫ���ǡ�����ʱ�临�Ӷ�������O{n����}



// ���� ���� ����Ҳ���Բ��û��ֵ���ôϸ����������ص������������
// ֱ�ӿ���  ��� Ai == Bj ��ô��ѡ  �����������ȣ����ǲ�Ҫi ���߲�Ҫj  ����ʱ�临�ӶȻή�͵ĺܵͺܵ�

const int N = 1010;
int dp[N][N];

int main()
{
	int n, m;
	cin >> n >> m;
	string A, B;
	cin >> A >> B;
	A = "?" + A;
	B = "?" + B;

	//��ʼ���  ���� dp[0][0]���������ʱA,BΪ�ռ������ڳ��� Ϊ0 ��˲���Ҫ��ʼ��
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			//�ȴ���ѡi�����
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			//���ѡ��i
			for (int k = j; k >= 0; k--)
			{
				if (B[k] == A[i])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][k - 1] + 1);
					break;
				}
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}