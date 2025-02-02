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



int main()
{
	int n;
	cin >> n;
	string a;
	cin >> a;

	int cnt_x = 0;// 记录有多少个连续的x
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 'x')
		{
			if (cnt_x >= 3) res += cnt_x - 2;
			cnt_x = 0; //处理完成  记录清空
		}
		else cnt_x++;
	}
	//处理一下尾巴
	if (cnt_x >= 3) res += cnt_x - 2;
	cout << res << endl;
	return 0;
}