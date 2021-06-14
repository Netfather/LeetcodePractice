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

// 由于题目没有详细说明，所以这里特别说明一下，是可以重复选取的
// 那么问题这样就可以进一步退化，首先取值范围是一定可以满足的
// 因此实际上关键就是 2 3 两条性质。
// 我们在选取的时候，直接保证  中位数的值不小于y  然后在这个条件下 找到 所有元素和的最小值
// 查看这个最小值是否不大于x即可  因此问题退化为 如何保证 中位数的值不小于y
// 按照中位数的性质， 在最后成型的数组中，必定有 n / 2个 小于y的  必定有 n/2 + 1个 大于等于y的
// 那么我们对于未完成的数组补充  就行  

// 补充 需要保证最后的和必定不大于x 因此将等于y和大于y划分到一起是没有问题的，这样可以保证 小于y的部分尽量的长
// 但是如果中位数的目标值恰好是 最小取值下界，那么此时就会有问题。 因此这种情况需要特判一下

const int N = 1004;
int w[N];

int main()
{
	int n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;
	int cnt_less_y = 0, cnt_larg_y = 0; //存储已知数组中 小于y 和大于y的个数
	int sum_smlst = 0; //存储数组可能达到的最小的和

	for (int i = 0; i < k; i++)
	{
		cin >> w[i];
		if (w[i] < y) ++cnt_less_y;
		else ++cnt_larg_y;
		sum_smlst += w[i];
	}
	// 特判一下 y是否正好在取值的下界
	if (y == 1)
	{
		// 如果y是1 那么取值只有可能取1，不存在其他可能
		sum_smlst += (n - k); 
		if (sum_smlst > x)
		{
			cout << -1 << endl;
			return 0;
		}
		for (int i = 0; i < n - k; i++) cout << 1 << " ";
		return 0;
	}
	//判断是否存在合理方案
	if (cnt_less_y > n / 2 || cnt_larg_y > n / 2 + 1 || sum_smlst > x) cout << -1 << endl;
	else
	{
		//填入对应个1 和对应个y
		sum_smlst += (n / 2 - cnt_less_y) * 1 + (n / 2 + 1 - cnt_larg_y ) * y;
		if (sum_smlst > x)
		{
			cout << -1 << endl;
			return 0;
		}
		for (int i = 0; i < n / 2 - cnt_less_y; i++) cout << 1 << " ";
		for (int i = 0; i < n / 2 + 1 - cnt_larg_y ; i++) cout << y << " ";
	}
	return 0;
}