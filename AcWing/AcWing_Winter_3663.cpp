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

//1. 观察可知从中轴线自上而下遵循0到n再到0
//2. 然后按照中轴线往两边延展直到减到0为止
// 3.但是考虑到格式控制的方便
// 我们定义 i j 分别代表 在纵向的总次数和横向的总次数
// u k 分别代表 在当前这一个纵行需要预留的空格  以及  在当前这一个横行输出的数字
// t代表 需要输出的次数  如果有 C++ 有乘法 字符串乘法重载 就可以不用这个循环

const int N = 14;
int g[N][N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0,u = 0; i < (2 * n + 1); i++)
	{
		for (int t = 0; t < n - u; t++) cout << "  ";
		for (int j = 0,k = 0; j < (2 * u + 1); j++)
		{
			if (j < u) cout << k++ << " ";
			else cout << k-- << " ";
		}
		cout << endl;
		if (i < n) u++;
		else (u--);
	}

	return 0;
}