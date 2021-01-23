
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


void setZeroes(vector<vector<int>>& matrix) {
	if (matrix.empty()) return;
	vector<int> Hang;
	vector<int> Lie;
	int flag_i = 0;
	int flag_j = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			flag_i = 0;
			flag_j = 0;
			if (matrix[i][j] != 0) continue;
			else if (matrix[i][j] == 0)
			{
				for (auto m : Hang)
				{
					if (m == i)
					{
						flag_i = 1;
						break;
					}
				}
				for (auto n : Lie)
				{
					if (n == j)
					{
						flag_j = 1;
						break;
					}
				}
				if (flag_i == 0 && flag_j == 0)
				{
					Hang.push_back(i);
					Lie.push_back(j);
				}
				else if (flag_i == 0 && flag_j == 1) Hang.push_back(i);
				else if (flag_i == 1 && flag_j == 0) Lie.push_back(j);
			}
		}
	}

	for (auto m : Hang)
	{
		int j = 0;
		while (j < matrix[0].size()) matrix[m][j++] = 0;
	}
	for (auto n : Lie)
	{
		int i = 0;
		while (i < matrix.size()) matrix[i++][n] = 0;
	}
}

*/