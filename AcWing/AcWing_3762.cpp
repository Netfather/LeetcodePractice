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

//可以证明 所有的2*2的矩阵 必定可以通过如下方式进行转换使得 矩阵内所有结果成为  0 0 0 0
//  1 1   ==>  0 0    ==> 0 1   ==>  1 1    ==> 0 0
//  1 1		   0 1        1 0        0 1        0 0

// 由于这道题最最最麻烦的地方在于 需要 输出操作中的元素坐标 因此 倒不如直接写个查找表 囊括所有情况进行输出

typedef pair<int, int> PII;
const int N = 30010;
vector<PII> Op[N]; //用于存储每次操作的坐标
int tail = -1; //用于指向Op数组的尾在哪里
const int M = 110;
int g[M][M];

//输入一个 2*2 子矩阵的 左上位置坐标 从1开始计算  ，注意由输入端维护操作的合法性。
// 当然完全不用这么麻烦 只需要记录哪个坐标没变就可以了
void Operation(int x, int y)
{
	if (g[x][y] == 0 && g[x + 1][y] == 0 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 0)
	{
		return;
	}
	// 4个1的情况 查找
	if (g[x][y] == 1 && g[x + 1][y] == 1 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x,y });
		g[x][y] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 0;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 0;
		Operation(x, y);
	}
	// 1个1 的情况 查找
	if (g[x][y] == 1 && g[x + 1][y] == 0 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x,y });
		g[x][y] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 1;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 1;
		Operation(x, y);
	}
	if (g[x][y] == 0 && g[x + 1][y] == 1 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x,y });
		g[x][y] = 1;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 0;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 1;
		Operation(x, y);
	}
	if (g[x][y] == 0 && g[x + 1][y] == 0 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x,y });
		g[x][y] = 1;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 1;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 0;
		Operation(x, y);
	}
	if (g[x][y] == 0 && g[x + 1][y] == 0 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x + 1,y + 1 });
		g[x + 1][y + 1] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 1;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 1;
		Operation(x, y);
	}

	// 2个1 的情况查询  
	if (g[x][y] == 1 && g[x + 1][y] == 1 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x + 1,y + 1 });
		g[x + 1][y + 1] = 1;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 0;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 1;
		Operation(x, y);
	}
	if (g[x][y] == 1 && g[x + 1][y] == 0 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x + 1,y + 1 });
		g[x + 1][y + 1] = 1;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 1;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 0;
		Operation(x, y);
	}
	if (g[x][y] == 1 && g[x + 1][y] == 0 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x + 1,y + 1 });
		g[x + 1][y + 1] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 1;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 1;
		Operation(x, y);
	}

	if (g[x][y] == 0 && g[x + 1][y] == 1 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x ,y });
		g[x][y] = 1;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 0;
		Op[tail].push_back({ x + 1,y + 1 });
		g[x + 1][y + 1] = 1;
		Operation(x, y);
	}

	if (g[x][y] == 0 && g[x + 1][y] == 1 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x ,y });
		g[x][y] = 1;
		Op[tail].push_back({ x ,y + 1 });
		g[x][y + 1] = 1;
		Op[tail].push_back({ x + 1,y + 1 });
		g[x + 1][y + 1] = 0;
		Operation(x, y);
	}

	if (g[x][y] == 0 && g[x + 1][y] == 0 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x ,y });
		g[x][y] = 1;
		Op[tail].push_back({ x ,y + 1 });
		g[x][y + 1] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 1;
		Operation(x, y);
	}
	// 处理3个1的情况
	if (g[x][y] == 1 && g[x + 1][y] == 1 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 0)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x ,y });
		g[x][y] = 0;
		Op[tail].push_back({ x ,y + 1 });
		g[x][y + 1] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 0;
		Operation(x, y);
	}
	if (g[x][y] == 1 && g[x + 1][y] == 1 && g[x][y + 1] == 0 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x ,y });
		g[x][y] = 0;
		Op[tail].push_back({ x + 1 ,y + 1 });
		g[x + 1][y + 1] = 0;
		Op[tail].push_back({ x + 1,y });
		g[x + 1][y] = 0;
		Operation(x, y);
	}
	if (g[x][y] == 1 && g[x + 1][y] == 0 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x ,y });
		g[x][y] = 0;
		Op[tail].push_back({ x + 1 ,y + 1 });
		g[x + 1][y + 1] = 0;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 0;
		Operation(x, y);
	}
	if (g[x][y] == 0 && g[x + 1][y] == 1 && g[x][y + 1] == 1 && g[x + 1][y + 1] == 1)
	{
		tail++;
		Op[tail].clear();
		Op[tail].push_back({ x + 1 ,y });
		g[x + 1][y] = 0;
		Op[tail].push_back({ x + 1 ,y + 1 });
		g[x + 1][y + 1] = 0;
		Op[tail].push_back({ x,y + 1 });
		g[x][y + 1] = 0;
		Operation(x, y);
	}
	return;
}

int main()
{
	int T;
	cin >> T;
	int n, m;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			string tmp;
			cin >> tmp;
			for (int j = 1; j <= m; j++)
				g[i][j] = tmp[j - 1] - '0';
		}
		tail = -1; //tail空置
		for (int i = 1; i < n; i = i + 2)
		{
			for (int j = 1; j < m; j = j + 2)
			{
				Operation(i, j);
			}
		}
		//处理奇数情况
		if (n % 2)
		{
			if (m % 2)
			{
				for (int k = 1; k < m; k = k + 2)
				{
					Operation(n - 1, k);
				}
				for (int k = 1; k < n; k = k + 2)
				{
					Operation(k, m - 1);
				}
			}
			else if (m % 2 == 0)
			{
				for (int k = 1; k < m; k = k + 2)
				{
					Operation(n - 1, k);
				}
			}
		}
		else if (n % 2 == 0)
		{
			if (m % 2)
			{
				for (int k = 1; k < n; k = k + 2)
				{
					Operation(k, m - 1);
				}
			}
		}
		//输出结果
		cout << tail + 1 << endl;
		for (int i = 0; i <= tail; i++)
		{
			for (auto element : Op[i])
			{
				cout << element.first << " " << element.second << " ";
			}
			cout << endl;
		}
	}
	return 0;
}