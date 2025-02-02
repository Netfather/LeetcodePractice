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

vector<vector<int>> generateMatrix(int n) {
	int index = 0;
	vector<vector<int>> res(n, vector<int>(n, 0));

	int i = 0;
	int j = 0;
	int k = 0; // i
	int l = 0; // j

	while (index < n*n)
	{
		i = k;
		j = l;
		//-> 右向搜索
		if (i == k && j == l)
		{
			while (j < n - l - 1) res[i][j++] = ++index;
			if (index == n * n - 1)
			{
				res[i][j] = index + 1;
				break;
			};
		}
		if (i == k && j == n - l-1) 
		{
			while (i < n - k - 1) res[i++][j] = ++index;
		}
		if (i == n - k-1 && j == n - l -1)
		{
			while (j > l) res[i][j--] = ++index;
			if (index == n * n - 1 )
			{
				res[i][j] = index + 1;
				break;
			};
		}
		if (i == n - k - 1 && j == l)
		{
			while (i > k) res[i--][j] = ++index;
		}
		++l, ++k;
	}
	return res;
}

int main()
{
	vector<vector<int>> res = generateMatrix(4);
	for (auto m : res)
	{
		for (auto n : m)
		{
			cout << n << "   ";
		}
		cout << endl;
	}
	system("Pause");
	return 0;
}
*/