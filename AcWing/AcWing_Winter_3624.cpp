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

//1. ���������ҵ�һ���ַ����� �������ָ�����ͬ��λ��  ������ڽ⣬��ô��ʼλ�ñض��Ǵ�����ط���ʼ��
// 2. Ȼ����ά��һ�����µ����ݽṹ
// 3. һ����¼λ�ÿ�ʼ   һ����¼Ѱ�ҵ�����    ��¼λ�ÿ�ʼ�ĵط�ʵʱά��һ����ʼλ�õ����ֵ
// 4. �������Ǿ�����O(N)��ʱ������������

int Table[4]; //���ڼ�¼��λ�õ����ֵ
// �����������һ���ַ���  1123   ��ɨ�赽12��ʱ��  ���¼���� Table[3] = 1, ��������ǵ�����3��ʱ�򣬽��±� - 1 + 1������������
// Ȼ��Ϊ�˱���������⣬���Ƚ�Table��ʼ��һ��������ľ��룬Ȼ��ÿ�θ���һ�¼���

int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		string a;
		cin >> a;

		int res = INT_MAX;
		memset(Table, -0x3f, sizeof Table);
		int i = 0;
		for (; i < a.length() - 1; i++)
		{
			// �õ�  ����� �ͺ�һ��������� ����
			int x = a[i] - '0';
			int x_1 = a[i + 1] - '0';
			// ������������ֲ���ȣ�˵���ҵ�һ����ʼλ�ã�����Table�С�ͬʱ���ݵ���ջ˼��
			// ֮ǰ����� ͬ��λ�õ������Ѿ���ȫû���ˣ����Կ���ֱ�Ӹ���
			if (x != x_1)
			{

				//����λ��
				Table[6 - x - x_1] = i;
			}
			res = min(res, i - Table[x] + 1);
		}
		//�������һ����������һ��û�����������һ������
		res = min(res, i - Table[(a[i] - '0')] + 1);
		// ���res �� a�ĳ��Ȼ�Ҫ�� ˵�����������  Table��ͷ��β��û�и��¹�
		if (res > a.length()) cout << 0 << endl;
		else cout << res << endl;
	}


	return 0;
}