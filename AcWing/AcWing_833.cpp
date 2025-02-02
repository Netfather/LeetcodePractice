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


// 这道题必须要自己画图来理解  关于ne数组的含义配合图阐明如下
//

const int N = 100010;
int ne[N];
int main()
{
	string p = "?";
	string s = "?";
	int n;
	string a;
	cin >> n >> a;
	p = p + a;
	int m;
	string b;
	cin >> m >> b;
	s = s + b;

	// 为了方便， 我们所有的字符串统一从1开始计算  原因在于 我们会经常判断j+1 所以为了避免越界  j可以从0开始 
	// 开始单独对ne数组进行处理
	// 以i开始枚举 每一次从i点开始往前看的子字符串 是否有满足ne数组的
	//  如果实在不理解 就打断点一步步调试
	// 这里关于下标的定义还是非常的有技巧的   
	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j != 0 && p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) j++;
		ne[i] = j;
	}


	// 拿到ne数组之后我们开始在s上进行匹配
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j != 0 && s[i] != p[j + 1]) j = ne[j];  // 当j没有到头，而且无法匹配的时候 我们就一直跳转j
		if (s[i] == p[j + 1]) j++; //从上面出来之后，如果是因为成功匹配才出来的，那么我们就直接将j++
		if (j == n)
		{
			 //说明j匹配到头了
			cout << i - n << endl;
			j = ne[j]; // 同时 j要再次跳转
		}
	}
	return 0;
}



//#include <iostream>
//
//using namespace std;
//
//const int N = 10010, M = 100010;
//
//int n, m;
//int ne[N];
//char s[M], p[N];
//
//int main()
//{
//    cin >> n >> p + 1 >> m >> s + 1;
//
//    for (int i = 2, j = 0; i <= n; i++)
//    {
//        while (j && p[i] != p[j + 1]) j = ne[j];
//        if (p[i] == p[j + 1]) j++;
//        ne[i] = j;
//    }
//
//    for (int i = 1, j = 0; i <= m; i++)
//    {
//        while (j && s[i] != p[j + 1]) j = ne[j];
//        if (s[i] == p[j + 1]) j++;
//        if (j == n)
//        {
//            printf("%d ", i - n);
//            j = ne[j];
//        }
//    }
//
//    return 0;
//}
