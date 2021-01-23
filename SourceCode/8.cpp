//这道题的格式要求很迷，其实一开始知道可以用非常简单的方法写出来，不需要吧所有可能列举，只需要确定在填入
//第一个数字之后，后面所有跟着的必须是数字，一旦不是，break就可以
/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <sstream>
#include <math.h>
using namespace std;

int flag = 0; //全局标志位 0表示为正数  1表示为负数
int flag_change = 0; //符号变化次数，只允许为0 次或1次
int int_max[10] = { 2, 1, 4, 7, 4, 8, 3, 6, 4, 7 };
int int_min[10] = { 2, 1, 4, 7, 4, 8, 3, 6, 4, 8 };

int tor2int(vector<int>& v1)
{
	long int res = 0;
	for (int i = 0 ; i < v1.size(); i++)
	{
		if (flag == 0) res = res + v1[i] * pow(10, v1.size() - i -1);
		if (flag == 1) res = res - v1[i] * pow(10, v1.size() - i - 1);
	}
	return int(res);
}

int vector2int(vector<int>& v1)
{
	//Delete first posiont zero
	int length_oringal = v1.size();
	for (int times = 0; times < length_oringal; times++)
	{
		if (v1[0] == 0)  v1.erase(v1.begin());
		else break;
	}
	if (v1.size() == 0) return 0;

	if (v1.size() > 10)
	{
		if (flag == 0) return INT_MAX;
		if (flag == 1) return INT_MIN;
	}
	if (v1.size() < 10) return tor2int(v1);


	if (v1.size() == 10)
	{
		if (flag == 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (int_max[i] > v1[i]) return tor2int(v1);
				if (int_max[i] < v1[i]) return INT_MAX;
			}
			return INT_MAX;
		}
		else if (flag == 1)
		{
			for (int i = 0; i < 10; i++)
			{
				if (int_min[i] > v1[i]) return tor2int(v1);
				if (int_min[i] < v1[i]) return INT_MIN;
			}
			return INT_MIN;
		}
	}
	return 0;
}


int myAtoi(string str) {
	vector<int> res; //指定vector容器，不指定大小
	int length = str.length();
	flag = 0;
	flag_change = 0;
	for (int i = 0; i < length; i++)
	{
		if (str.at(i) == 32 && res.size() == 0 && flag_change == 0)  continue;
		else if ((str.at(i) == 32 || str.at(i) == 43 || str.at(i) == 45) && res.size() != 0) break;
		else if (str.at(i) == 32 && flag_change == 1) break;
		else if (flag_change > 1) break;
		else
		{
			if (str.at(i) != 43 &&
				str.at(i) != 45 &&
				str.at(i) != 48 &&
				str.at(i) != 49 &&
				str.at(i) != 50 &&
				str.at(i) != 51 &&
				str.at(i) != 52 &&
				str.at(i) != 53 &&
				str.at(i) != 54 &&
				str.at(i) != 55 &&
				str.at(i) != 56 &&
				str.at(i) != 57
				) break;
			else
			{
				switch (int(str.at(i)))
				{
				case(43) : 
				{
					flag = 0;
					flag_change = flag_change + 1;
				}
					break;
				case(45) : 
				{
					flag = 1;
					flag_change = flag_change + 1;
				}
					break;
				case(48) : res.push_back(0);
					break;
				case(49) : res.push_back(1);
					break;
				case(50) : res.push_back(2);
					break;
				case(51) : res.push_back(3);
					break;
				case(52) : res.push_back(4);
					break;
				case(53) : res.push_back(5);
					break;
				case(54) : res.push_back(6);
					break;
				case(55) : res.push_back(7);
					break;
				case(56) : res.push_back(8);
					break;
				case(57) : res.push_back(9);
					break;				
				default:
					break;
				}
			}
		}
	}



	return vector2int(res);
}

int main()
{
	string s = "2147483647";
	cout << myAtoi(s) <<endl;
	system("Pause");
	return 0;
}

*/