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

//输入变量 1，代处理的数字，2，最后输出的数组，3，当前迭代位置
vector<string> res;
map<string, string> dic = { { "2", "abc" }, { "3", "def" }, { "4", "ghi" }, { "5", "jkl" }, { "6", "mno" }, { "7", "pqrs" }, { "8", "tuv" }, { "9", "wxyz" } };

void letterRecur(const string &src, int index, const string &temp){
	if (index == src.size()) res.push_back(temp);
	string k = src.substr(index, 1);
	string v = dic[k];
	for (char c : v){
		letterRecur(src, index + 1, temp + c);
	}
}

vector<string> letterCombinations(string digits) {
	if (digits.empty()) return res;
	string temp;
	letterRecur(digits, 0, temp);
	return res;
}



int main()
{
	string digits = "23";
	int i = 0;
	int lenth = digits.length();
	int num_4 = 0;
	for (i = 0; i < digits.length(); i++)
	{
		if (digits.at(i) == '7' || digits.at(i) == '9') num_4 = num_4 + 1;
	}
	int len_res = pow(3 ,(lenth - num_4)) * pow(4,(num_4));
	vector<string> res(len_res);

	res = letterCombinations(digits);

	for (int j = 0; j < res.size(); j++)
	{
		cout << res[j] << endl;
	}
	system("Pause");



	return 0;
}

*/