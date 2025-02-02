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

// 树的遍历  这道题是非常经典的 常考的关于二叉树的问题 如何使用 中序和后序遍历 来重建一个二叉树 然后再输出这个新的二叉树的层序遍历 
// 或者输出这个新的二叉树的 前序遍历。
// 这里我们可以用经典递归思想来考虑   定义一个函数  执行一次返回当前这个树中序 和 后续遍历的根节点
// 根据中序遍历的特点，通过后序遍历拿到根节点 我们可以找到中序遍历中对应位置 那么前一半就是左子树，后一半就是右子树
unordered_map<int,int> inorder_index; //用于指定中序遍历的位置
const int N = 35;
int l[N];  //存储着 某个节点 他的左子树的编号
int r[N]; // 存储着 某个节点 他的右子树的编号
int inorder[N], postorder[N];

// l1 l2 代表在中序遍历中 当前输入的这棵树的位置  r1 r2 代表在后续遍历中 当前这棵树输入的位置   //返回的是当前这棵树的根节点
int Rebuild(int l1, int l2, int r1, int r2)
{
	//递归终止条件
	if (l1 > l2 || r1 > r2) return 0;

	int root = postorder[r2];
	int inorder_x = inorder_index[root];
	l[root] = Rebuild(l1, inorder_x - 1, r1, r1 + inorder_x - l1 - 1);
	r[root] = Rebuild(inorder_x + 1, l2, r2 - l2+inorder_x, r2 - 1);
	return root;
}

void bfs(int root)
{
	queue<int> q;
	q.push(root);

	while (q.size())
	{
		int tmp = q.front();
		cout << tmp << " ";
		q.pop();
		if (l[tmp]) q.push(l[tmp]);
		if (r[tmp]) q.push(r[tmp]);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> postorder[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> inorder[i];
		//预处理一下 index
		inorder_index.insert({inorder[i], i});
	}
	int root = Rebuild(1, n, 1, n);
	bfs(root);
	return 0;
}