//思路：
// 简单的小小模拟 白给题

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

const int N = 15;
int w[N], s[N];

float Jidian(int score)
{
	if (score >= 90 && score <= 100) return 4.0;
	else if (score >= 85 && score <= 89) return 3.7;
	else if (score >= 82 && score <= 84) return 3.3;
	else if (score >= 78 && score <= 81) return 3.0;
	else if (score >= 75 && score <= 77) return 2.7;
	else if (score >= 72 && score <= 74) return 2.3;
	else if (score >= 68 && score <= 71) return 2.0;
	else if (score >= 64 && score <= 67) return 1.5;
	else if (score >= 60 && score <= 63) return 1.0;
	else return 0;
}
int main()
{
	int n;
	cin >> n;
	int sum_w = 0;
	float sum_s = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
		sum_w += w[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		sum_s += Jidian(s[i]) * w[i];
	}
	printf("%.2f", sum_s / sum_w);
	return 0;
}