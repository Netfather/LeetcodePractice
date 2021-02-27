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

typedef pair<long int, long int> LL;

//这道题分成如下几个关键步骤
//1. 首先这道题如果不考虑标记相同星座，而是只考虑标记，是一道flood fill算法
//2. 然后，如果考虑相同这个概念，我们使用哈希思想，对每个星空图生成一个独有标记，相同星空图的标记会非常相近
//3. 最后，如何生成标记，使用点到点距离的和即可。注意一定要开平方，否则生成的标记不能唯一

const int W = 110, H = 110;
char Map[H][W]; // 用于存储星空图
const int NUM = 31;  
float Hash[NUM]; // 用于存储哈希值的数组，
char Color[NUM]; //用于存储某个已经存在哈希值数组的坐标，应该填充哪个颜色
int Hash_end = 0; //用于存储哈希表的结束位置
char cursor = 'a'; //用于存储如果当前的哈希值是没有出现过的，那么应该填充哪个颜色

//此函数用于生成对应于某块图形的哈希特征值
float Gerate_Flag(vector<LL> &S)
{
	double res = 0;
	for (int i = 0; i < S.size(); i++)
	{
		for (int j = i + 1; j < S.size(); j++)
		{
			res += sqrt((S[i].first - S[j].first) * (S[i].first - S[j].first) + (S[i].second - S[j].second) * (S[i].second - S[j].second));
		}
	}
	return res;
}

//此函数用于根据输入的S，来填充颜色，如果是已经存在的，那么填充已经存在的颜色，如果不存在那么填充全新的颜色
void Fill(vector<LL> S)
{
	double flag = Gerate_Flag(S);
	for (int i = 0; i < Hash_end; i++)
	{
		//距离足够小 说明是一个已经存在的图形，那么直接填充Color中存储的对应颜色，然后直接返回
		if (abs(Hash[i] - flag) < 1e-6)
		{
			for (int j = 0; j < S.size(); j++)
			{
				Map[S[j].first][S[j].second] = Color[i];
			}
			return;
		}
	}
	//如果遍历完都没有返回，说明这个哈希值是一个全新的特征，需要改变Hash Color Cursor 和 Hash_end4个变量
	Hash[Hash_end] = flag; //存入新特征值
	Color[Hash_end] = cursor;
	for (int j = 0; j < S.size(); j++)
	{
		Map[S[j].first][S[j].second] = cursor;
	}
	cursor++;
	Hash_end++;
	return;
}

//最基本的flood fill 算法，首先是特征改变，每当你进入了DFS，就需要改变当前的特征避免再次进入时 然后是条件判断区，用于表示周围连通块哪些地方是满足条件的
void dfs(int i, int j, int w, int h, vector<LL> &S)
{
	//特征改变区
	Map[i][j] = '0';
	S.push_back(pair(i, j));


	//条件判断区
	for (int x = i - 1; x <= i + 1; x++)
	{
		for (int y = j - 1; y <= j + 1; y++)
		{
			if (x == i && y == j) continue;
			else
			{
				if (x >= 0 && x < h && y >= 0 && y < w && Map[x][y] == '1') dfs(x, y, w, h, S);
			}
		}
	}
}

int main()
{
	int w, h;
	cin >> w >> h;

	for (int i = 0; i < h; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < w; j++)
		{
			Map[i][j] = tmp[j];
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (Map[i][j] == '1')
			{
				vector<LL> S;
				dfs(i, j, w, h, S);
				Fill(S);
				S.clear();
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << Map[i][j];
		}
		cout << endl;
	}
	return 0;
}