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

// ��������һ�� dp��ʽ 
// f[i][j]��ʾ��i,j��ʼ��������·������
// �洢��ʽΪ ����·�����������ֵ

//����״̬ת��
// f[i][j]һ���ܱ�ʾΪ  max(��Χ4���������ܻ���ȥ�� ���з���)

// ͬʱͨ����֤������֪�� ��������ֵ��ô�ض��Ǵ���ߵ㿪ʼ����
const int N = 310;
int g[N][N];
int f[N][N]; // f[i][j]��ʾ��i,j��ʼ��������·������
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int R, C;
int res = -1;

int SearchDp(int x, int y)
{
	if (f[x][y] != -1) return f[x][y];

	//�鿴һ���µ�
	int tmp_res = 1;  //�Լ�����Ҳ������������Ϊ1
	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (new_x >= 0 && new_x < R && new_y >= 0 && new_y < C)
		{
			if (g[new_x][new_y] < g[x][y]) tmp_res = max(tmp_res,1 + SearchDp(new_x, new_y));  //���ҽ��� �µ�Ϸ� �����ܹ�����ȥ
		}
	}
	f[x][y] = tmp_res;
	return tmp_res;
}



int main()
{
	cin >> R >> C;
	int max_p = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> g[i][j];
		}
	}
		
	memset(f, -1, sizeof f); //��ʼ������״̬  -1 ��ʾ����㻹û�б������
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			res = max(res, SearchDp(i, j));
		}
	}
	cout << res << endl; 
	return 0;
}