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


// ��1 unordered ��
//// �����ĺ���������α���һ��˳�� ʹ�ÿ���ֱ�����˳���Ѿ����ҹ���
//unordered_map<string, int> dis;   // ����ʹ�ù�ϣmap����ÿһ�ֿ��ܵ�����������洢��dis��
//
//// �����ļ��ٷ���Ҳ�ܼ�  �����֮��������ԭ������ ���ϵ�unordered�ٶȺ��� ���ʺ������ķ���������д��ϣ
//string target = "12345678x";
//
//int dx[] = { 0,1,0,-1 };
//int dy[] = { 1,0,-1,0 };
//
//// Ȼ����Ҫһ������ ��������ܸ��ݵ�ǰstring ���� ������������һ��string
////����˼·Ϊ �õ�x��string�е�λ��  ����λ�÷��Ƴ�x������ͼ�е����꣬Ȼ�����������λ�ã��õ��µ�string
//int bfs(string start)
//{
//	//��ʼ��dis
//	dis[start] = 1;
//	queue<string> q;
//	q.push(start);
//
//	while (q.size())
//	{
//		string str = q.front();
//		string tmp = str;
//		q.pop();
//
//		int idx = str.find('x');
//
//		int x = idx / 3;
//		int y = idx % 3;
//
//		for (int d = 0; d < 4; d++)
//		{
//			int new_x = x + dx[d];
//			int new_y = y + dy[d];
//			int new_idx = new_x * 3 + new_y;
//			if (new_x >= 0 && new_x < 3 && new_y >= 0 && new_y < 3)
//			{
//				swap(str[idx], str[new_idx]);
//				if (dis[str] == 0)
//				{
//					dis[str] = dis[tmp] + 1;
//					q.push(str);
//				}
//				if (str == target) return dis[str];
//				swap(str[idx], str[new_idx]); //��ԭ�ֳ� �Ա��´εõ��µ�string
//			}
//		}
//		
//	}
//	return 0;
//}
//
//
//int main()
//{
//	string a;
//	for (int i = 0; i < 9; i++)
//	{
//		string tmp;
//		cin >> tmp;
//		a += tmp;
//	}
//	cout << bfs(a) - 1 << endl;
//	return 0;
//}


// ��2 ��д��ϣ��

// �����ĺ���������α���һ��˳�� ʹ�ÿ���ֱ�����˳���Ѿ����ҹ���
const int N = 100000010;
int dis[N];
typedef unsigned long long ULL;
int P = 13331;
ULL h[10];

ULL hash_string(string a)
{
	a = "?" + a;
	for (int i = 1; i <= 9; i++)
	{
		h[i] = h[i - 1] * P + a[i];
	}
	return h[9] % N;
}

// �����ļ��ٷ���Ҳ�ܼ�  �����֮��������ԭ������ ���ϵ�unordered�ٶȺ��� ���ʺ������ķ���������д��ϣ
string target = "12345678x";

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

// Ȼ����Ҫһ������ ��������ܸ��ݵ�ǰstring ���� ������������һ��string
//����˼·Ϊ �õ�x��string�е�λ��  ����λ�÷��Ƴ�x������ͼ�е����꣬Ȼ�����������λ�ã��õ��µ�string
int bfs(string start)
{
	//��ʼ��dis
	dis[hash_string(start)] = 1;
	queue<string> q;
	q.push(start);

	while (q.size())
	{
		string str = q.front();
		string tmp = str;
		q.pop();

		int idx = str.find('x');

		int x = idx / 3;
		int y = idx % 3;

		for (int d = 0; d < 4; d++)
		{
			int new_x = x + dx[d];
			int new_y = y + dy[d];
			int new_idx = new_x * 3 + new_y;
			if (new_x >= 0 && new_x < 3 && new_y >= 0 && new_y < 3)
			{
				swap(str[idx], str[new_idx]);
				if (dis[hash_string(str)] == 0)
				{
					dis[hash_string(str)] = dis[hash_string(tmp)] + 1;
					q.push(str);
				}
				if (str == target) return dis[hash_string(str)];
				swap(str[idx], str[new_idx]); //��ԭ�ֳ� �Ա��´εõ��µ�string
			}
		}

	}
	return 0;
}


int main()
{
	string a;
	for (int i = 0; i < 9; i++)
	{
		string tmp;
		cin >> tmp;
		a += tmp;
	}
	cout << bfs(a) - 1 << endl;
	return 0;
}

