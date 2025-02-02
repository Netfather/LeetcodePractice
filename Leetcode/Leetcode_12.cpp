/*
//递归的简单应用

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

string intToRoman(int num) {
	string partial;
	if (num >= 1000)
	{
		num = num - 1000;
		partial = "M";
		return partial + intToRoman(num);
	}
	else if (num >= 900)
	{
		num = num - 900;
		partial = "CM";
		return partial + intToRoman(num);
	}
	else if (num >= 500)
	{
		num = num - 500;
		partial = "D";
		return partial + intToRoman(num);
	}
	else if (num >= 400)
	{
		num = num - 400;
		partial = "CD";
		return partial + intToRoman(num);
	}
	else if (num >= 100)
	{
		num = num - 100;
		partial = "C";
		return partial + intToRoman(num);
	}
	else if (num >= 90)
	{
		num = num - 90;
		partial = "XC";
		return partial + intToRoman(num);
	}
	else if (num >= 50)
	{
		num = num - 50;
		partial = "L";
		return partial + intToRoman(num);
	}
	else if (num >= 40)
	{
		num = num - 40;
		partial = "XL";
		return partial + intToRoman(num);
	}
	else if (num >= 10)
	{
		num = num - 10;
		partial = "X";
		return partial + intToRoman(num);
	}
	else if (num >= 9)
	{
		num = num - 9;
		partial = "IX";
		return partial + intToRoman(num);
	}
	else if (num >= 5)
	{
		num = num - 5;
		partial = "V";
		return partial + intToRoman(num);
	}
	else if (num >= 4)
	{
		num = num - 4;
		partial = "IV";
		return partial + intToRoman(num);
	}
	else if (num >= 1)
	{
		num = num - 1;
		partial = "I";
		return partial + intToRoman(num);
	}
	else if (num == 0)
	{
		return partial;
	}
	return "False";
}


int main()
{
	int  num = 1994;
	cout << intToRoman(num) << endl;
	system("Pause");
	return 0;
}

*/