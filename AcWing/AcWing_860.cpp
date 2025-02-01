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

//���ڶ���ͼ���ж�  һ������ͼ�Ƿ��Ƕ���ͼ����˼��ָ �ܷ�ʹ�����ֲ�ͬ����ɫ����һ��ͼ������Ⱦ���������֣�
// ����������� ���ǿ����� 1 2 ���ֱ�Ⱦɫ��ͬ�Ķ��� ʹ��������flood fill�㷨
// ������ flood fill�㷨��������ȫһ��  ֻ��������ص�˼����˵��� ͼ������
int n, m;
const int N = 1000010;
int e[N], ne[N], h[N], idx;
void add(int x, int y)
{
	e[idx] = y;
	ne[idx] = h[x];
	h[x] = idx++;
}

int colors[N]; //���ڲ�ѯĳ�����㱻Ⱦɫ��ʲô��ɫ
bool Pending(int x,int color)  //�����Ϊx�Ķ��� ȾɫΪcolor��ɫ
{
	//if (colors[x])
	//{
	//	if (colors[x] == color) return true;
	//	else return false;
	//}
	//��������û�б�Ⱦɫ
	colors[x] = color; //���ڱ�Ⱦɫ�� Ȼ�����һ�������������ٱ�
	for (int i = h[x]; i != -1; i = ne[i])
	{
		int index = e[i];
		if (colors[index] && colors[index] != 3 - color) return false;
		if (!colors[index])  //��������û�б������ɫ ��ô�ͽ���dfs����
		{
			if (!Pending(index, 3 - color)) return false;  //���һ������Ա�ȾɫΪĿ����ɫ �ͽ���Ⱦɫ Ȼ��
		}
	}
	return true;
}


int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	//���ڿ������ͼ����ĳЩ�㲻��ͨ ���Ա������һ�����еĶ���
	for (int i = 1; i <= n; i++)
	{
		if (!colors[i] && !Pending(i, 1))
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}