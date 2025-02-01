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

//根据三角形的三边关系   例如 有一个三角形三边为 a b c
// 那么 c的长度必定是     0 < c < a + b
// 那么反映到这道题 由于兔子可以跳到无理数的点，那就意味着 只要 x落入  0 到 a+b的范围 那么必定是两步就可以跳到了。
// 因此每一次检查都这样判断  函数 cal_dis 负责处理 从  (start,0) 开始 到 (x,0)的次数计算


typedef unsigned long long ULL;
const int N = 100010;
int a[N];
int cnt = 0;// 记录总共的跳跃次数
unordered_set<int> Table; //记录某个数字是否出现过
int x, n;
ULL max_a = 0; //用于保存a中的最大值   由于不固定距离使用次数，因此最优秀的方法 应该是不停的基于 max_a进行跳跃

//从 start 开始跳跃
void cal_dis(int start)
{
	//递归终止条件1  当距离恰好在a数组中
	if (Table.count(x - start))
	{
		cnt++;
		return; //跳跃1次 直接返回
	}
	//递归终止条件2  当距离恰好在 三角形不等式内
	else if ((x - start) > 0 && ULL(x - start) < ULL(max_a * 2)) //这里可能有爆int的风险
	{
		cnt = cnt + 2;
		return; //此时一定能构成三角形 因此跳跃2次 直接返回
	}
	//此时意味着无法构成三角形  x的距离超出了所能提供的最大范围 此时需要移动起始位置
	cnt = cnt + (x - start) / max_a - 1;  //移动max_a的距离  但是要提前预留出 1个max_a 多一些的距离 
	//这里着重解释一下为什么要 -1   因为如果不提前跳步  在d特别小 x特别大的情况下 时间复杂度会有问题 例如 d= 1 x = 10000000这种情况
	//根据上面的不等式 我们可以得到  能到这一步的 必定是 距离 >= max_a * 2
	// 而这一步的 本质意义是 将 距离 缩小到  [max_a, 2*max_a) 之间 使得可以通过上面两个循环直接得到结果
	// 那么 我们此时移动距离的时候  跳跃的max_a次数就应该是  距离/max_a  - 1>= 2 - 1 使得剩下的距离必定在 上述范围内。 
	// 然后就能在O(1)的时间内对每个询问 找到结果了。
	cal_dis(start+ ((x - start) / max_a - 1) * max_a);
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> x;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (max_a < a[i]) max_a = a[i]; //记录出现过的最大值
			Table.insert(a[i]); //存储查询表
		}
		cal_dis(0);
		cout << cnt << endl;
		//执行清空
		Table.clear(); //清空查询表
		max_a = 0; //清空最大暂存
		cnt = 0;//清空答案
	}
	return 0;
}