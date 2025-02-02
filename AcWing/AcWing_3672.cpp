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


const int N = 110;
int w[N];

bool cmp(int x, int y) {
	return x > y;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> w[i];
		sort(w, w + n,cmp);
		for (int i = 0; i < n; i++) cout << w[i] <<" ";
		cout << endl;
	}
	return 0;
}