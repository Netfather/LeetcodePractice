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

//��ɺܳ�  ��΢�ܽ�һ�¾���
// ����һ����ͼ������ʼ�ߵ���β�� �����ĵط�������
// ͬʱ��ͼ����������  ÿ�����ƶ�һ�� ������Ҳ�����ƶ�һ��   
// ���������˻ᾡ���ܵ��������ߵ�һ�������ϡ� �� �������ٵ������˵�·��

// ���������˻�Ϊ�������  
// �������ڳ�ɭ��ǰһ�̵�λ���Ǿ��Թ̶��ģ��� t =0 ʱ�� ��һ���ڳ�ʼλ��  t = end ʱ�� ��ض��ڳ��ڷ���λ��
// ��ô���������ս����˵���׿� ����һͬ�ƶ�������⣬���� ������ t = st ʱ�� �Ѿ������˳��ڷ���
// ��ô ����������ζ��޷�������ξ����ģ�  ��� ����ֻ��Ҫ����һ�� ���� ����� ������ڷ������̾���
// Ȼ�󿼲�һ�����Ǻ�  �����ʼλ���ƶ�������λ�õľ��� ����

// ����ʱ�临�Ӷ� 10�����η� ���� ִ��bfs��ʱ�临�Ӷ�Ϊ 6�η�   ����������λ�ö����� ��ô��ʱ���Ӷ�Ϊ12�η� ��ʱ�ᳬʱ
// �������ǻ����Ƕ�˼���������  ���Ǵӽ�βλ�ó���  �ҵ��������ֵ�����βλ�õ���̾��뼴�� �����Ǵ��յ㿪ʼ�ѣ�����ȫ����ͼ
// ��ôֻ��Ҫbfsһ�ξͿ���֪�����еĵ���
typedef pair<int, int> PII;
int end_x, end_y; //���ճ��ڿյ�
const int N = 1010;
int dis[N][N]; //��¼��ǰλ�õ����ڿյصľ���
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 }; //��������
int r, c; //��¼�������̵ĺ�������
char g[N][N]; //��¼������ͼ

//���º�����ʼ��dis���飬���ڴ洢�������ֵ� �� �յ�ľ���
void bfs_search(int start_x, int start_y)
{
	//���� dis����
	dis[start_x][start_y] = 0; //��ʼλ�þ��븳ֵ
	queue<PII> q;
	q.push({ start_x,start_y }); //��ʼλ�����

	while (q.size())
	{
		auto curisor = q.front();
		q.pop();

		int cur_x = curisor.first, cur_y = curisor.second;
		for (int d = 0; d < 4; d++)
		{
			int new_x = cur_x + dx[d];
			int new_y = cur_y + dy[d];
			//���ҽ���  ��������Ϲ涨��ʱ��
			// �������ڵ�ͼ��Χ�� �� ���ڵز�Ϊ��ľ  ��  ��ǰλ��û�б��ߵ���
			if (new_x >= 0 && new_x < r && new_y >= 0 && new_y < c && g[new_x][new_y] != 'T' && dis[new_x][new_y] == -1)
			{
				q.push({ new_x,new_y });
				dis[new_x][new_y] = dis[cur_x][cur_y] + 1;
			}
		}
	}
}

int main()
{
	cin >> r >> c;
	int player_x = 0;
	int player_y = 0; //��¼���Լ�����ʼλ��
	memset(dis, -1, sizeof dis); //dis����ֻ��Ҫ��ʼ��һ�ξͿ����� 
	for (int i = 0; i < r; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < c; j++)
		{
			g[i][j] = tmp[j];
			if (tmp[j] == 'S') player_x = i, player_y = j;
			if (tmp[j] == 'E') end_x = i, end_y = j;
		}
	}
	bfs_search(end_x, end_y);
	int dis_level = dis[player_x][player_y];  //��¼��㵽�������Ҫ�߶��ٲ�
	//������ͼ�����е� ��0���ֵ� ͨ��dis���� �������ǵľ���ˮƽ
	int res = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (g[i][j] > '0' && g[i][j] <= '9')
			{
				int dis_judge = dis[i][j];
				if (dis_judge!= -1 &&     dis_judge <= dis_level) res += int(g[i][j] - '0');
			}
		}
	}
	cout << res << endl;
	return 0;
}