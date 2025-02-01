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
int w[N], tmp[N];
long int res = 0;

void Nixu(int start, int end)
{
	if (start >= end) return;

	int mid = start + end >> 1;

	Nixu(start, mid);
	Nixu(mid + 1, end);

	//归并
	int p_1 = start, p_2 = mid + 1;
	int tmp_cur = 0;

	while (p_1 <= mid && p_2 <= end)
	{
		//此处考虑逆序对，对于每一次从归并的过程，假设两个序列 前向序列p1 代表的为 x1,x2,x3 后向序列p2 代表的为 y1,y2,y3
		// 注意到这里每一个前向序列的坐标都是小于后向序列的 满足逆序对条件1
		// 那么如果此时在前向序列中存在一个 xi 他大于后向序列中的某个 yj
		// 可以得到 x1 < x2 < ...  < xi < yj 因此其前面的所有长度统统为逆序对的数量
		if (w[p_1] <= w[p_2]) tmp[tmp_cur++] = w[p_1++];
		else
		{
			res += mid - p_1 + 1;
			tmp[tmp_cur++] = w[p_2++];
		}
	}
	while (p_1 <= mid) tmp[tmp_cur++] = w[p_1++];
	while (p_2 <= end) tmp[tmp_cur++] = w[p_2++];

	for (int i = start, k = 0; i <= end; i++, k++) w[i] = tmp[k];
	return;
}



int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	Nixu(1, n);
	cout << res << endl;
	return 0;
}