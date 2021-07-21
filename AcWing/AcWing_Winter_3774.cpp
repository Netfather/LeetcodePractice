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

//����Ŀ����˼����  ����ָ����ʱ�� ���ܵ���ai  ���� ָ����ʱ�̱ض�Ϊ����
// ��ô���ǵ���һ�� ����������������ʱ�価���ܳ��� ���ܵ�����
//  1. ���п��ܵ�ѡ��ض��� ai -1 ���� ai + 1Ϊֹ ͨ����֤������֤��
//  2. �����O(1)��ʱ���ڵõ� ������ʱ��
// 

// �۲���������
// ����һ�� a1��a6�Ļ���    ����ʱ����
// 0,a1   a2,a3   a4,a5
//�������x���뵽 0,a1֮�� �ͻ���
// 0,x  a1,a2 a3,a4 a5,a6 ����  ��������� ������Ԥ���������ǰ׺������
// һ�������¼ 0��a1����  ��һ�������¼ a1��a2����

// Ȼ��ʣ�µľ���ö��  ���� ���п���ȡ����λ��  ������ǰ׺������ ��O(1)ʱ���ڵõ�������ʱ��

const int N = 100010;
typedef unsigned long long ULL;
ULL res = 0; //��¼ÿһ�εĽ��
int a[N]; //��һʱ�̱� ��0��ʼ��¼
unordered_set<int> Table; //���ڼ�¼��Ҫָ����ʱ�� �Ƿ��Ѿ�������
ULL s1[N]; //ǰ׺������ ��1��ʼ һ�μ�¼  0,a1  a2,a3����ʱ�̵Ĳ�
ULL s2[N]; //ǰ׺������ ��1��ʼ ÿһ�μ�¼ a1,a2 a3,a4 ����ʱ�̵Ĳ�

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, M;
		cin >> n >> M;
		for (int i = 1; i <= n; i++) cin >> a[i], Table.insert(a[i]);
		Table.insert(0);
		Table.insert(M);
		a[n + 1] = M; //�ڱ�  ��ֹ����Խ��

		// 1. Ԥ����ǰ׺��  ����Ҳ����ֱ�Ӱ� 0 �� M���뵽a�� �����Ͳ���Ҫ������ô�������
		int p1 = 1, p2 = 1;
		for (int i = 1; i <= n; i++)
		{
			// ��¼���� 0,a1 a2,a3  a4,a5������
			if (i % 2)
			{
				//���i������
				//����һ����ʼ״̬
				if (i == 1) s1[p1] = s1[p1 - 1] + (a[i] - 0);
				else s1[p1] = s1[p1 - 1] + (a[i] - a[i - 1]);
				p1++;
			}
			// ��¼���� a1,a2 a3,a4  a5,a6������
			else
			{
				s2[p2] = s2[p2 - 1] + (a[i] - a[i - 1]);
				p2++;
			}
		}
		// ����һ��β��
		if (n % 2)
		{
			//���n������
			s2[p2] = s2[p2 - 1] + (M - a[n]);
			p2++;
		}
		else
		{
			s1[p1] = s1[p1 - 1] + (M - a[n]);
			p1++;
		}

		// Ԫ�ؼ��
		//for (int i = 1; i < p1; i++) cout << s1[i] << " ";
		//cout << endl;
		//for (int i = 1; i < p2; i++) cout << s2[i] << " ";
		//cout << endl;
		//cout << endl;

		// 2. Ȼ��ʼö������
		//ö��һ�� s1 ����  ��S1������ö����ζ�� �Ƿ���ĳ��ʱ���������صƲ�����
		// ����i=1������� ���ڲ���Ϊ���� ֻ��һ���������    ����������������������
		res = s1[p1-1] - s1[0]; //��ʱresΪ���������ص�ѡ��
		ULL tmp = 0;
		for (int i = 1; i < p1; i++)
		{
			tmp = s1[i - 1] - s1[0] + s2[p2 - 1] - s2[i - 1];
			//����һ��  ����Ǹտ�ʼ 0,a1�׶� ��ʱ 
			if (i == 1)
			{
				if (!Table.count(1)) tmp += (a[1] - 1);
			}
			else
			{
				//������±�  �ֶ�ģ��һ�¾����Ƶ����� 
				// ����si�еĵ�i������   ����Ӧ��ԭ�����еķ�Χ ���� 2*i -1 
				if (!Table.count(a[2 * i - 1] - 1)) res = max(res, tmp + (a[2 * i - 1] - 1 - a[2 * i - 2]));
				if (!Table.count(a[2 * i - 3] + 1)) res = max(res,tmp+(a[2 * i - 2] - (a[2 * i - 3] + 1)));
			}
			res = max(res, tmp);
		}
		cout << res << endl;
		res = 0;
		memset(s1, 0, sizeof s1);
		memset(s2, 0, sizeof s2);
		Table.clear();
	}
	return 0;
}