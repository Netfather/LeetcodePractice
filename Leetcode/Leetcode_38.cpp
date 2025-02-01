
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

string res;

void rec(string input, int  step , int target)
{
	string output;
	if (step == target)
	{
		res = input;
		return;
	}
	char num = '0';
	char count = '0';
	char temp = '0';
	int length = input.length();
	for (int i = 0; i < length; ++i)
	{
		num = input.at(i);
		if (num == temp && i < length - 1)		count = count + 1;
		else if (num == temp && i == length - 1)
		{
			count = count + 1;
			output = output + count + num;
		}
		else if (num != temp && temp != '0' && i < length - 1)
		{
			output = output + count + temp;
			count = '1';
		}
		else if (num != temp && temp != '0' && i == length - 1)
		{
			output = output + count + temp + '1' + num;
		}
		else if (num != temp && temp == '0')	count = count + 1;
		temp = input.at(i);
	}
	rec(output, step + 1, target);
	return;
}

string countAndSay(int n) {
	string input;
	if (n == 1) return "1";
	if (n == 2) return "11";
	if (n<1 || n>30) return input;
	input = "11";
	rec(input, 2, n);
	return res;
}

int main()
{
	string temp;
	temp = countAndSay(5);
	cout << temp << endl;
	system("Pause");
	return 0;
}
*/