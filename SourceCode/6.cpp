/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;
string convert(string s, int numRows) {
	string result;
	int length = 0; //s的长度
	int i, j = 0;
	length = s.length();
	if (length == 0) return s;
	else if (length == 1 || length == 2 || numRows == 1) return s;
	else
	{

		//动态二维数组声明
		int **p = new int*[numRows];
		for (int k = 0; k < numRows; k++)
		{
			p[k] = new int[length];
		}
		//初始化为0
		for (i = 0; i < numRows; i++)
		{
			for (j = 0; j < length; j++)
			{
				p[i][j] = 0;
			}
		}
		//头部初始化，头部是唯一的额外。
		p[0][0] = int(s.at(0));

		i = 1;
		j = 0;
		//如下进行srting类型的分配 分为下降过程和上升过程
		int times = 1; //上升下降次数 为奇数时，表示下降，为偶数表示上升
		int counts = 1;//小计数器，用于标志是否完成本次下降上升过程
		for (string::iterator ita = (s.begin()+1); ita != s.end(); ita++)
		{
			if (counts == numRows && times % 2 == 1)
			{
				times = times + 1;
				counts = 1;//下降次数+1 同时counts归1
				i = i - 1;//i需要额外维护一次
			}
			if (counts == numRows && times % 2 == 0)
			{
				times = times + 1;
				counts = 1;//下降次数+1 同时counts归1
				i = i + 1;//i需要额外维护一次
			}
			if (times % 2 == 1) //下降过程
			{
				counts++; //计数器维护
				p[i][j] = (int)*ita; //赋值完成一次
				i = i + 1;//下表维护
				continue;
			}
			if (times % 2 == 0) //上升过程
			{
				j = j + 1;
				i = i - 1;//下标维护
				counts++; //计数器维护
				p[i][j] = (int)*ita;
				continue;
			}
		}
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (p[i][j] != 0)
				{
					result = result + char(p[i][j]);
				}
			}
		}
		for (int k = 0; k < numRows; k++)
		{
			delete[] p[k];
		}
		delete[]p;
	}
	return result;
}

int main()
{
	string s = "ABC";
	string res;
	res = convert(s, 1);
	cout << res << endl;
	system("Pause");
	return 0;
}

//PAYPALISHIRING
*/