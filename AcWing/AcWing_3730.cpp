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

//题意的意思简化以下就是 p的每一个元素从同位置的 abc中选，且
//保证最后的 满足 p1 != p2, p2 != p3, p3 != p4  一直到 pn!= p1
// 观察这个我们可以发现 起始 p1= p3 = p5 是没有关系的 并不影响最终的结果

// 因为我们可以发现  每隔一个数  二者就没有任何限制了
// 因此我们只需要把 隔开的数字直接赋值 a b c 中的任意一个 然后再往中间选择一个 不等于前后的一个数字即可
// 完成这步之后 对偶数个  就剩下最后一个数字没填写 对奇数个 就剩下最后两个数字没填写
// 最后暴力枚举以下  就可以完成


// 因此考虑这样构造 分奇偶
// 若为偶数 则  p1 = a1  p3 = a3  pn-1 = an-1
// 然后对于中间的 p2 p4 等  如果a1 != a2 且 a2 != a3 就填a2
//

const int N = 110;
int a[N], b[N], c[N],p[N];
int tmp1[4], tmp2[4]; //用于存放最后尾巴的暴力枚举

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		memset(p, 0, sizeof p);
		int up_bound = n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		for (int i = 1; i <= n; i++) cin >> c[i];
		//先把 前n个偶数部分填写好 例如 对n=5 就先把 n= 4的所有填写好
		if (n % 2 == 1)  up_bound--;
		for (int i = 1; i <= up_bound; i =i + 2) p[i] = a[i];
		for (int i = 2; i < up_bound ; i = i + 2)
		{
			if (a[i] != p[i - 1] && a[i] != p[i + 1]) p[i] = a[i];
			else if (b[i] != p[i - 1] && b[i] != p[i + 1]) p[i] = b[i];
			else if (c[i] != p[i - 1] && c[i] != p[i + 1]) p[i] = c[i];
		}

		// 到这里 就剩下 n为偶数 就剩最后一个数字没填写   n为奇数 就剩下最后两个数字没填写
		if (up_bound != n) //说明还有最后两个数字要填
		{
			tmp1[1] = a[up_bound], tmp1[2] = b[up_bound], tmp1[3] = c[up_bound];
			tmp2[1] = a[n], tmp2[2] = b[n], tmp2[3] = c[n];
			//暴力枚举以下所有可能
			bool sucess = false;
			for (int i = 1; i <= 3; i++)
			{
				for (int j = 1; j <= 3; j++)
				{
					// 在这里  倒数第二个数字填的是 tmp1[i] 倒数第一个数字填写的是tmp2[j]
					if (tmp1[i] != p[up_bound - 1] && tmp1[i] != tmp2[j] && tmp2[j] != p[1])
					{
						p[up_bound] = tmp1[i];
						p[n] = tmp2[j];
						sucess = true;
						break;
					}
				}
				if (sucess) break;
			}
		}
		else //否则 我们只需要填写最后一个数
		{
			tmp1[1] = a[n], tmp1[2] = b[n], tmp1[3] = c[n];
			for (int i = 1; i <= 3; i++)
			{
				//在这里 最后一个数字填写的是 tmp1[i]
				if (tmp1[i] != p[up_bound - 1] && tmp1[i] != p[1])
				{
					p[n] = tmp1[i];
					break;
				}
			}
		}
		//输出结果
		for (int i = 1; i <= n; i++) cout << p[i] << " ";
		cout << endl;
	}
	return 0;
}