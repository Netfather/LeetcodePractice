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

// �����ı��ʾ��� ̰�������������
// ��������˼· ���ǰ�����˵�����Ȼ���Ҷ˵��С����
// �����ǰ��������˵� û�а�������һ�ε�����˵���  ��ô��̰�ĵ�ѡ����һ��
// ��������˼·��һ��©��  �����һ�����䳤���ر�С ������˵�������һ������ ���ַ�ʽ�ƺ��ͻ������
// ���� һ������   ����� [9,20]  [10,11] [12,13]  ��������˼· ��ѡ�� 9,20�� ���Ǻ����� ѡ����������Ը���

// ��� ץס�������ĺ���Ҫ�㣬 �Ǿ��� ��һ����������֮ǰ �������������һ������
// ���Ҫ�����Ҷ˵��С�������� Ȼ������˵�Ӵ�С   Ȼ�󿼲������Ҷ˵㷢���仯�ĵ�  ���������Ƿ����㼴��
// ��Ϊ  �ܷ�ӵ��Ĺؼ� ȡ������ʲôʱ�� �ܹ�������һ��

const int N = 500010;
struct TimeRange
{
	int l;
	int r;

	bool operator < (const TimeRange& w)&
	{
		if (r == w.r) return l > w.l;
		return r < w.r;
	}
}a[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].l >> a[i].r;
	}
	sort(a, a + n); //����
	//��������һ�����кϷ���  �Ҷ˵㷢���仯�ĵ�
	int pre_r = 0; //��¼��һ�ε����Ҷ˵�
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int cur_l = a[i].l, cur_r = a[i].r;
		if (cur_r != pre_r)
		{
			//˵����ο��ܿ��Խӵ� ������Ҫ���� ��ʼʱ��
			if (cur_l > pre_r)
			{
				//���Խӵ�
				res++;
				pre_r = cur_r; //������ֵ
			}
		}
	}
	cout << res << endl;

	return 0;
}