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

int mySqrt(int x) {

	int start = 1;
	int end = x;

	while (start <= end)
	{
		long long int temp = start + ((end - start) >> 1);
		if (temp * temp == x) return temp;
		else if (temp * temp > x) end = temp - 1;
		else start = temp + 1;
	}
	return start - 1;

}

int main()
{
	int k = mySqrt(80);
	cout << k<< endl;
	system("Pause");
	return 0;
}
*/
