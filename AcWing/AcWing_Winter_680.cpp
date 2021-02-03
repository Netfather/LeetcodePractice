//Ë¼Â·£º

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
#include <iomanip>
using namespace std;

bool check(double mid, vector<int>& Ropes, int M)
{
	int cnt = 0;
	for (auto i : Ropes)
	{
		cnt += i / mid;
	}
	if (cnt >= M) return false;
	return true;
}


int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> Ropes(N, -1);
	for (int i = 0; i < N; i++) cin >> Ropes[i];

	double episl = 1e-4;
	double l = 0, r = 1e9;

	while (r - l > episl)
	{
		double mid = (l + r) / 2;
		if (check(mid, Ropes, M)) r = mid;
		else l = mid;
	}
	printf("%.2f", l);
	return 0;
}