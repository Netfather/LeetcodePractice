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
int w[N];  //表示存储的原数组
int s[N];  //表示从1开始加到第i个元素 （包括第i个 的和

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> w[i];

 //处理前缀和
	for (int i = 1; i <= n; i++)
	{
		s[i] = w[i]+ s[i - 1];
	}
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		cout << s[r] - s[l - 1] << endl;

	}


	return 0;
}