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

//直接根据基础课的 高精度加法改编一下就可以， 先将读入的字符串处理为vector容器，然后从低位开始遍历
// 指定当前位结果暂存tmp和进位暂存t
// 考虑当当前位结果tmp 可以被2整除时 就说明当前位是 0
// 如果当前位结果tmp > 1说明需要进位 进位为 t = tmp - 1 否则 t = 0
// 最后没有处理完的t 要做while 直到 t为0
vector<int> Add2(vector<int>& A)
{
	int t = 0;
	int tmp = 0;
	vector<int> C;
	for (int i = 0; i < A.size(); i++)
	{
		if (i > 0) tmp = A[i] + t;
		else tmp = A[i] + t + 1;
		if (tmp % 2 == 0) C.push_back(0);
		else C.push_back(1);
		if (tmp > 1) t = tmp - 1;
		else t = 0;
	}
	//如果进位没有完全 还需要处理进位
	while (t)
	{
		C.push_back(t % 2);
		t = t / 2;
	}
	return C;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string x;
		cin >> x;
		vector<int> A, C;
		for (int i = x.length() - 1; i >= 0; i--) A.push_back(x[i] - '0');
		C = Add2(A);
		for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
		cout << endl;
		C = Add2(C);
		C = Add2(C);
		for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
		cout << endl;
	}
	return 0;
}