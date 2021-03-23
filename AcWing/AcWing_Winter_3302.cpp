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

//这道题其实是关于中缀后缀前缀表达式的区分。
//如果觉得直接一步到尾，在处理过程中同步计算表达式的值有困难的话 可以先把中缀表达式处理为后缀表达式
// 然后后缀表达式求值  由于后缀表达式求值只是一个非常简单的栈的应用，因此没有难度
//最大的难度就在于如何把一个带括号的中缀表达式 转换为 能够正确运算的后缀表达式。

// 只需要遵循如下的思路：
// 读入一串中缀表达式，我们按照如下步骤就可以正确转换
// 首先所有表达式中的数字，是不需要做任何处理的，拿到就可以直接压入结果队列
// 然后表达式中的括号开始，同样不需要任何处理，拿到压入 操作符栈  注意这里和上面是完全不同的两个结构。 一个是结果队列，一个是暂存表达式的栈
//		表达式中的括号结束，也不需要任何处理，一旦遇到，就直接弹出操作符栈，直到最顶层是括号开始为止
// 然后就是 关于 + - * / 的处理。   这里我们只需要遵循一个定理： 当遇到运算符的时候，我们就看看操作符栈的顶层操作符，
// 保证顶层操作符的优先级一定比当前拿到的运算符低，否则就要一直出栈，直到栈为空 或者栈顶为括号开始

// 基于如上定理， 就可以分为 + - 法 和 * / 法来考虑。
// 对于 + - 法 由于是最低级的操作优先级，而且先入栈的 + - 法是要先算的，所以先入栈也比当前 的操作符有更高优先级
//				因此，对于 + - 法 我们直接将操作符栈中所有元素弹出，直到栈为空 或者栈顶为 括号开始
// 对于 * / 法，由于是最高级的操作符，能比这个优先级高的 只有之前存入的 * / 法，
//				因此，对于 * / 法 我们检查栈顶元素 如果 为 * 或者 / 就弹出， 当然还要保证栈不为空
// 如此就可以正确处理完成所有的操作符 实现中缀转后缀


queue<string> convert(string a)
{
	queue<string> LastPrefix;
	stack<string> Opera;

	for (int i = 0; i < a.length(); )
	{
		if (a[i] == '(')
		{
			Opera.push("(");
			i++;
		}
		else if (a[i] == ')')
		{
		// 直接弹出所有 直到上一个记录的括号开始位置
			while (Opera.top() != "(")
			{
				LastPrefix.push( Opera.top());
				Opera.pop();
			}
			Opera.pop(); // 将对应这次括号的 存储弹出
			i++;
		}
		else if (a[i] >= '0' && a[i] <= '9' )
		{
			// 不管三七二十八 直接入结果队列
			int sum = 0;
			while (i < a.length() && a[i] >= '0' && a[i] <= '9')
			{
				sum = sum * 10 + a[i++] - '0';
			}	
			LastPrefix.push(to_string(sum));
		}
		else if (a[i] == '+' || a[i] == '-')
		{
			while (!Opera.empty() && Opera.top() != "(")  //如果是 + - 法 那么我们要保证此时堆栈中的顶层存储的运算符的优先级一定比 + - 小 //那么能满足这个条件的 只有堆栈为空 或者  堆栈顶是括号开始
			{
				LastPrefix.push(Opera.top());
				Opera.pop();
			}
			Opera.push(a.substr(i, 1));
			i++;
		}
		else    //如果此时是 * / 法 那么由于一旦遇到闭括号我们就直接弹出了，因此 * / 法只需要考虑之前压入的  * /
		{
			while (!Opera.empty() && (Opera.top() == "*" || Opera.top() == "/"))  //如果是 + - 法 那么我们要保证此时堆栈中的顶层存储的运算符的优先级一定比 + - 小 //那么能满足这个条件的 只有堆栈为空 或者  堆栈顶是括号开始
			{
				LastPrefix.push(Opera.top());
				Opera.pop();
			}
			Opera.push(a.substr(i, 1));
			i++;
		}
	}
	while (!Opera.empty())  //处理完成如果 还有没处理完的操作符 就按照顺序一次入栈
	{
		LastPrefix.push(Opera.top());
		Opera.pop();
	}
	return LastPrefix;

}



//这道题需要先把中缀表示的表达式转换为前缀 然后再对前缀表达式求值即可
int main()
{
	string a;
	cin >> a;
	queue<string> lastpre = convert(a);
	stack<int> res;

	//根据转换好的后缀表达式 直接求值
	while (!lastpre.empty())
	{
		string key = lastpre.front();
		if (key == "+")
		{
			int a = res.top();
			res.pop();
			int b = res.top();
			res.pop();
			res.push(a + b);
		}
		else if (key == "-")
		{
			int a = res.top();
			res.pop();
			int b = res.top();
			res.pop();
			res.push(b - a);
		}
		else if (key == "*")
		{
			int a = res.top();
			res.pop();
			int b = res.top();
			res.pop();
			res.push(a * b);
		}
		else if (key == "/")
		{
			int a = res.top();
			res.pop();
			int b = res.top();
			res.pop();
			res.push(b / a);
		}
		else
		{
			res.push(stoi(key));
		}
		lastpre.pop();
	}
	cout << res.top() << endl;
	//while (!lastpre.empty())
	//{
	//	cout << lastpre.front();
	//	lastpre.pop();
	//}


	return 0;
}