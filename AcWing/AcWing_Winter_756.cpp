// 基础的输出格式控制问题，使用递归同时控制好 递归传递的参数就可以，这里维护好5个递归的参数 就没问题
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


//递归函数 一共要维护5个变量 start_i,start_j代表本次外圈填充的起始坐标，cnt表示起始值，width,height表示外圈的宽高
//void Solution(vector<vector<int>> &res, int start_i, int start_j, int cnt, int width, int height)
//{
//	// 递归终止条件
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
//	//本体函数 填充外圈
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
//	// 递归终止条件
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
//	//本体函数 填充外圈
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
//	//M行 N列的矩阵
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