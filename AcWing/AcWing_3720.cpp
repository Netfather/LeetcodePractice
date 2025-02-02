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

const int N = 55;
int a[N];
int b[N];
int target[N];

int main()
{
	int T;
	cin >> T;
Label:	while (T--)
	{
		int n, x;
		cin >> n >> x;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < n; i++) target[i] = x - a[i];
		sort(target, target + n);
		sort(b, b + n);
		for (int i = 0; i < n; i++)
		{
			if (b[i] > target[i])
			{
				cout << "No" << endl;
				goto Label;
			}
		}
		cout << "Yes" << endl;
	}
	return 0;
}