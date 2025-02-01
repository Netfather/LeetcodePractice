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

const int N = 100010;
int S[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> S[i];
	}
	//由于要求在使得 n1-n2尽可能小，那么看n奇偶就知道了
	//然后两个划分尽可能大。我们可以通过反证法证明
	//对于一个已经排序好的数组，使得两个划分的和尽可能大的划分，就是前后对半分
	sort(S, S + n);
	int S1 = 0, S2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (i <= n / 2-1) S1 += S[i];
		else S2 += S[i];
	}
	cout << n % 2 << " " << S2 - S1 << endl;
	return 0;
}