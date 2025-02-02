//寻找回文string数

/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;
//反向方法还需要找两个数组之间的最大公共部分，相当麻烦，因此还是直接写
void findPalindromeOdd(string s, int m,int *b){
	b[0] = m;
	b[1] = m + 2;
	int length = s.length();
	for (int i = 1; i < length; i++)
	{
		if (m - i<0 || m + i + 2 > length-1) break;
		if (s.at(m - i) == s.at(m+i+2))
		{
			b[0] = m - i;
			b[1] = m + i + 2;
			continue;
		}
		if (s.at(m - i) != s.at(m + i + 2)) break;
	}
}
void findPalindromeEven(string s, int m,int *a){
	a[0] = m;
	a[1] = m + 1;
	int length = s.length();
	for (int i = 1; i < length+1; i++)
	{
		if (m - i < 0 || m + i + 1 > length-1) break;
		if (s.at(m - i) == s.at(m + i + 1))
		{
			a[0] = m - i;
			a[1] = m + i + 1;
			continue;
		}
		if (s.at(m - i) != s.at(m + i + 1)) break;
	}
}

string longestPalindrome(string s) {
	int length = s.length();
	int a[2] = {0}; //even中存储
	int b[2] = {0}; //odd中存储
	int c[2] = {0};
	string::iterator first = s.begin();
	if (length == 1) return s;
	else if (length == 2)
	{
		if (s.at(0) == s.at(1)) return s;
		return s.substr(0,1);
	}
	else
	{
		for (string::iterator ita = s.begin(); ita != s.end(); ita++)
		{
			if (ita+1  == s.end()) break;
			if (*ita == *(ita + 1)) //说明是偶数类型的回文，使用even函数
			{
				findPalindromeEven(s, distance(first, ita), a);
			}
			if ((a[1] - a[0]) > (c[1] - c[0]))
			{
				c[1] = a[1];
				c[0] = a[0];
			}
			if (ita + 2 == s.end()) break;
			if (*ita == *(ita + 2))
			{
				findPalindromeOdd(s, distance(first, ita), b);
			}
			if ((b[1] - b[0]) > (c[1] - c[0]))
			{
				c[1] = b[1];
				c[0] = b[0];
			}
		}
		return s.substr(c[0], c[1] - c[0] + 1);
	}
}

int main()
{
	string s = "babad";
	cout << longestPalindrome(s) << endl;
	system("Pause");
	return 0;
}
*/