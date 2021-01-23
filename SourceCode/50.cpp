
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

double PositivePow(double x, int n) {
	if (n == 2) return x*x;
	if (n == 1) return x;
	if (n == 0) return 1;

	if (n > 2 && n % 2 == 0) return PositivePow(x, n / 2) * PositivePow(x, n / 2);
	else if (n > 2 && n % 2 == 1) return x*PositivePow(x, (n - 1) / 2)*PositivePow(x, (n - 1) / 2);
	return 0;
}

double myPow(double x, int n) {
	if (n >= 0) return PositivePow(x, n);
	else if (n < 0) return 1 / PositivePow(x, -n);
	return 0;
}

int main()
{
	double res;
	res = myPow(2.00000, -2);
	cout << res << endl;
	system("Pause");
	return 0;

}

*/