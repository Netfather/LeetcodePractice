//思路：

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <climits>
using namespace std;

int month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int weekday[] = { 0,0,0,0,0,0,0 };
 
int main()
{
	int n;
	cin >> n;

	int day = 0; //用于统计当前年，当前月的13号距离其实的1月1日过了多少天
	for (int year = 1900; year < 1900 + n; year++)
	{
		for (int mont = 1; mont <= 12; mont++)
		{
			weekday[(day + 12) % 7]++;
			day += month[mont];
			if (mont == 2)
			{
				if (year % 100 && year % 4 == 0 || year % 400 == 0) day++;
			}
		}
	}

	for (int i = 5, int j = 0; j < 6; j++, (i++) % 7)
	{
		cout << weekday[i] << " ";
	}
	cout << endl;
	return 0;
}