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

//Version1:
//vector<int> add(vector<int>& A, vector<int>& B)
//{
//	vector<int> C(A.size() + 1, 0);
//
//	int i = 0;
//	int t = 0;
//	// 首先计算A B 共同的部分
//	while (i < A.size() && i < B.size())
//	{
//		C[i] = (A[i] + B[i] + t) % 10;
//		t = (A[i] + B[i] + t) / 10;
//		i++;
//	}
//	// 计算A比B多的部分
//	while (i < A.size())
//	{
//		C[i] = (A[i] + t) % 10;
//		t = (A[i] + t) / 10;
//		i++;
//	}
//	// 计算如果最后还有进位 将进位的数值直接放入
//	if (t != 0) C[i] = t;
//	reverse(C.begin(), C.end());
//	return C; // 注意C的返回值有前导0 在输出的时候将前导0 删除
//}

//Version2 中间计算A B的部分其实可以合并
////vector<int> add(vector<int>& A, vector<int>& B)
////{
////	vector<int> C(A.size() + 1, 0);
////
////	int i = 0;
////	int t = 0;
////	int temp = 0;
////	 
////	while (i < A.size() ||  i < B.size())
////	{
////		if (i < B.size()) temp = A[i] + B[i] + t;
////		else temp = A[i] + t;
////		C[i] = (temp % 10);
////		t = temp / 10;
////		i++;
////	}
////	 计算如果最后还有进位 将进位的数值直接放入
////	if (t != 0) C[i] = t;
////	reverse(C.begin(), C.end());
////	return C; // 注意C的返回值有前导0 在输出的时候将前导0 删除
////}

//Version: 非前导0版本 最终版本
vector<int> add(vector<int>& A, vector<int>& B)
{
	vector<int> C;

	int i = 0;
	int t = 0;
	int temp = 0;
	//  首先我们要保证 在有A 或者B的地方 的情况全部计算完成了
	while (i < A.size() || i < B.size())
	{
		if (i < B.size()) temp = A[i] + B[i] + t;
		else temp = A[i] + t;
		C.push_back(temp % 10);
		t = temp / 10;
		i++;
	}
	// 计算如果最后还有进位 将进位的数值直接放入C中 但是这只针对加法，乘法有可能会不止一位，要用循环来加入C
	if (t != 0) C.push_back(t);
	reverse(C.begin(), C.end());
	return C; // 注意C的返回值有前导0 在输出的时候将前导0 删除
}



int main()
{
	string a, b;
	cin >> a >> b;
	// 交换二者大小，保证A为最大，B为最小
	int l_a = a.length();
	int l_b = b.length();
	if (l_a < l_b) swap(a, b), swap(l_a, l_b);
	// 将两个数据放入数组中
	vector<int> A(l_a, 0);
	vector<int> B(l_b, 0);
	for (int i = 0; i < l_a; i++) A[i] = (a[i] - '0');
	for (int i = 0; i < l_b; i++) B[i] = (b[i] - '0');
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());


	vector<int> C = add(A, B);
	//针对版本3  这里就不需要前导0了
	//bool flag = false;
	//
	//for (int i = 0; i < l_a + 1; i++)
	//{
	//	if (!flag && c[i] == 0)
	//	{
	//		continue;
	//	}

	//	cout << c[i];
	//	flag = true;
	//}
	for (int i = 0; i < C.size(); i++) cout << C[i];
	//cout << a << b;
	return 0;
}