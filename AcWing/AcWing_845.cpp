//思路：

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


// 法1 unordered 大法
//// 这道题的核心在于如何编码一种顺序 使得快速直到这个顺序已经被找过了
//unordered_map<string, int> dis;   // 我们使用哈希map来将每一种可能到达的网格结果存储到dis中
//
//// 这道题的加速方法也很简单  这道题之所以慢的原因在于 以上的unordered速度很慢 最适合这道题的方法就是手写哈希
//string target = "12345678x";
//
//int dx[] = { 0,1,0,-1 };
//int dy[] = { 1,0,-1,0 };
//
//// 然后需要一个函数 这个函数能根据当前string 返回 满足条件的下一个string
////具体思路为 拿到x在string中的位置  根据位置反推出x在网格图中的坐标，然后求得新坐标位置，得到新的string
//int bfs(string start)
//{
//	//初始化dis
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
//				swap(str[idx], str[new_idx]); //还原现场 以便下次得到新的string
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


// 法2 手写哈希大法

// 这道题的核心在于如何编码一种顺序 使得快速直到这个顺序已经被找过了
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

// 这道题的加速方法也很简单  这道题之所以慢的原因在于 以上的unordered速度很慢 最适合这道题的方法就是手写哈希
string target = "12345678x";

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

// 然后需要一个函数 这个函数能根据当前string 返回 满足条件的下一个string
//具体思路为 拿到x在string中的位置  根据位置反推出x在网格图中的坐标，然后求得新坐标位置，得到新的string
int bfs(string start)
{
	//初始化dis
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
				swap(str[idx], str[new_idx]); //还原现场 以便下次得到新的string
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

