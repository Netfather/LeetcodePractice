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

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.empty()) return false;
	if (matrix[0].empty()) return false;
	if (target < matrix[0][0]) return false;
	if (target > matrix[matrix.size() - 1][matrix[0].size() - 1]) return false;
	//Step1: 锁定行数
	int start = 0;
	int end = matrix.size() - 1 ;
	
	while (start < end)
	{
		int middle = start + (end - start) / 2;
		if (matrix[middle][0] == target) return true;
		else if (matrix[middle][0] > target) end = middle - 1;
		else start = middle + 1;
	}
	int col = 0; //锁定行数
	
	if ( matrix[end][0] > target) col = end - 1;
	else if (matrix[end][matrix[0].size() - 1] < target) col = end + 1;
	else col = end;

	start = 0;
	end = matrix[col].size();

	while (start < end)
	{
		int middle = start + (end - start) / 2;
		if (matrix[col][middle] == target) return true;
		else if (matrix[col][middle] > target) end = middle - 1;
		else start = middle + 1;
	}
	if (start < matrix[0].size() && matrix[col][start] == target) return true;
	else return false;
}

int main()
{
	vector<vector<int>> matrix = { { 1},
	{ 3 } };
	cout << searchMatrix(matrix, 2) << endl;
	system("Pause");
	return 0;
}
*/


