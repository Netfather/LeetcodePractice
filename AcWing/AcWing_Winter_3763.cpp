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

//�۲���Ե�֪���ͼ����ż��������
// ��ô�ض�����ͨ�� ��β��� ʵ�ֽ�ͼ�е����и�����Ϊ����
// ���������������
// ��ô���ǿ��԰Ѹ���ת�Ƶ� ����ֵ��С���Ǹ�Ԫ����
// ����ʵ����һ�ִ�����˼��  �������µ����
// a ,x ,x ,x ,x ....(n��x) ,b    (���a b ����ͬһ�У�����Խ�ֱ����ֱ������������ֵ�����)
// ��ô����֤��  �� a b��Ϊ������ʱ�� �ض�����ͨ����������� ������a�ĸ��Ŵ��ݵ� b��ǰһ����ȥ
// ��ʱ ���һ���� a b ��һ�β��� ���ɽ� a b ���������
// ���˲���Ψһ�������õľ���  ԭ������ ����������������ʱ����ͨ�����ϲ��� ������ת�Ƶ�����ֵ��С���Ǹ�����ȥ �ý⡣
const int N = 11;
int g[N][N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		int res = 0;
		int min_abs = INT_MAX; //��¼����ֵ��С���Ǹ���
		int cnt_neg = 0;  //��¼�����ĸ���
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> g[i][j];
				if (g[i][j] < 0) cnt_neg++;
				res += abs(g[i][j]);
				min_abs = min(min_abs, abs(g[i][j]));
			}
		}
		if (cnt_neg % 2)
		{
			//˵���ض�����һ�������޷���Ϊ��
			cout << res - 2 * min_abs << endl;
		}
		else cout << res << endl;
	}
	return 0;
}