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

int Yushu = 0;

vector<int> Div(vector<int> &A, int B)
{

	vector<int> C;

	int t = 0; //存储余数位 
	int tmp = 0; //存储当前数值

	//对于除法，首先不管当前位是否比被除数大，我们都要将结果push到C中
	// 然后关键在于进位t的处理， 进位t 在0的时候，是直接 当前没有被除尽的元素  进位存在的时候，就直接是余数
	for (int i = 0; i < A.size(); i++)
	{
		C.push_back((t * 10 + A[i]) / B);// 不管是否能除完，都需要在不能除完的位置上放上0
		if ((t * 10 + A[i]) / B) //如果当前数字加上存储的余数位能有结果，那么就计算 
		{
			t = (t * 10 + A[i]) % B;
		}
		else //如果当前数字加上存储的余数位不能大于，那么就继续进位
		{
			t = (t * 10 + A[i]);
		}
	}
	//处理前导0
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0) C.pop_back();

	Yushu = t;
	return C;
}

int main()
{
	string a;
	cin >> a;
	int b;
	cin >> b;

	vector<int> A, C;
	for (int i = 0; i < a.length(); i++) A.push_back(a[i] - '0'); //除法是从高位开始除的
	C = Div(A, b);

	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
	cout << endl << Yushu;

	return 0;
}