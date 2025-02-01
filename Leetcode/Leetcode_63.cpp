
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


int uniquePaths(vector<vector<int>>& obstacleGrid, int m, int n) {
	vector<vector<long int>> c(n, vector<long int>(m, 1));

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (obstacleGrid[i][j] == 1) c[i][j] = 0;
		}
	}

	int flag = 0;
	for (int i = 1; i < n; i++)
	{
		if (obstacleGrid[i][0] == 1)
		{
			c[i][0] = 0;
			flag = 1;
		}
		if (flag == 1) c[i][0] = 0;
	}

	flag = 0;
	for (int j = 1; j < m; j++)
	{
		if (obstacleGrid[0][j] == 1)
		{
			c[0][j] = 0;
			flag = 1;
		}
		if (flag == 1) c[0][j] = 0;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (c[i][j] != 0) c[i][j] = c[i - 1][j] + c[i][j - 1];
		}
	}
	return c[n - 1][m - 1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	if (obstacleGrid.empty()) return 0;
	if (obstacleGrid[0][0] == 1) return 0;
	return uniquePaths(obstacleGrid, obstacleGrid[0].size(), obstacleGrid.size());
}


int main()
{
	vector<vector<int>> obstacleGrid = {{0, 0}, { 1, 1}, { 0, 0}};
	cout << uniquePathsWithObstacles(obstacleGrid) << endl;
	system("Pause");
	return 0;
}
*/
