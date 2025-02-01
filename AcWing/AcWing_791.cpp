//˼·��

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
//	// ���ȼ���A B ��ͬ�Ĳ���
//	while (i < A.size() && i < B.size())
//	{
//		C[i] = (A[i] + B[i] + t) % 10;
//		t = (A[i] + B[i] + t) / 10;
//		i++;
//	}
//	// ����A��B��Ĳ���
//	while (i < A.size())
//	{
//		C[i] = (A[i] + t) % 10;
//		t = (A[i] + t) / 10;
//		i++;
//	}
//	// �����������н�λ ����λ����ֱֵ�ӷ���
//	if (t != 0) C[i] = t;
//	reverse(C.begin(), C.end());
//	return C; // ע��C�ķ���ֵ��ǰ��0 �������ʱ��ǰ��0 ɾ��
//}

//Version2 �м����A B�Ĳ�����ʵ���Ժϲ�
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
////	 �����������н�λ ����λ����ֱֵ�ӷ���
////	if (t != 0) C[i] = t;
////	reverse(C.begin(), C.end());
////	return C; // ע��C�ķ���ֵ��ǰ��0 �������ʱ��ǰ��0 ɾ��
////}

//Version: ��ǰ��0�汾 ���հ汾
vector<int> add(vector<int>& A, vector<int>& B)
{
	vector<int> C;

	int i = 0;
	int t = 0;
	int temp = 0;
	//  ��������Ҫ��֤ ����A ����B�ĵط� �����ȫ�����������
	while (i < A.size() || i < B.size())
	{
		if (i < B.size()) temp = A[i] + B[i] + t;
		else temp = A[i] + t;
		C.push_back(temp % 10);
		t = temp / 10;
		i++;
	}
	// �����������н�λ ����λ����ֱֵ�ӷ���C�� ������ֻ��Լӷ����˷��п��ܻ᲻ֹһλ��Ҫ��ѭ��������C
	if (t != 0) C.push_back(t);
	reverse(C.begin(), C.end());
	return C; // ע��C�ķ���ֵ��ǰ��0 �������ʱ��ǰ��0 ɾ��
}



int main()
{
	string a, b;
	cin >> a >> b;
	// �������ߴ�С����֤AΪ���BΪ��С
	int l_a = a.length();
	int l_b = b.length();
	if (l_a < l_b) swap(a, b), swap(l_a, l_b);
	// ���������ݷ���������
	vector<int> A(l_a, 0);
	vector<int> B(l_b, 0);
	for (int i = 0; i < l_a; i++) A[i] = (a[i] - '0');
	for (int i = 0; i < l_b; i++) B[i] = (b[i] - '0');
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());


	vector<int> C = add(A, B);
	//��԰汾3  ����Ͳ���Ҫǰ��0��
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