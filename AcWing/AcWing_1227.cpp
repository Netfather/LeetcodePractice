//思路：

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

//实现一个函数，对于给定的边长S，给定的一块巧克力，这块巧克力能划分为多少部分
int Split(int S, vector<int> &cholo)
{
	int height, weight;
	height = cholo[0];
	weight = cholo[1];
	int large = height, small = weight;
	if (height < small)
	{
		large = weight;
		small = height;
	}
	if (S >small) return 0;
	return (small / S) * (large /S);
}


bool check(int mid, vector<vector<int>> &Cholo,int K)
{
	int res = 0;
	for (auto i : Cholo)
	{
		res += Split(mid, i);
	}
	if (res > K) return false;
	return true;
}



int main()
{
	int N, K;
	cin >> N >> K;

	vector<vector<int>> Cholo(N,vector<int>(2,-1));

	for (int i = 0; i < N; i++)
	{
		cin >> Cholo[i][0] >> Cholo[i][1];
	}

	int l = 0;
	int r = 100000;

	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		if (check(mid, Cholo,K)) r = mid - 1;
		else l = mid;
	}

	cout << l << endl;
	system("Pause");
	return 0;
}