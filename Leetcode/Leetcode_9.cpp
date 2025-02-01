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


string rev(string str)
{
	string r;
	for (int i = 0; i < str.length(); ++i)
	{
		r = str[i] + r;
	}
	return r;
}


bool isPalindrome(int x) {
	string s;
	stringstream sstr;
	sstr << x;
	sstr >> s;
	string res;
	res = rev(s);
	int lenth = s.length();
	for (int i = 0; i < lenth; i++)
	{
		if (s.at(i) == res.at(i)) continue;
		else return 0;
	}
	return 1;
}


int main()
{
	cout << isPalindrome(121) << endl;
	system("Pause");
	return 0;
}

*/