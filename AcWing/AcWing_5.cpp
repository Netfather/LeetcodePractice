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

// �����Ϊ ���ر�������Ķ������Ż�����
// ������˼·�� AcWing�� 3483���˼·��һ����  �� ����ܹ���ÿ����Ʒ����Ϊ2���ݴ�
// Ϊʲô����Ϊ2���ݴ� �����ԭ������
// ��� ĳ����Ʒһ����11��   ������������ж������Ż����  ֱ��ö�� һ��Ҫö��0��11  һ��12��
// ����������ж������Ż�  �������Ʒ ���»���Ϊ   1����Ʒһ��Ϊ��1    1����Ʒ2����Ʒһ��Ϊ��2  4����Ʒһ��Ϊ��3  4����ƷΪһ��Ϊ��4
// ��ô���������˻�Ϊ��01�������� ��������0��11���κ����� ���Ƕ�����ֻȡ4�����е�������������ÿһ��ֻȡ1�Σ��������ʵ��
// ��ô��ʱ���������˻�Ϊ�� 0 1 ��������  ������Ҫʵ��һ������ �˺����ܹ���  vi si wi תΪ �µ� 01 ����µ� vi wi
const int N = 1010;
int vi[N], si[N], wi[N];
const int M = 10010;  // 
int f[M];
int vi_new[M], wi_new[M];
int tail_new = 1; //�µ�ת���õ�01 ������ĩβ

// ����һ����Ʒ�ı��i  ���ǽ������Ʒת��Ϊ ��Ӧ 01 ���������µ�ȫ�µ� vi_new  wi_new
void Convert(int i)
{
	int num = 1; //��1����Ʒ ����Ϊ�� ��1��ʼ
	for (int u = 1; u <= si[i]; u++)
	{
		vi_new[tail_new] = vi[i] * num;
		wi_new[tail_new++] = wi[i] * num;
		si[i] -= num;
		if (si[i] < num * 2) break; //˵����ʱ�޷�������2���� ֱ������ѭ��
		num = num * 2; // ��1������ ��ʼ��2����
	}
	//�������ѭ������β�� ��ֱ�ӽ�β�������һ������
	if (si[i])
	{
		vi_new[tail_new] = vi[i] * si[i];
		wi_new[tail_new++] = wi[i] * si[i];
	}
	return;
}


int main()
{
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> vi[i] >> wi[i] >> si[i];
	}
	//��ÿһ����Ʒ����ӵ�еĸ��� ������
	for (int i = 1; i <= n; i++) Convert(i);
	// ��  vi_new wi_new���µ� 0 1�������⶯̬�滮
	// ����ʹ�ö�ά��01�����ᵼ������Խ��  ����ҪתΪ 1ά��01��������ⷨ
	// ����ʲô����ѡ�����ڼ�ֵ ���Բ���Ҫ��f���г�ʼ��
	for (int i = 1; i < tail_new; i++)
	{
		for (int j = v; j >= vi_new[i]; j--)
		{
			f[j] = max(f[j - vi_new[i]] + wi_new[i], f[j]);
		}
	}

	cout << f[v] << endl;
	return 0;
}