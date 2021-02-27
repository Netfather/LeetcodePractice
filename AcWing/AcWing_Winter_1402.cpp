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

typedef pair<long int, long int> LL;

//�����ֳ����¼����ؼ�����
//1. �����������������Ǳ����ͬ����������ֻ���Ǳ�ǣ���һ��flood fill�㷨
//2. Ȼ�����������ͬ����������ʹ�ù�ϣ˼�룬��ÿ���ǿ�ͼ����һ�����б�ǣ���ͬ�ǿ�ͼ�ı�ǻ�ǳ����
//3. ���������ɱ�ǣ�ʹ�õ㵽�����ĺͼ��ɡ�ע��һ��Ҫ��ƽ�����������ɵı�ǲ���Ψһ

const int W = 110, H = 110;
char Map[H][W]; // ���ڴ洢�ǿ�ͼ
const int NUM = 31;  
float Hash[NUM]; // ���ڴ洢��ϣֵ�����飬
char Color[NUM]; //���ڴ洢ĳ���Ѿ����ڹ�ϣֵ��������꣬Ӧ������ĸ���ɫ
int Hash_end = 0; //���ڴ洢��ϣ��Ľ���λ��
char cursor = 'a'; //���ڴ洢�����ǰ�Ĺ�ϣֵ��û�г��ֹ��ģ���ôӦ������ĸ���ɫ

//�˺����������ɶ�Ӧ��ĳ��ͼ�εĹ�ϣ����ֵ
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

//�˺������ڸ��������S���������ɫ��������Ѿ����ڵģ���ô����Ѿ����ڵ���ɫ�������������ô���ȫ�µ���ɫ
void Fill(vector<LL> S)
{
	double flag = Gerate_Flag(S);
	for (int i = 0; i < Hash_end; i++)
	{
		//�����㹻С ˵����һ���Ѿ����ڵ�ͼ�Σ���ôֱ�����Color�д洢�Ķ�Ӧ��ɫ��Ȼ��ֱ�ӷ���
		if (abs(Hash[i] - flag) < 1e-6)
		{
			for (int j = 0; j < S.size(); j++)
			{
				Map[S[j].first][S[j].second] = Color[i];
			}
			return;
		}
	}
	//��������궼û�з��أ�˵�������ϣֵ��һ��ȫ�µ���������Ҫ�ı�Hash Color Cursor �� Hash_end4������
	Hash[Hash_end] = flag; //����������ֵ
	Color[Hash_end] = cursor;
	for (int j = 0; j < S.size(); j++)
	{
		Map[S[j].first][S[j].second] = cursor;
	}
	cursor++;
	Hash_end++;
	return;
}

//�������flood fill �㷨�������������ı䣬ÿ���������DFS������Ҫ�ı䵱ǰ�����������ٴν���ʱ Ȼ���������ж��������ڱ�ʾ��Χ��ͨ����Щ�ط�������������
void dfs(int i, int j, int w, int h, vector<LL> &S)
{
	//�����ı���
	Map[i][j] = '0';
	S.push_back(pair(i, j));


	//�����ж���
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