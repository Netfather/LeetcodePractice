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
using namespace std;

double eps = 1e-7;

int main()
{
	double x;
	cin >> x;

	double l = -10000, r = 10000;

	while (r - l >= eps)
	{
		double mid = (l + r) / 2;
		if (mid * mid * mid >= x) r = mid;
		else l = mid;
	}

	printf("%6f", r);
	return 0;
}