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

//首先移动是说选取一个连续1构成的   那么有可能选择是 出这样的位置 [l,r] l-1位置为0  r+1位置为1
//这样是只能往左边移动的，但是这种情况会把本来聚集到一起的1分离出来，因此这种情况是绝对不可能被选到的
// 基于以上证明 我们可以得到一个结论： 每次移动的连续1区间 必定是被两个0夹在一起的，在这种情况下，
// 我们在读入1的时候，连续的1 只需要写一次1 即可


// 关于移动位置，其实等效于 移动一格， 为了将所有的1聚集在一起使得移动次数最小  我们可以通过遍历枚举的方式
// 即假定最后的聚集位置区间为  [m,n] 计算从当前位置转移到 m,n所需要的最短距离即可
// 这时问题就退化为 给定一个区间  然后给定一个离散01序列，将这个序列 移动为 这个区间的最小代价是多少？
// 以上推论错误  实际上的操作 在操作过程中会裹挟已经聚集到一起的 1 一起运动 因此我们只需要统计 第一个1 到最后一个1之间有多少个0
// 就可以了

const int N = 55;
int w[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(w, 0, sizeof w);
		int n;
		cin >> n;
		int w_prev = 0;
		int tail = 1;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			// 将连续的1 只记录一次
			if (x == w_prev && x == 1) continue;
			w[tail++] = x;
			w_prev = x;
		}
		// 计算从第一个1 到最后一个1之间 有多少个0
		vector<int> tmp;
		for (int i = 1; i < tail; i++)
		{
			if (w[i] == 1) tmp.push_back(i); //每当找到1  就把1对应的索引存储下来
		}
		//cout << tmp.back() << " " << tmp.front() << " " << tmp.size() << endl;
		cout << tmp.back() - tmp.front() + 1 - tmp.size() << endl;

	}
	return 0;
}

