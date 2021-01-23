/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <sstream>
using namespace std;


char int_max[10] = { '2', '1', '4', '7', '4', '8', '3', '6', '4', '7' };
char int_min[10] = { '2', '1', '4', '7', '4', '8', '3', '6', '4', '8' };
string rev(string str)
{
	string r;
	for (int i = 0; i < str.length(); ++i)
	{
		r = str[i] + r;
	}
	return r;
}


int out(string s, int flag)
{
	int count = 0;
	int length = s.length();
	//首先判断前面有没有0,有0就删除
	if (s == "0") return 0;
	if (s.at(0) == '0')
	{
		for (int i = 0; i < length; i++)
		{
			if (s.at(i) == '0')
			{
				count = count + 1;
			}
			else break;
		}
			s = s.erase(0, count);

	}
	//判断输出是否overflow
	length = s.length(); //更新length
	if (length < 10 && flag == 0) return stoi(s);
	else if (length < 10 && flag == 1) return (0 - stoi(s));
	else if (length > 10) return 0;
	else if (length == 10)
	{
		if (flag == 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (int_max[i] > s.at(i)) return stoi(s);
				if (int_max[i] < s.at(i)) return 0;
			}
		}
		else if (flag == 1)
		{
			for (int i = 0; i < 10; i++)
			{
				if (int_min[i] > s.at(i)) return (0 - stoi(s));
				if (int_min[i] < s.at(i)) return 0;
			}
		}
	}
	return 0;
}
int reverse(int x) {
	string s;
	string res;
	stringstream sstr;
	int flag = 0; // 0 表示输入为正数 1 表示输入为负数
	if (x >= 0) flag = 0;
	else
	{
		flag = 1;
		x = llabs(x);
	}
	sstr << x;
	sstr >> s;
	res = rev(s);
	return out(res, flag);
}
int main()
{
	cout << reverse(-2147483412) << endl;
	system("Pause");
	return 0;
}

*/