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

//���ȱ���һ������  ���ǿ�����O(n)ʱ���ڵõ� �������λ�� �Լ� ��Ҫ���������  �Լ������ȫ���в��ܵ��ڵ�λ��
// ��ô ���������˻�Ϊ  �������� ˳�����е� ����  a1 a2 a3 ... an  �� b1 b2 b3 .. bn
// ������β���an���в���ʹ�� �������е� 1��n   ai������ bi�����
// �������ݱ�֤ �н�  ��ô����ֻ��Ҫ  ����2��n��λ�� һ����λ�õ��� bn ���ǾͰѸ�λ�ú�ǰ�������swapһ�� 


// �޶� ���������������һ�µ�һ��β�� ������ ���ǾͰѵ�һ�����ֺ͵ڶ������ֽ���һ�� 
// ������Ŀ�Ǳ�֤һ���н�� ������ַ���һ������������յĽ��
//��һ��������O(n)��ʱ���ڵó�����

vector<int> unequal; //���ܵ�������   ������鰴˳������  0λ�õ�  �±�����
vector<int> number; // ������������  ����������� ��Ҫ���������
const int N = 200010;
int a[N]; //�洢ԭʼ����
bool Table[N]; //���ڼ�¼��������Щδ��д


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		//���һ�� Table
		memset(Table, false, sizeof Table);

		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] == 0) unequal.push_back(i);
			else Table[a[i]] = true; //�����Ϊ0 �Ͱ�������ı�־λ��Ϊ1
		}
		for (int i = 1; i <= n; i++) 
			if (!Table[i]) number.push_back(i);
		sort(number.begin(), number.end());  //����Ҫ����������Ÿ���
		// ����һ�� unequal����� bn    number�д���� an  ͬʱ����������������
		// ������Ҫ���� an ʹ�ö������е�1��n  ���� an������ bn�����
		// ����������������� ���ǿ���ͨ�������ķ�ʽ ��O(n)ʱ��������ع�������������an����

		//������ ˵����Ҫ����λ��  
		for (int i = 1; i < unequal.size(); i++)
			if (number[i] == unequal[i]) swap(number[i], number[i - 1]);	
		//��� �����һ��������ͬ ��ѵ�һ�����ֺ͵ڶ������ֽ���һ�� ���� ���ݱ�֤��һ���н� ������ַ�ʽһ�����Թ�����������������
		if (number[0] == unequal[0]) swap(number[0], number[1]);

		//������
		for (int i = 1, j = 0; i <= n; i++)
		{
			if (a[i] != 0) cout << a[i] << " ";
			else cout << number[j++] << " ";
		}
		cout << endl;
		//�������
		unequal.clear();
		number.clear();
	}
	return 0;
}