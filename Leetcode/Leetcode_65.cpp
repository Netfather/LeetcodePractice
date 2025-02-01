
/*
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

//flag状态标志寄存器
//0: 标志这串字符串是否不合法  1表明不合法，0表明合法
//1: 标志目前是否处于数字中， 1表明处于，0表明不处于
//2: 标志第一个正负号，1表明为正，0表明为没有，3表明为负
//3: 标志第一个小数点，1表明有，0表明没有
//4: 标志第一个e，1表明有，0表明没有
//5: 标志第二个正负号，1表明为正，0表明为没有，3表明为负
//6: 标志第二个小数点，1表明有，0表明没有
//7: 标志这一串数字是否结束
//8: 标志前面为数字 1表明前面是，0表明前面不是

bool check(string s)
{
	if (s.empty()) return false;
	if (s.length() == 1)
	{
		if (s.at(0) >= '0' && s.at(0) <= '9') return true;
		else return false;
	}

	int flag_1 = 0;
	int flag_2 = 0;
	if (s.at(0) == '+' || s.at(0) == '-') flag_1 = 1;
	for (int i = 1; i < s.length(); i++)
	{
		if ((s.at(i) >= '0' && s.at(i) <= '9') || s.at(i) == '.')
		{
			if (i == 1 && s.at(i) == '.') return false;
		}
		else return false;
	}
}

bool isNumber(string s) {
	int l_b = 0;
	int l_e = 0;
	int r_b = 0;
	int r_e = s.length() - 1;
	int flag_1 = 0;
	int flag_2 = 0;
	int flag_e = 0;
	int flag_k = 0;

	for (int i = 0; i < s.length();i++)
	{
		if (flag_1 == 0 && s.at(i) == ' ') continue;
		if (flag_1 == 0 && s.at(i) != ' ')
		{
			l_b = i;
			flag_1 = 1;
		}
		else if (flag_1 = 1 && s.at(i) == 'e' && flag_e == 0)
		{
			l_e = i;
			flag_e = 1;
		}
		else if (flag_1 = 1 && s.at(i) == ' ' && flag_2 == 0)
		{
			l_e = i;
			flag_2 = 1;
		}
		else if (flag_2 == 1 && s.at(i) == ' ') continue;
		else if (flag_2 == 1 && s.at(i) != ' ') return false;
		else if (flag_e == 1 && flag_k == 0)
		{
			r_b = i;
			while (s.at(i++) != ' ') r_e = i;
			flag_k = 1;
		}
		

	}
	string m = s.substr(l_b, l_e-l_b);
	string n = s.substr(r_b, r_e-r_b);
	if (flag_e == 0 && check(m)) return true;
	else if (flag_e == 1 && check(m) && check(n)) return true;
	else return false;
}

int main()
{
	string s = "   2e30   1";
	cout << isNumber(s) << endl;
	system("Pause");
	return 0;
}

*/
