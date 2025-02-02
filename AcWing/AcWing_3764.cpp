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

//由于给定的包含一个长度为n 首位为2的三元数， 意味着 如果要 max(a,b)尽可能的小，必然两个数字的首位必定都是1
//然后对于剩下的数字  由于每一位遵循   (a+b)mod 3 那么如果是1  必定是0 1  如果是0 必定是 0 0
// 唯一的特例就是 2的情况
// 假设 我们每次遇到1的时候 是把1放到a中 0放到b中。 那么此时 a就绝对比 b大了， 那么在这之后遇到的2 就可以分解为 0 2的形势
// 如果没有遇到 过1 那么此时所有的大小都是一样的，只需要把2分解为 1 1 的形式就可以了

// 总而言之，当 1没有出现之前   a b是绝对一样大小的， 当1出现之后， 此时  a b 一定要决出大小
// 如果将 1放入a中， 0 放入b中 那么之后  1 2 的分配逻辑 全部都要发生改变，因为此时 a > b是确定的
// 我们只需要把 0 尽可能往 a中塞就可以了。


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		string a;
		string b;
		string x;
		cin >> x;
		bool is_one_happen = false; //用于判断前面的位数 是否出现过1
		for (int i = 0; i < n; i++)
		{
			if (x[i] == '2')
			{
				if (is_one_happen == false)
				{
					a += "1";
					b += "1";
				}
				else if (is_one_happen)
				{
					a += "2";
					b += "0";
				}
			}
			else if (x[i] == '1')
			{
				if (is_one_happen == false)
				{
					a += "0";
					b += "1";
					is_one_happen = true; //一旦出现过1  那么之后的2 全部都可以分解为 0 2 且 2位于 a上
				}
				else if (is_one_happen)
				{
					a += "1";
					b += "0"; //一旦出现1之后 此时 a b的大小就决出胜负了， 此时我们只需要尽可能把0往 b中放就可以了
				}
			}
			else
			{
				a += "0";
				b += "0";
			}
		}
		cout << a << endl << b << endl;
		a.clear();
		b.clear();
	}
	return 0;
}