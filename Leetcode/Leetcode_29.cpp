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

int divide(int dividend, int divisor) {
	if (dividend == 0) return 0;
	if (divisor == INT_MAX && dividend > INT_MIN + 1) return 0;
	else if (divisor == INT_MAX && (dividend == -INT_MAX || dividend == INT_MIN)) return -1;     else if (dividend == -2147483648){
		if (divisor == -1)
			return 2147483647;    //result overflows
		if (divisor == 1)
			return -2147483648;
	}
	int flag = 0; //0表示结果为正数 1表示结果为负数
	if ((dividend > 0 && divisor>0) || (dividend<0 && divisor<0)) flag = 0;
	else flag = 1;
	dividend = labs(dividend);
	divisor = labs(divisor);
	long int i = 0;
	while (dividend >= divisor)
	{
		dividend = dividend - divisor;
		i++;
	}
	if (flag == 0)
	{
		if (i  > INT_MAX) return INT_MAX;
		else return i;
	}
	if (flag == 1)
	{
		if (0 - i < INT_MIN) return INT_MIN;
		else return 0 - i;
	}
	return 0;
}





int main()
{
	int i = 35;
	int m = i << 1;
	cout << m << endl;
	cout << divide(-2147483647 , -1) << endl;
	system("Pause");
	return 0;
}

*/