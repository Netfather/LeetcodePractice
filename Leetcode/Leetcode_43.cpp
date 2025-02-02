
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

map<char, int> nums = { { '1', 1 }, { '2', 2 }, { '3', 3 }, { '4', 4 }, { '5', 5 }, { '6', 6 }, { '7', 7 }, { '8', 8 }, { '9', 9 }, {'0',0} };

string reserve(string input)
{
	string res;
	for (char c : input)
	{
		res =  c + res;
	}
	return res;
}
string multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0") return "0";
	//更长的为num1 更短的为num2
	if (num1.length() < num2.length())
	{
		string temp;
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	int count = 0;
	int i = num1.length() - 1;
	int j = num2.length() - 1;
	int flag_mul = 0;
	int temp = 0;
	vector<vector<int>> store; //存储中间数
	for (; j >= 0; j--)
	{
		vector<int>line(count, 0);
		for (i = num1.length() - 1; i >= 0; i--)
		{
			temp = nums[num1.at(i)] * nums[num2.at(j)] + flag_mul;
			if (i == 0 )
			{
				line.push_back(temp % 10);
				if(temp >= 10) line.push_back(temp / 10);
				flag_mul = 0;
			}
			else
			{
				line.push_back(temp % 10);
				flag_mul = temp / 10;
			}
		}
		store.push_back(line);
		line.clear();
		count = count + 1;
	}
	//对store中的每一行进行加法运算然后得到结果
	string res;
	int flag_add = 0;
	i = 0;
	j = 0;
	for (i = 0; i < store[store.size() - 1].size(); i++)
	{
		temp = 0;
		for (j = 0; j < store.size(); j++)
		{
			if (i >= store[j].size()) continue;
			int k = store[j][i];
			temp = temp + store[j][i] ;
		}
		temp = temp + flag_add;
		res = res + to_string(temp % 10);
		flag_add = temp / 10;
	}
	if (temp >= 10)	res = res + to_string(temp / 10);
	return reserve(res);

}

int main()
{
	string num1 = "493";
	string num2 = "21";
	string res;
	res = multiply(num1, num2);
	cout << res << endl;
	system("Pause");
	return 0;
}

*/