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

int Yushu = 0;

vector<int> Div(vector<int> &A, int B)
{

	vector<int> C;

	int t = 0; //�洢����λ 
	int tmp = 0; //�洢��ǰ��ֵ

	//���ڳ��������Ȳ��ܵ�ǰλ�Ƿ�ȱ����������Ƕ�Ҫ�����push��C��
	// Ȼ��ؼ����ڽ�λt�Ĵ��� ��λt ��0��ʱ����ֱ�� ��ǰû�б�������Ԫ��  ��λ���ڵ�ʱ�򣬾�ֱ��������
	for (int i = 0; i < A.size(); i++)
	{
		C.push_back((t * 10 + A[i]) / B);// �����Ƿ��ܳ��꣬����Ҫ�ڲ��ܳ����λ���Ϸ���0
		if ((t * 10 + A[i]) / B) //�����ǰ���ּ��ϴ洢������λ���н������ô�ͼ��� 
		{
			t = (t * 10 + A[i]) % B;
		}
		else //�����ǰ���ּ��ϴ洢������λ���ܴ��ڣ���ô�ͼ�����λ
		{
			t = (t * 10 + A[i]);
		}
	}
	//����ǰ��0
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
	for (int i = 0; i < a.length(); i++) A.push_back(a[i] - '0'); //�����ǴӸ�λ��ʼ����
	C = Div(A, b);

	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
	cout << endl << Yushu;

	return 0;
}