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

// ˼·�� ���������������ף������������� �������������У���˶���a�е����֣�ֱ�Ӱ�˳���ҵ���һ����b����֮ƥ��ĵ�Ϳ��ԣ���Ϊ��������ƥ��ɹ���
//����ĵ�Ҳ��ƥ��ɹ��������ڴ�λ�����  ���Թؼ���������

const int N = 100010;
int a[N];
int b[N];


int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int i = 0, j = 0;
	for (; j < m; j++)
	{
		if (b[j] == a[i]) i++;
		// ���ƥ���� �ͽ�i�ƶ�λ�� 
		if (i == n)
		{
			cout << "Yes" << endl;
			return 0;
		}
		//ƥ�䲻�� ��һֱ�ƶ�j
	}
	cout << "No" << endl;

	return 0;
}