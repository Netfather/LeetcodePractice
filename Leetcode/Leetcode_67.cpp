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

string addBinary(string a, string b) {
	string res;
	int i = a.length() - 1;
	int j = b.length() - 1;
	int carry = 0;
	while (i >= 0 || j >= 0){
		int sum = carry;
		if (i >= 0){
			sum += a[i--] - '0';
		}
		if (j >= 0){
			sum += b[j--] - '0';
		}
		res.insert(0, to_string(sum % 2));
		carry = sum / 2;
	}
	if (carry > 0){
		res.insert(0, "1");
	}
	return res;
}

int main()
{
	return 0;
}
*/