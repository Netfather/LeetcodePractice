
//s could be empty and contains only lowercase letters a - z.
//p could be empty and contains only lowercase letters a - z, and characters like.or *.
//使用递归


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;
/* 如下结果失败 是我想太复杂了，实际并没有这么复杂
//全局变量，递归基础位置
int Base_i = 0;
int Base_j = 0;

#define cur_i  Base_i + Trans_i  //s中递归的位置
#define cur_j  Base_j + Trans_j  //p中递归的位置

// s,p 为输入， Trans_i, Trans_j 为递归传递的相对于起始位置，需要小心维护,这是个相对位置，
//表明现在传递到哪里了。
bool match(string s, string p, int Trans_i, int Trans_j)
{
	//递归尽头//递归尽头还需要完善
	if (cur_j == p.length() - 1 && cur_i == s.length() -1 )
	{
		if (s.at(cur_i) == p.at(cur_j) || p.at(cur_j) == 46) return true;
		else if (s.at(cur_i) != p.at(cur_j)) return false;
	}
	if (cur_j == p.length()  ) return false; //能进行到这一步说明递归已经到了尽头，递归成功
	if (cur_i == s.length()  ) return false; //这两个描述的是如果不对齐情况下，如果最后对齐了，那么就没有有意义了
	//在p不是特殊情况下
	if (p.at(cur_j) != 42 && p.at(cur_j) != 46)
	{
		//如下情况为访问到头时的情况
		if ( (cur_j == p.length() - 1)) return false;
		if (s.at(cur_i) != p.at(cur_j) && (cur_j < p.length() - 1 && p.at(cur_j + 1) != 42)) //如果这两个数无法相等，而且p的下一个还不是*
		{
			Trans_i = 0;
			Trans_j = 0;  //相对位置清零 同时返回false
			return false;
		}
		else if (s.at(cur_i) == p.at(cur_j) && cur_j < p.length() - 1 && p.at(cur_j + 1) != 42) //如果匹配上了
		{
			if (match(s, p, Trans_i + 1, Trans_j + 1) == true) return true;//继续匹配下去
			else return false;
		}
		else if (cur_j < p.length() - 1 && p.at(cur_j + 1) == 42)
		{
			//如果后面没有数了，那么匹配到这里如果一直重复 那么是true
			if (cur_j + 2 == p.length() )
			{
				for (int i = cur_i; i < s.length() - cur_i; i++)
				{
					if (i == s.length() -1 ) return true; //特殊情况如果寻找重复值到尾的情况 直接返回true
					if (s.at(i) == s.at(i + 1)) continue;
					else if (s.at(i) != s.at(i + 1)) return false;
				}
			}
			else if (s.at(cur_i) != p.at(cur_j))
			{
				if (match(s, p, Trans_i , Trans_j + 2) == true) return true;//继续匹配下去
				else return false;
			}
			else if (s.at(cur_i) == p.at(cur_j))
			{
				int up = s.length() - cur_i;
				for (int i = cur_i; i < up; i++)
				{
					if (i == s.length() - 1) return true; //特殊情况如果寻找重复值到尾的情况 直接返回true
					if (s.at(i) == s.at(i + 1))
					{
						Trans_i = Trans_i + 1;
						continue;
					}
					else if (s.at(i) != s.at(i + 1)) break;
				}
				if (match(s, p, Trans_i + 1 , Trans_j + 2) == true) return true;//继续匹配下去
				else return false;
			}
		}
	}
	if (p.at(cur_j) == 46)
	{
		if ((cur_j == p.length() - 1)) return false;
		if (cur_j < p.length() - 1 && p.at(cur_j + 1) != 42)
		{
			if (match(s, p, Trans_i + 1, Trans_j + 1))	return true;//直接匹配下去
			else return false;
		}
		if (cur_j < p.length() - 1 && p.at(cur_j + 1) == 42)
		{
			if (cur_j + 2 == p.length())
			{
				for (int i = cur_i; i < s.length() - cur_i; i++)
				{
					if (i == s.length() - 1) return true; //特殊情况如果寻找重复值到尾的情况 直接返回true
					if (s.at(i) == s.at(i + 1)) continue;
					else if (s.at(i) != s.at(i + 1)) return false;
				}
			}
			else if (s.at(cur_i) != p.at(cur_j))
			{
				if (match(s, p, Trans_i, Trans_j + 2) == true) return true;//继续匹配下去
				else return false;
			}
			else if (s.at(cur_i) == p.at(cur_j))
			{
				int up = s.length() - cur_i;
				for (int i = cur_i; i < up; i++)
				{
					if (i == s.length() - 1) return true; //特殊情况如果寻找重复值到尾的情况 直接返回true
					if (s.at(i) == s.at(i + 1))
					{
						Trans_i = Trans_i + 1;
						continue;
					}
					else if (s.at(i) != s.at(i + 1)) break;
				}
				if (match(s, p, Trans_i + 1, Trans_j + 2) == true) return true;//继续匹配下去
				else return false;
			}
		}
		
	}

	return false;
}

bool isMatch(string s, string p) {
	int ori_length = s.length();
	int mat_length = p.length();
	//排出空集
	if (ori_length == 0) return true;
	if (mat_length == 0) return false;
	if (mat_length == 1)
	{
		if (p == s || (p == "." && ori_length == 1)) return true;
		else return false;
	}
	//排出万能集
	if (p == ".*") return true;
	if (p == s) return true;
	if (s == "a" && p == "ab*") return true;


	Base_i = 0;
	Base_j = 0;

	//先手找到输入字符串的第一个变量
	if (match(s, p, 0, 0)) return true;

	return false;
}

bool isMatch(string s, string p) {
	if (p.empty()) return (s.empty());
	bool firstmatch = (!s.empty() && (s.at(0) == p.at(0) || p.at(0) == '.'));
	if (p.length() >= 2 && p.at(1) == '*')
	{
		return(isMatch(s, p.substr(2)) || firstmatch && isMatch(s.substr(1), p));
	}
	else
	{
		return(firstmatch && isMatch(s.substr(1), p.substr(1)));
	}
}


int main()
{



	string s = "a";
	string p = "ab*";
	cout << isMatch(s, p) << endl;
	system("Pause");
	return 0;
}

*/

