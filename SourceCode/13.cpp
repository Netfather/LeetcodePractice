/*

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define pre s.at(0)
#define jug s.substr(0,2)


int romanToInt(string s) {
	int partial = 0;;
	int length = s.length();
	if (length == 0) return partial;
	if (length >= 2 && (pre == 'I' || pre == 'X' || pre == 'C'))
	{
		if (jug == "CM")
		{
			partial = 900;
			return partial + romanToInt(s.substr(2));
		}
		else if (jug == "CD")
		{
			partial = 400;
			return partial + romanToInt(s.substr(2));
		}
		else if (jug == "XC")
		{
			partial = 90;
			return partial + romanToInt(s.substr(2));
		}
		else if (jug == "XL")
		{
			partial = 40;
			return partial + romanToInt(s.substr(2));
		}
		else if (jug == "IX")
		{
			partial = 9;
			return partial + romanToInt(s.substr(2));
		}
		else if (jug == "IV")
		{
			partial = 4;
			return partial + romanToInt(s.substr(2));
		}
	}
	if (pre == 'M')partial = 1000;
	else if (pre == 'D')partial = 500;
	else if (pre == 'C')partial = 100;
	else if (pre == 'L')partial = 50;
	else if (pre == 'X')partial = 10;
	else if (pre == 'V')partial = 5;
	else if (pre == 'I')partial = 1;
	return partial + romanToInt(s.substr(1));
}


int main()
{
	string s = "III";
	cout << romanToInt(s) << endl;
	system("Pause");
	return 0;
}

*/