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

//���͵�˫ָ������  �� ���������ˡ���

// ���϶����� �������ʵ�����Ǹ� �ؼ� ��ν������˻�Ϊһ���ǳ��򵥵����⡣
// �������ǿ��Է���һ�����ĵ㣬  ���һ���µ����ּ��������䣬����������ʹ�õ�ǰ�����ƽ���������˱仯��
// 1. ���ʹƽ�������ϱ仯�� ���� 1 3   �¼����3����ƽ������1 �仯Ϊ2    ��ô����һ������ͨ��ֻѡ3 ���ҵ����Ž�
// 2. ���ʹƽ�������±仯�� ���� 3 1   ��ô����һ������ͨ��֮ѡǰ�벿�� ���ҵ����Ž�
// ���� �ܹ�ʹ�ó�����չ��Ψһ���ܾ���   ��ǰ�����������ֶ�һ��

// ��������۶� ���ǿ��Եõ�   ���в���ȵ����ָ���һ��Ϊһ������ ������ȵ�����ȫ��Ϊһ������ Ȼ�����һ���ҵ����ֵ���ɡ�

//Ϊ�˷������  ����ǰ׺������
typedef long long LL;
const int N = 100010;
LL a[N];
LL s[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		//Ԥ����ǰ׺������
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

		//˫ָ��
		int i = 1, j = 2;  //iָ����˵�  jָ���Ҷ˵�
		int len = 1;  // ����ݴ� 
		double res = double(a[1]); //ƽ�����ݴ�
		for (; j <= n; j++)
		{
			if (a[i] != a[j])  //�������� ��Ҫ����һ�µ�ǰ�����ƽ�������ж����� ��ǰ�����Ƿ�ΪĿǰ�����Ž�
			{
				double tempres = double(s[j - 1] - s[i - 1]) / double(j - i);
				if (tempres > res  ||  (tempres == res && j - i > len))  //�������� �ֱ��Ӧ ��Ŀ����������
				{
					len = j - i;
					res = tempres;
				}
				//�����µ�����
				i = j;
			}
		}
		//����һ��β��  �����Ϊ�˷�ֹ ���һ���� û�д����µ�
		if (i != j)
		{
			double tempres = double(s[j - 1] - s[i - 1]) / double(j - i);
			if (tempres > res || (tempres == res && j - i > len))
			{
				len = j - i;
				res = tempres;
			}
		}
		cout << len << endl;
	}


	return 0;
}