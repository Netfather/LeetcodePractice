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


//����ͨ����֤�����ǿ���֤��  ���յĵĽ� �ض��ǻ�����k���������
// Ȼ�������Ȱ���������   Ȼ���վ���ֵ������5������ ��β��ͷ ���ֳ����ɸ��� ������ΪS
// ����S��ȡ�� ǰk��  �������鼴Ϊ��
const int N = 5010;
int w[N];
int s[N];
int f[N][N];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> w[i];
	sort(w+1, w + n+1);
	//˫ָ��Ԥ����һ�� ���������굽����
	int i= 1, j = 1;
	for (; j <= n; j++)
	{
		while ( i <= n && w[j] - w[i] > 5) i++;
		s[j] = i;
	}
	//ʹ��dp���
	for (int i = 1; i <= n; i++) //��1��i��Ԫ����ѡ
	{
		for (int j = 1; j <= k; j++) //ѡj������з���
		{
			f[i][j] = max(f[i - 1][j], f[s[i] - 1][j - 1] + i - s[i] + 1);
		}
	}

	cout << f[n][k] << endl;
	return 0;
}