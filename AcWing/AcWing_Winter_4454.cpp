//思路：
// 哈希表查询 过于弱智的题目

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
#include <cstring>
#include <climits>
using namespace std;


unordered_set<int> hash_check;
int res = 0;

int main()
{
	int n, k;
	cin >> n >> k;
	hash_check.insert(0); //在这道题中 0表示常量 常量的赋值一定是合法的
	while (k--)
	{
		int xi, yi;
		cin >> xi >> yi;
		if (!hash_check.count(yi)) res++;
		hash_check.insert(xi);
	}
	cout << res << endl;
}