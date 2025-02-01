//思路：
// 这道题具体思路按照如下挂你递进
// 对于给定的一组查询 L R  在查询输入完毕后，一定可以得到一个数列 数列的各项为 w[i] 被 区间LR 包含的次数
// 且 根据次数的多少，我们一定能够按照数组从大到小的顺序 使得 查询结果的总和最大，
// 且 我们一定可以保证 这个新的按照包含次数顺序的排列 是一定可以获得的

// 因此原问题退化为一个 一维差分问题， 即 每一次查询都意味着给一个 原始全0的数组 L到R区间内+1
// 然后将原数组从大到小排列 与差分数组 元素相乘并相加 即为最大查询结果的和。

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
typedef long long LL;
const int N = 100010;
int w[N];
LL b[N];  //差分数组
LL s[N];  // 前缀数组
long long res_1, res_2 = 0;

void InsertB(int l, int r)
{
    b[l] = b[l] + 1;
    b[r + 1] = b[r + 1] - 1;
}

int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        s[i] = s[i - 1] + w[i];
    }
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        res_1 += (s[r] - s[l - 1]);
        InsertB(l, r);
    }
    // 根据差分数组 还原出每个的次数
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + b[i]; // 注意这里是将还原的数组赋值给b以节约空间
    sort(w + 1, w + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) res_2 += LL(w[i] * b[i]);
    cout << res_2 - res_1 << endl;

    return 0;
}