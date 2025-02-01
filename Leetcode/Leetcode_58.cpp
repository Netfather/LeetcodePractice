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

int lengthOfLastWord(string s) {
	if (s.empty()) return 0;
	int length = s.length();
	int cnt = 0;
	int flag = 0;
	for (int i = length-1; i >= 0; i--)
	{
		if (flag == 0 && s.at(i) == ' ') continue;
		if (s.at(i) != ' ' && i != 0)
		{
			++cnt;
			flag = 1;
		}
		else if (i == 0 && s.at(i) != ' ') ++cnt;
		else if ( flag == 1 &&s.at(i) == ' ') break;
	}
	return cnt;
}


int main()
{
	string s = "World ";
	cout << lengthOfLastWord(s) << endl;
	system("Pause");
	return 0;
}
*/