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

//通过观察  操作特性 我们可以发现  这种操作 配合 指定位置的字符串序列 可以简化为如下模式
// 只要为1的部分 那么该位置和其后一个位置的数字 只要保证 范围正确即可   
// 0的部分就像是挡板， 阻断了 1之间的连接
// 例如 1 0 1 这种  前1 之前的数字 永远不可能传递到 后1 部分 
// 因此判断能否变为升序数组的  充要条件1就是   确保1 或者连续1 部分的数字  处于正确数组的范围内
// 充要条件2 确保 连续0部分的数字  百分百对应 

//下面举个例子来说明 这道题的思路
// 例如我们有一个字符串是  0110001010
// 根据上面的认知 我们知道 0的作用就像是阻断器 阻断了1之间的连接 这就意味着连续1 内包含的数字需要 在正确的范围内 这是充要条件1
// 而只考虑连续1还不行，我们还需要考虑到 连续0 连续0中 0的位置必须保证位置完全正确 这是充要条件2
// 所以这道题考虑用双指针的形式， 一个指针p_1用于 遍历整个 字符串标志位  一个指针p_2用于记录 连续1的起始位置 方便判断


const int N = 200010;
int w[N];
int flags[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	string flags;
	cin >> flags;
	flags = "?" + flags + "0";  //额外添加末尾哨兵元素， 末尾哨兵也不可能往后走 因为已经没有元素了， 所以状态也为0

	int prev = 0; //存储上一次的 flags中标志   注意下标为0的元素 也就是-1位置，由于1号元素不可能往前走 所以prev的起始状态为0
	int p_1 = 1;// 指针1 用于探查 flags中的序列
	int p_2 = 1;// 指针2 用于记录本次探查的起始位置 方便判断

	for (; p_1 <= n;)
	{
		//用于遍历p_2时候，存储范围内元素的最大最小值
		int max_temp = INT_MIN;
		int min_temp = INT_MAX;
		//充要条件2判断，如果出现了连续的0 那么我们必须保证当前的元素 必定是在正确位置上的
		if (prev == 0 && flags[p_1] == '0')
		{
			//本次为连续0的第二个  
			if (w[p_1] != p_1)
			{
				cout << "NO" << endl;
				return 0;
			}
			//更新指针 和  上一次的prev
			prev = 0;
			p_1++;
			p_2 = p_1;
		}
		// 此时为可能的起始位置  此时需要对p_2记录p_1位置 
		else if (prev == 0 && flags[p_1] == '1')
		{
			p_2 = p_1;
			p_1++;
			prev = 1;
		}
		// 充要条件1 判断，连续1到了尽头  此时需要判断 [p2,p1]范围内数字是否在正确范围
		else if (prev == 1 && flags[p_1] == '0')
		{
			int lower_bound = p_2;
			//此时说明连续1 到头了
			while (p_2 <= p_1)
			{
				max_temp = max(w[p_2], max_temp);
				min_temp = min(w[p_2], min_temp);
				p_2++;
			}
			if (max_temp > p_1 || min_temp < lower_bound)
			{
				cout << "NO" << endl;
				return 0;
			}
			//更新指针 和 上一次的prev
			p_1++;
			prev = 0;
		}
		// 连续1的时候   更新必要参数即可
		else if (prev == 1 && flags[p_1] == '1') p_1++, prev = 1;
	}

	cout << "YES" << endl;
	return 0;
}