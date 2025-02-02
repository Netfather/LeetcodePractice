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

// 由于战舰本身必定是 在某个方向占据1个格子，因此  当战舰是横着放的时候   纵向起始是完全不管的，也就是割裂开的
// 那么可以通过如下方式执行搜索   
// 先横向搜索  搜索连续的 . 区域  数量
// 若数量  < k  则无法放入  
// 若数量  >= k   <  2k - 1 则不能完全填充满  此时 需要 根据 [ 末尾 - k + 1       , base + k - 1 ] 来分别赋值
// 若数量 >= 2k -1  则 [base + k - 1, 末尾  - k + 1]  来分别赋值
// 然后基于上述搜索到的坐标 同样执行纵向搜索

// 这道题似乎只能 横向搜一次 纵向搜一次 然后最后看总的大小 
const int N = 110;
typedef pair<int, int> PII;
int res[N][N];  //存储每个点的方案数
int n, k;
string g[N];  //存储 海域地图

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> g[i];
		g[i] = "?" + g[i]; //添加顶部哨兵
	}
	//统计横向的连续的.的个数
	for (int i = 1; i <= n; i++)
	{
		int base = 0; //起始位置
		int cnt = 0; //记录.的个数
		for (int j = 1; j <= n; j++)
		{
			if (g[i][j] == '.') cnt++;
			else
			{
				base = base + 1;
				if (cnt >= k && cnt < 2 * k - 1)  //此时 类似于  1 2 3 4 5 按照4的窗口 结果是  1 2 2 2 1
				{
					int temp_cnt = 1;
					for (int u = base; u < j - k; u++) res[i][u] += temp_cnt, temp_cnt++;
					for (int u = j - k; u <= base + k - 1; u++)  res[i][u] += temp_cnt;
					--temp_cnt;
					for (int u = base + k; u < j; u++) res[i][u] += temp_cnt, temp_cnt--;
				}
				else if (cnt >= 2 * k - 1) //此时 类似于  1 2 3 4 5 6按照3的窗口 结果是 1 2 3 3 2 1 
				{
					int temp_cnt = 1;
					for (int u = base; u < base + k - 1; u++) res[i][u] += temp_cnt, temp_cnt++;
					for (int u = base + k - 1; u <= j - k; u++)  res[i][u] += temp_cnt;
					--temp_cnt;
					for (int u = j - k + 1; u < j; u++) res[i][u] += temp_cnt, temp_cnt--;
				}
				base = j; //重置起始位置
				cnt = 0; //清空 累加器
			}
		}
		//处理一下尾巴
		if (cnt)
		{
			base = base + 1;
			int j = n + 1;
			if (cnt >= k && cnt < 2 * k - 1)
			{
				int temp_cnt = 1;
				for (int u = base; u < j - k; u++) res[i][u] += temp_cnt, temp_cnt++;
				for (int u = j - k; u <= base + k - 1; u++)  res[i][u] += temp_cnt;
				--temp_cnt;
				for (int u = base + k; u < j; u++) res[i][u] += temp_cnt, temp_cnt--;
			}
			else if (cnt >= 2 * k - 1)
			{
				int temp_cnt = 1;
				for (int u = base; u < base + k - 1; u++) res[i][u] += temp_cnt, temp_cnt++;
				for (int u = base + k - 1; u <= j - k; u++)  res[i][u] += temp_cnt;
				--temp_cnt;
				for (int u = j - k + 1; u < j; u++) res[i][u] += temp_cnt, temp_cnt--;
			}
		}
	}

	//统计纵向的连续的.的个数  这里的逻辑和上面的逻辑是完全一样的  同样还可以在读入的时候就存两份  这样就不用这么绕了
	for (int j = 1; j <= n; j++)
	{
		int base = 0; //起始位置
		int cnt = 0; //记录.的个数
		for (int i = 1; i <= n; i++)
		{
			if (g[i][j] == '.') cnt++;
			else
			{
				base = base + 1;
				if (cnt >= k && cnt < 2 * k - 1)
				{
					int temp_cnt = 1;
					for (int u = base; u < i - k; u++) res[u][j] += temp_cnt, temp_cnt++;
					for (int u = i - k; u <= base + k - 1; u++)  res[u][j] += temp_cnt;
					--temp_cnt;
					for (int u = base + k; u < i; u++) res[u][j] += temp_cnt, temp_cnt--;
				}
				else if (cnt >= 2 * k - 1)
				{
					int temp_cnt = 1;
					for (int u = base; u < base + k - 1; u++) res[u][j] += temp_cnt, temp_cnt++;
					for (int u = base + k - 1; u <= i - k; u++)  res[u][j] += temp_cnt;
					--temp_cnt;
					for (int u = i - k + 1; u < i; u++) res[u][j] += temp_cnt, temp_cnt--;
				}
				base = i; //重置起始位置
				cnt = 0; //清空 累加器
			}
		}
		//处理一下尾巴
		if (cnt)
		{
			base = base + 1;
			int i = n + 1;
			if (cnt >= k && cnt < 2 * k - 1)
			{
				int temp_cnt = 1;
				for (int u = base; u < i - k; u++) res[u][j] += temp_cnt, temp_cnt++;
				for (int u = i - k; u <= base + k - 1; u++)  res[u][j] += temp_cnt;
				--temp_cnt;
				for (int u = base + k; u < i; u++) res[u][j] += temp_cnt, temp_cnt--;
			}
			else if (cnt >= 2 * k - 1)
			{
				int temp_cnt = 1;
				for (int u = base; u < base + k - 1; u++) res[u][j] += temp_cnt, temp_cnt++;
				for (int u = base + k - 1; u <= i - k; u++)  res[u][j] += temp_cnt;
				--temp_cnt;
				for (int u = i - k + 1; u < i; u++) res[u][j] += temp_cnt, temp_cnt--;
			}
		}
	}

	//找到res中最大的那个 该坐标位置即为所求
	PII loc = { 1,1 };
	int len_res = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (res[i][j] > len_res)
			{
				loc = { i,j };
				len_res = res[i][j];
			}
		}
	}

	cout << loc.first << " " << loc.second;



	return 0;
}