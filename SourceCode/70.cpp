
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

int climbStairs(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	vector<int> res(n, 0);
	res[0] = 1;
	res[1] = 2;
//	int res_temp = 0;

	for (int i = 2; i < n; i++)	res[i] = res[i - 2] + res[i - 1];
	return res[n-1];
}

int main()
{
	cout << climbStairs(4) << endl;
	system("Pause");
	return 0;
}
*/
