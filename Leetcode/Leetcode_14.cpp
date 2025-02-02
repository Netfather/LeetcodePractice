
//1. 第一步，按照字符串的长度顺序，从小到大排序

/*

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

void swap(vector<string> &strs)
{
	string temp;
	int len_ele = 0; //用于保存每一个元素长度
	int len_ele_temp = strs[0].length(); //用于保存每一个元素的上一个长度
	int pos_ele = 0; //用于保存当前下标
	int pos_ele_temp = 0; //用于保存前一个元素的下标
	for (int i = 0; i < strs.size(); i++)
	{
		len_ele = strs[i].length();
		pos_ele = i;
		if (len_ele_temp > len_ele)
		{
			len_ele_temp = len_ele;
			pos_ele_temp = pos_ele;
		}
	}//完成之后最小值的下标就保存在pos_ele_temp中
	temp = strs[0];
	strs[0] = strs[pos_ele_temp];
	strs[pos_ele_temp] = temp;
}

string longestCommonPrefix(vector<string>& strs) {
	string s;
	if (strs.size() == 0) return s; 
	if (strs.size() == 1) return strs[0];
	string temp_s; //保存上一个结果 用于比较是否最大值
	swap(strs);
	//Switch交换首元素和最小长度的元素
	int length = strs[0].length();
	int i=0,j=0,len = 0; //分别代表循环的参数
	for (i = 0; i < 1; i++)
	{
		for (j = i ; j < length; j++)
		{
			s = strs[0].substr(i, j + 1);
			for (len = 1; len < strs.size(); len++)
			{
				if (s != strs[len].substr(i, j + 1) ) break;
				else if (s == strs[len].substr(i, j + 1) && len == strs.size() - 1)
				{
					if (temp_s.length() < s.length()) temp_s = s;
				}
			}
		}
	}
	return temp_s;
}

int main()
{
	vector<string> strs = { "flower", "flow", "flight" };
	
	cout << longestCommonPrefix(strs) << endl;
	system("Pause");
	return 0;
}

*/