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

vector<int> Mul(vector<int>& A, int B)
{
	vector<int> C;

	int t = 0; //�����λ
	int tmp = 0; //�ݴ汾������

	for (int i = 0; i < A.size(); i++)
	{
		tmp = A[i] * B + t;
		C.push_back(tmp % 10);
		t = tmp / 10;
	}

	//��δ������ʣ�µĽ�λ�����ڽ�λ�ᳬ��10 ���Ҫ��ѭ����д
	while (t)
	{
		C.push_back(t % 10);
		t = t / 10;
	}
	//ֻ�м����ͳ����ſ��ܳ���ǰ��0 �����ǲ��е�

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

	//�߾��ȼ�������Ҫ�����ж��Ƿ��Ǹ��� �ڼ���minus�Ĺ��������Ǳ�֤�����Aһ���Ǵ���B��
	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
	cout << endl;


	return 0;


}