//˼·�� ʹ��flood fill�㷨  ���� dfs ��  bfs ��ͨ��ģ�壬����ģ��ο�OneDrive�е���ͼ����һ�ֽ��flood fill����ǳ����õ�һ�ַ���

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
#include <climits>
using namespace std;

int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };



//�Y�����_ ����һ��ʼ��ʱ�ˣ�����Ĺؼ�����һ��ʼû�д���� bfs�ı߽������ж������¶��ظ����˺ܶ��
// ����Ҫ�㣺 ����bfs һ������ͨ�����п��Թ���һ��ģ�壬Ȼ�����Ǳ��뱣֤ÿһ��ֻ���Լ���Ȼ��ʣ�µ�δ����ģ�������ӣ������к����Ĵ���
// һ���������޸��ж�������ʱ������ӵ�ʱ�򣬾��޸ģ�Ȼ����ӵ�Ԫ�أ����ǿ��Բ�����if�ж�����ֱ�ӽ���++����
//int bfs(vector<vector<char>> &Blocks, int start_x, int start_y, int width, int height)
//{
//
//	queue<int> q_x;
//	queue<int> q_y;
//
//	int cnt = 0;
//	q_x.push(start_x);
//	q_y.push(start_y);
//
//	while (!q_x.empty())
//	{
//		
//		int now_x = q_x.front();
//		int now_y = q_y.front();
//		q_x.pop();
//		q_y.pop();
//
//		cnt++; //��������ӵ�ʱ����Ѿ���ʾ���ʹ��ˣ���˳��ӵ�ʱ������һ�㲻��Ҫ�����ж���ֱ�ӽ��++�Ϳ���
//		//if (Blocks[now_x][now_y] == '.')
//		//{
//		//	Blocks[now_x][now_y] = '#';
//		//	cnt++;
//		//}
//
//		for (int d = 0; d < 4; d++)
//		{
//			int a = now_x + dx[d], b = now_y + dy[d];
//			if (a >= 0 && a < height && b >= 0 && b < width && Blocks[a][b] == '.')
//			{
//				Blocks[a][b] = '#';  //�������޸ı�־λ����ʾ����ط��Ѿ����ʹ���
//				q_x.push(a);
//				q_y.push(b);
//			}
//		}
//	}
//	return;
//}
//
//
//int main()
//{
//	while (true)
//	{
//		int cnt = 0;
//		int width = -1, height = -1;
//		cin >> width >> height;
//		if (width == 0) break;
//		int start_x = 0, start_y = 0;
//		vector<vector<char>> Blocks(height, vector<char>(width, 'a'));
//		for (int i = 0; i < height; i++)
//		{
//			for (int j = 0; j < width; j++)
//			{
//
//				cin >> Blocks[i][j];
//				if (Blocks[i][j] == '@')
//				{
//					start_x = i;
//					start_y = j;
//					Blocks[i][j] = '#';
//				}
//			}
//		}
//		int res = bfs(Blocks, start_x, start_y, width, height);
//		cout << res << endl;
//	}
//	return 0;
//}



#define x first
#define y second
typedef pair<int, int> PII;


//���Ӽ���ʹ��pair�� ����洢����
//int bfs(vector<vector<char>> &Blocks, int start_x, int start_y, int width, int height)
//{
//	queue<PII> q;
//	q.push({ start_x,start_y });
//	int cnt = 0;
//
//	while (!q.empty())
//	{
//		int now_x = q.front().x;
//		int now_y = q.front().y;
//		q.pop();
//		cnt++;
//
//		for (int d = 0; d < 4; d++)
//		{
//			int a = now_x + dx[d], b = now_y + dy[d];
//			if (a >= 0 && a < height && b >= 0 && b < width && Blocks[a][b] == '.')
//			{
//				Blocks[a][b] = '#';
//				q.push({ a,b });
//			}
//		}
//	}
//	return cnt ;
//}
//
//
//int main()
//{
//	while (true)
//	{
//		int cnt = 0;
//		int width = -1, height = -1;
//		cin >> width >> height;
//		if (width == 0) break;
//		int start_x = 0, start_y = 0;
//		vector<vector<char>> Blocks(height, vector<char>(width, 'a'));
//		for (int i = 0; i < height; i++)
//		{
//			for (int j = 0; j < width; j++)
//			{
//
//				cin >> Blocks[i][j];
//				if (Blocks[i][j] == '@')
//				{
//					start_x = i;
//					start_y = j;
//					Blocks[i][j] = '.';
//				}
//			}
//		}
//		cnt = bfs(Blocks, start_x, start_y, width, height);
//		cout << cnt << endl;
//	}
//	return 0;
//}



//��3 ʹ��flood fill�� dfsд��
int dfs(vector<vector<char>>& Blocks, int x, int y, int width, int height)
{
	int res = 1; //��ǰ�Լ����Ҫ������
	//����ǰ����Ϊ��ɫש��
	Blocks[x][y] = '#';

	for (int d = 0; d < 4; d++)
	{
		int new_x = x + dx[d], new_y = y + dy[d];
		if (new_x >= 0 && new_x < height && new_y >= 0 && new_y < width && Blocks[new_x][new_y] == '.')
		{
			res += dfs(Blocks, new_x, new_y, width, height);
		}
	}
	return res;
}


//int main()
//{
//	int width = -1, height = -1;
//	while (cin >> width >> height && width!= 0)
//	{
//		int start_x = 0, start_y = 0;
//		vector<vector<char>> Blocks(height, vector<char>(width, 'a'));
//		for (int i = 0; i < height; i++)
//		{
//			for (int j = 0; j < width; j++)
//			{
//
//				cin >> Blocks[i][j];
//				if (Blocks[i][j] == '@')
//				{
//					start_x = i;
//					start_y = j;
//					Blocks[i][j] = '.';
//				}
//			}
//		}
//		int res = dfs(Blocks, start_x, start_y, width, height);
//		cout << res << endl;
//	}
//	return 0;
//}

