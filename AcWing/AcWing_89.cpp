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
#define ull unsigned long long

ull quick_pow(ull a, ull b, ull p)
{
	if (b == 0) return 1 % p;
	a %= p;
	ull res = quick_pow(a, b >> 1, p);
	if (b & 1) return res * res%p*a%p;
	return res * res%p;
}
int main()
{
	int a, b, p;
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> a >> b >> p;
	cout << quick_pow(a, b, p) << endl;
	return 0;
}
