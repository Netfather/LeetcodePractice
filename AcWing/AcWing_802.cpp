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

// 相当复杂的一道题  分步骤来看
// 第一步 关于在某一位置x 加上c 这个点该怎么看
//   一个n长度的数组， 数据类型位pair 里面记录了哪些位置+c  那么等效于 给定一个数组，数组索引位pair中的first 元素 数组对应位置元素位second元素
// 通过这个方式 我们可以把这个在无限长数轴上进行操作的问题，投影到一个 n长的数组上来 然后使用前缀和求解指定区间的和

// 核心思路就在于 存在一个 all 数组，这个数组记录着所有在这道题中用到的区间
// 然后在构造前缀和数组的时候，我们使用all的大小来进行构建  也就是这个all 数组承担着 将输入的lr 查询 投影到指定坐标，然后再把指定坐标交给s求解

// 第二部 关于all存储的坐标，我们需要将所有在这道题中使用到的坐标，统统都记录下来，然后排序后去重

typedef pair<int, int> PII; //定义用于存储  add 操作 和查询早多的每一个元素对
vector<int> alls; //定义存储所有到的所有数轴上的坐标
vector<PII> add;  //存储 加法操作的所有数字
queue<PII> Query; //定义存储查询lr操作的队列
const int N = 300010;
int s[N]; //存储前缀和数组   其实这里使用vector<int> S 也可以
int a[N]; //存储 处理add的数组

int find(int x)
{
	int l = 0, r = alls.size() - 1;

	while (l < r)
	{
		int mid = l + r >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;

	}
	return r + 1;

}

int main()
{
	int n, m;
	cin >> n >> m;
	//处理加法操作
	while (n--)
	{
		int x, c;
		cin >> x >> c;
		add.push_back({ x, c }); //操作记录
		alls.push_back(x); //坐标记录
	}
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		Query.push({ l,r });
		alls.push_back(l);
		alls.push_back(r);
	}

	// 对所有用到的坐标排序并去重   先排序 然后做一个去重 返回完成交换后的数据位置 然后erase擦除重复元素
	sort(alls.begin(), alls.end());
	auto it = unique(alls.begin(), alls.end());
	alls.erase(it, alls.end());

	// 处理加法操作 我们需要将坐标作为索引，然后坐标+c 就是对应位置+c
	for (auto elements : add)
	{
		// 这里我们需要先把 elements.first存储的坐标值 找到对应在 alls中的索引
		int alls_index = find(elements.first);
		a[alls_index] += elements.second;
	}
	// 然后将这个a数组 按照alls的大小 转换位 前缀和数组
	for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

	//最后 挨个弹出查询输出结果
	while (!Query.empty())
	{
		auto elements = Query.front();
		Query.pop();
		int l = find(elements.first);
		int r = find(elements.second);
		cout << s[r] - s[l - 1] << endl;

	}

	return 0;
}