// �����������ʽ�������⣬ʹ�õݹ�ͬʱ���ƺ� �ݹ鴫�ݵĲ����Ϳ��ԣ�����ά����5���ݹ�Ĳ��� ��û����
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


//�ݹ麯�� һ��Ҫά��5������ start_i,start_j��������Ȧ������ʼ���꣬cnt��ʾ��ʼֵ��width,height��ʾ��Ȧ�Ŀ��
//void Solution(vector<vector<int>> &res, int start_i, int start_j, int cnt, int width, int height)
//{
//	// �ݹ���ֹ����
//	int i_iter = start_i;
//	int j_iter = start_j;
//
//	if (width == 0 || height == 0) return;
//	if (width == 1)
//	{
//		while (i_iter < start_i + height)
//		{
//			res[i_iter][j_iter] = cnt;
//			cnt++;
//			i_iter++;
//		}
//		return;
//	}
//	else if (height == 1)
//	{
//		while (j_iter < start_j + width)
//		{
//			res[start_i][j_iter] = cnt;
//			cnt++;
//			j_iter++;
//		}
//		return;
//	}
//
//	//���庯�� �����Ȧ
//	while (j_iter < start_j + width)
//	{
//		res[i_iter][j_iter] = cnt;
//		cnt++;
//		j_iter++;
//	}
//	j_iter--;
//	i_iter++;
//	while (i_iter < start_i + height)
//	{
//		res[i_iter][j_iter] = cnt;
//		cnt++;
//		i_iter++;
//	}
//	i_iter--;
//	j_iter--;
//	while (j_iter >= start_j)
//	{
//		res[i_iter][j_iter] = cnt;
//		cnt++;
//		j_iter--;
//	}
//	j_iter++;
//	i_iter--;
//	while (i_iter > start_i)
//	{
//		res[i_iter][j_iter] = cnt;
//		cnt++;
//		i_iter--;
//	}
//	Solution(res, i_iter + 1, j_iter + 1, cnt, width - 2, height - 2);
//	return;
//}


//void Solution(vector<vector<int>> &res, int start_i, int start_j, int cnt, int width, int height)
//{
//	// �ݹ���ֹ����
//	int i_iter = start_i;
//	int j_iter = start_j;
//
//	if (width == 0 || height == 0) return;
//	if (width == 1)
//	{
//		while ((i_iter < start_i + height) && (res[i_iter++][j_iter] = cnt++)) {}
//		return;
//	}
//	else if (height == 1)
//	{
//		while ((j_iter < start_j + width) && (res[i_iter][j_iter++] = cnt++)) {}
//		return;
//	}
//
//	//���庯�� �����Ȧ
//	while ((j_iter < start_j + width) && (res[i_iter][j_iter++] = cnt++)){}
//	j_iter--;
//	i_iter++;
//	while ((i_iter < start_i + height) && (res[i_iter++][j_iter] = cnt++)){}
//	i_iter--;
//	j_iter--;
//	while ((j_iter >= start_j) && (res[i_iter][j_iter--] = cnt++)){}
//	j_iter++;
//	i_iter--;
//	while ((i_iter > start_i) && (res[i_iter--][j_iter] = cnt++)){}
//	Solution(res, i_iter + 1, j_iter + 1, cnt, width - 2, height - 2);
//	return;
//}
//
//int main()
//{
//	int M = 0;
//	int N = 0;
//	cin >> M >> N;
//	//M�� N�еľ���
//	vector<vector<int>> Matrix(M, vector<int>(N, 0));
//	Solution(Matrix, 0, 0, 1, N, M);
//	for (auto i : Matrix)
//	{
//		for (auto j : i)
//		{
//			cout << j << " ";
//		}
//		cout << endl;
//	}
//	system("Pause");
//	return 0;
//}


//ʹ�÷����������dx dy������
//int main()
//{
//	int M, N = -1;
//	cin >> M >> N;
//
//	vector<vector<int>> Matrix(M, vector<int>(N, INT_MIN));
//	����ƫ������
//	int dy[] = { 0,1,0,-1 }, dx[] = {-1,0,1,0};
//	int d = 1; //��ʼ����Ϊ1  
//	int x = 0, y = 0;
//
//	for (int cnt = 1; cnt <= M * N; cnt++)
//	{
//		Matrix[x][y] = cnt;
//		int a = x + dx[d], b = y + dy[d];
//		if (a < 0 || a > M - 1 || b < 0 || b > N - 1 || Matrix[a][b] != INT_MIN)
//		{
//			d = (d + 1) % 4; //�������ײǽ��������ô����d�ķ���
//			a = x + dx[d];
//			b = y + dy[d]; //������һ�ε�����
//		}
//		x = a;
//		y = b;
//	}
//	for (auto i : Matrix)
//	{
//		for (auto j : i)
//		{
//			cout << j << " ";
//		}
//		cout << endl;
//	}
//	system("Pause");
//	return 0;
//}