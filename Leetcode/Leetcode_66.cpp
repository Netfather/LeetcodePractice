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


vector<int> plusOne(vector<int>& digits) {
	if (digits.empty()) return digits;

	int temp = 0;

	int flag_int = 0; //进位标志
	int i = 0;
	for (i = digits.size() - 1; i >= 0; i--)
	{
		if (i == digits.size() - 1) temp = digits[i] + flag_int + 1;
		else temp = digits[i] + flag_int;
		if (temp > 9)
		{
			digits[i] = temp % 10;
			if (i == 0)  digits.insert(digits.begin(), 1);
			flag_int = 1;
		}
		else
		{
			digits[i] = temp;
			flag_int = 0;
		}
	}
	return digits;
}
*/

