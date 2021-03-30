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

//堆是一种完美的完全二叉树，然后这种二叉树是按照列表的形式存储的 
// 这种由列表存储的完美二叉树拥有一个非常好的性质 已知某个根节点的下标为u 那么他的左节点必定是2u 右节点索引必定是2u+1
// 构造这种树必须满足 任意一个根节点 它的值 一定比左右两个节点都要小  针对这个递归条件  完成down up两个操作 就可以实现几乎所有的堆操作
const int N = 100010;
int w[N];
int ph[N];  //存放第k个插入点的下标
int hp[N];  //存放堆中点的插入次序
int mysize = 0;  //这道题mysize的功能就是一个地址分配器 但是由于这道题必须准确维护mysize大小 所以这里从0开始

// 主要实现 两个递归操作 down 和 up
// 但是这道题的核心难点就在于如何处理最后的删除第k个数 这种操作
// 由于在过程中我们经常进行swap  所以 每个数的地址是经常更换的  或者换个说法 某个地址存储的值是经常变更的
// 因此在每次swap操作时， 我们都要维护ph 和 hp   ph 是将 k个数字转为 堆能用的下标 同理hp是将堆能用的下标转为 我们所理解的第k个数字

// u v 是树能用的地址 这点应当非常明确
void heap_swap(int u, int v)
{
	swap(w[u], w[v]);
	swap(hp[u], hp[v]); // 由于题目指定了第k个数 我们需要维护好两个映射表，能把第k个数转为目前他在树中的索引位置
	swap(ph[hp[u]], ph[hp[v]]);

}

void down(int u)
{
	int t = u; //假定输入的地址就是最小值  最小值存在u中
	if (2 * u <= mysize && w[2 * u] < w[t]) t = 2 * u;
	if (2 * u + 1 <= mysize && w[2 * u + 1] < w[t]) t = 2 * u + 1;

	if (t != u)
	{
		heap_swap(t, u);
		down(t);
	}
	return;
}

void up(int u)
{
	int t = u;
	if ( u/2 && w[u / 2] > w[t]) t = u / 2;

	if (t != u)
	{
		heap_swap(t,u);
		up(t);
	}
	return;

}


int main()
{
	int n;
	cin >> n;
	int m = 0;
	while (n--)
	{
		string opera;
		int a;
		cin >> opera;
		if (opera == "I")
		{
			cin >> a;
			m++; //第几个插入的数
			w[++mysize] = a;
			ph[m] = mysize;
			hp[mysize] = m;
			up(mysize);

		}
		else if (opera == "PM")
		{
			cout << w[1] << endl;
		}
		else if (opera == "DM")
		{
			heap_swap(1, mysize);
			mysize--;
			//w[1] = w[mysize--]; // 将w[1] 直接修改为最末尾的元素 然后地址分配器-1 然后再down
			down(1);
		}
		else if (opera == "D")
		{
			cin >> a;
			int u = ph[a];
			heap_swap(u, mysize);
			mysize--;
			down(u);
			up(u);
		}
		else if (opera == "C")
		{
			int k;
			cin >> k >> a;

			w[ph[k]] = a;
			down(ph[k]);
			up(ph[k]);
		}
	}


	return 0;
}


