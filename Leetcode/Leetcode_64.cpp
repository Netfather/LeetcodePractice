/*
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;


int minPathSum(vector<vector<int>>& grid) {
	if (grid.empty()) return 0;
	int m = grid.size(); //行
	int n = grid[0].size(); //列
	//Step1 : 第一行修改,行不动，列变化
	for (int j = 1; j < n; j++)	grid[0][j] = grid[0][j] + grid[0][j - 1];
	//Step2: 第一列修改，列不动，行变化
	for (int i = 1; i < m; i++)	grid[i][0] = grid[i][0] + grid[i - 1][0];
	//Step3: 遍历求解
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
		}
	}
	return grid[m - 1][n - 1];
}
*/
