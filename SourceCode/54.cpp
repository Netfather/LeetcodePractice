
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


vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	if (matrix.empty()) return res;

	int m = matrix.size();
	int n = matrix[0].size();

	int k = 0;
	int l = 0;
	int i = 0; //m
	int j = 0; //n

	while ( res.size() < m * n)
	{
		i = k;
		j = l;
		if ( i == k &&  j == l)
		{
			while (j < n - l - 1) res.push_back(matrix[i][j++]);
			if (res.size() == m * n - 1)
			{
				res.push_back(matrix[i][j]);
				break;
			};
			//l++;
		}
		if (i == k && j == n - l - 1)
		{
			while (i < m - k - 1) res.push_back(matrix[i++][j]);
		//	if (res.size() == m * n) break;
			//k++;
		}
		if (i == m - k - 1 && j == n - l -1)
		{
			while (j > l) res.push_back(matrix[i][j--]);
			if (res.size() == m * n - 1)
			{
				res.push_back(matrix[i][j]);
				break;
			};
		}
		if (i == m - k - 1 && j == l )
		{
			while (i > k ) res.push_back(matrix[i--][j]);
			//if (res.size() == m * n) break;
		}
		++l;
		++k;
	}
	return res;
}

int main()
{
	vector<vector<int>> matrix = { { 1, 2, 3},
	{ 5, 6, 7 },
	{ 9, 10, 11}
	};
	vector<int> res;
	res = spiralOrder(matrix);

	for (auto k : res)
	{
		cout << k << "  ";
	}

	system("Pause");


}

*/