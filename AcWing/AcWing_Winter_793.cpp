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

vector<int> Mul(vector<int>& A, int B)
{
	vector<int> C;

	int t = 0; //处理进位
	int tmp = 0; //暂存本次数据

	for (int i = 0; i < A.size(); i++)
	{
		tmp = A[i] * B + t;
		C.push_back(tmp % 10);
		t = tmp / 10;
	}

	//如何处理最后剩下的进位？由于进位会超过10 因此要用循环来写
	while (t)
	{
		C.push_back(t % 10);
		t = t / 10;
	}
	//只有减法和除法才可能出现前导0 其他是不行的

	return C;

}

int main()
{
	string a;
	cin >> a;
	int b;
	cin >> b;
	if (b == 0)
	{
		cout << 0;
		return 0;
	}
	vector<int> A, C;
	for (int i = a.length() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	C = Mul(A, b);

	//高精度减法还需要额外判断是否是负数 在计算minus的过程中我们保证输入的A一定是大于B的
	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
	cout << endl;


	return 0;


}