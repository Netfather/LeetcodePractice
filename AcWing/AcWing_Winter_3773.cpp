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

//���������ε����߹�ϵ   ���� ��һ������������Ϊ a b c
// ��ô c�ĳ��ȱض���     0 < c < a + b
// ��ô��ӳ������� �������ӿ��������������ĵ㣬�Ǿ���ζ�� ֻҪ x����  0 �� a+b�ķ�Χ ��ô�ض��������Ϳ��������ˡ�
// ���ÿһ�μ�鶼�����ж�  ���� cal_dis ������ ��  (start,0) ��ʼ �� (x,0)�Ĵ�������


typedef unsigned long long ULL;
const int N = 100010;
int a[N];
int cnt = 0;// ��¼�ܹ�����Ծ����
unordered_set<int> Table; //��¼ĳ�������Ƿ���ֹ�
int x, n;
ULL max_a = 0; //���ڱ���a�е����ֵ   ���ڲ��̶�����ʹ�ô��������������ķ��� Ӧ���ǲ�ͣ�Ļ��� max_a������Ծ

//�� start ��ʼ��Ծ
void cal_dis(int start)
{
	//�ݹ���ֹ����1  ������ǡ����a������
	if (Table.count(x - start))
	{
		cnt++;
		return; //��Ծ1�� ֱ�ӷ���
	}
	//�ݹ���ֹ����2  ������ǡ���� �����β���ʽ��
	else if ((x - start) > 0 && ULL(x - start) < ULL(max_a * 2)) //��������б�int�ķ���
	{
		cnt = cnt + 2;
		return; //��ʱһ���ܹ��������� �����Ծ2�� ֱ�ӷ���
	}
	//��ʱ��ζ���޷�����������  x�ľ��볬���������ṩ�����Χ ��ʱ��Ҫ�ƶ���ʼλ��
	cnt = cnt + (x - start) / max_a - 1;  //�ƶ�max_a�ľ���  ����Ҫ��ǰԤ���� 1��max_a ��һЩ�ľ��� 
	//�������ؽ���һ��ΪʲôҪ -1   ��Ϊ�������ǰ����  ��d�ر�С x�ر�������� ʱ�临�ӶȻ������� ���� d= 1 x = 10000000�������
	//��������Ĳ���ʽ ���ǿ��Եõ�  �ܵ���һ���� �ض��� ���� >= max_a * 2
	// ����һ���� ���������� �� ���� ��С��  [max_a, 2*max_a) ֮�� ʹ�ÿ���ͨ����������ѭ��ֱ�ӵõ����
	// ��ô ���Ǵ�ʱ�ƶ������ʱ��  ��Ծ��max_a������Ӧ����  ����/max_a  - 1>= 2 - 1 ʹ��ʣ�µľ���ض��� ������Χ�ڡ� 
	// Ȼ�������O(1)��ʱ���ڶ�ÿ��ѯ�� �ҵ�����ˡ�
	cal_dis(start+ ((x - start) / max_a - 1) * max_a);
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> x;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (max_a < a[i]) max_a = a[i]; //��¼���ֹ������ֵ
			Table.insert(a[i]); //�洢��ѯ��
		}
		cal_dis(0);
		cout << cnt << endl;
		//ִ�����
		Table.clear(); //��ղ�ѯ��
		max_a = 0; //�������ݴ�
		cnt = 0;//��մ�
	}
	return 0;
}