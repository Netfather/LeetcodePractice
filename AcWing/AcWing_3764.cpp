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

//���ڸ����İ���һ������Ϊn ��λΪ2����Ԫ���� ��ζ�� ���Ҫ max(a,b)�����ܵ�С����Ȼ�������ֵ���λ�ض�����1
//Ȼ�����ʣ�µ�����  ����ÿһλ��ѭ   (a+b)mod 3 ��ô�����1  �ض���0 1  �����0 �ض��� 0 0
// Ψһ���������� 2�����
// ���� ����ÿ������1��ʱ�� �ǰ�1�ŵ�a�� 0�ŵ�b�С� ��ô��ʱ a�;��Ա� b���ˣ� ��ô����֮��������2 �Ϳ��Էֽ�Ϊ 0 2������
// ���û������ ��1 ��ô��ʱ���еĴ�С����һ���ģ�ֻ��Ҫ��2�ֽ�Ϊ 1 1 ����ʽ�Ϳ�����

// �ܶ���֮���� 1û�г���֮ǰ   a b�Ǿ���һ����С�ģ� ��1����֮�� ��ʱ  a b һ��Ҫ������С
// ����� 1����a�У� 0 ����b�� ��ô֮��  1 2 �ķ����߼� ȫ����Ҫ�����ı䣬��Ϊ��ʱ a > b��ȷ����
// ����ֻ��Ҫ�� 0 �������� a�����Ϳ����ˡ�


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		string a;
		string b;
		string x;
		cin >> x;
		bool is_one_happen = false; //�����ж�ǰ���λ�� �Ƿ���ֹ�1
		for (int i = 0; i < n; i++)
		{
			if (x[i] == '2')
			{
				if (is_one_happen == false)
				{
					a += "1";
					b += "1";
				}
				else if (is_one_happen)
				{
					a += "2";
					b += "0";
				}
			}
			else if (x[i] == '1')
			{
				if (is_one_happen == false)
				{
					a += "0";
					b += "1";
					is_one_happen = true; //һ�����ֹ�1  ��ô֮���2 ȫ�������Էֽ�Ϊ 0 2 �� 2λ�� a��
				}
				else if (is_one_happen)
				{
					a += "1";
					b += "0"; //һ������1֮�� ��ʱ a b�Ĵ�С�;���ʤ���ˣ� ��ʱ����ֻ��Ҫ�����ܰ�0�� b�зžͿ�����
				}
			}
			else
			{
				a += "0";
				b += "0";
			}
		}
		cout << a << endl << b << endl;
		a.clear();
		b.clear();
	}
	return 0;
}