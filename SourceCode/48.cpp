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

void rotate(vector<vector<int>>& matrix) {
	vector<vector<int>> res(matrix.size(), vector<int>(matrix.size(),0));
	int i = 0;
	int j = matrix.size() - 1;
	for (vector<int> m : matrix)
	{
		i = 0;
		for (int n : m)
		{
			res[i++][j] = n;
		}
		j--;
	}
	matrix.clear();
	matrix = res;
}

int main()
{
	vector<vector<int>> input = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	rotate(input);
	for (vector<int> m : input)
	{
		for (int n : m)
		{
			cout << n << "  ";
		}
		cout << endl;
	}
	system("Pause");
	return 0;

}
*/