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

//ֱ�Ӹ��ݻ����ε� �߾��ȼӷ��ı�һ�¾Ϳ��ԣ� �Ƚ�������ַ�������Ϊvector������Ȼ��ӵ�λ��ʼ����
// ָ����ǰλ����ݴ�tmp�ͽ�λ�ݴ�t
// ���ǵ���ǰλ���tmp ���Ա�2����ʱ ��˵����ǰλ�� 0
// �����ǰλ���tmp > 1˵����Ҫ��λ ��λΪ t = tmp - 1 ���� t = 0
// ���û�д������t Ҫ��while ֱ�� tΪ0
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
	//�����λû����ȫ ����Ҫ�����λ
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