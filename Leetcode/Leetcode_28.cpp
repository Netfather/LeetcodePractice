
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

int strStr(string haystack, string needle) {
	if (needle.empty()) return 0;
	if (needle.length() > haystack.length()) return -1;
	else if (needle.length() == haystack.length())
	{
		if (needle == haystack) return 0;
		else return -1;
	}
	else if (needle.length() < haystack.length())
	{
		int i = 0;
		for (i = 0; i < haystack.length() - needle.length()+ 1; i++)
		{
			if (haystack.at(i) == needle.at(0))
			{
				if (haystack.substr(i, needle.length()) == needle)
				{
					return i;
				}
			}
		}
		return -1;

	}
	return -1;
}


int main()
{

	cout << strStr("mississippi","pi") << endl;
	system("Pause");
	return 0;
}

*/