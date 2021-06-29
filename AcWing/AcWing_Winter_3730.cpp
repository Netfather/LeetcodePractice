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

//�������˼�����¾��� p��ÿһ��Ԫ�ش�ͬλ�õ� abc��ѡ����
//��֤���� ���� p1 != p2, p2 != p3, p3 != p4  һֱ�� pn!= p1
// �۲�������ǿ��Է��� ��ʼ p1= p3 = p5 ��û�й�ϵ�� ����Ӱ�����յĽ��

// ��Ϊ���ǿ��Է���  ÿ��һ����  ���߾�û���κ�������
// �������ֻ��Ҫ�� ����������ֱ�Ӹ�ֵ a b c �е�����һ�� Ȼ�������м�ѡ��һ�� ������ǰ���һ�����ּ���
// ����ⲽ֮�� ��ż����  ��ʣ�����һ������û��д �������� ��ʣ�������������û��д
// �����ö������  �Ϳ������


// ��˿����������� ����ż
// ��Ϊż�� ��  p1 = a1  p3 = a3  pn-1 = an-1
// Ȼ������м�� p2 p4 ��  ���a1 != a2 �� a2 != a3 ����a2
//

const int N = 110;
int a[N], b[N], c[N],p[N];
int tmp1[4], tmp2[4]; //���ڴ�����β�͵ı���ö��

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		memset(p, 0, sizeof p);
		int up_bound = n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		for (int i = 1; i <= n; i++) cin >> c[i];
		//�Ȱ� ǰn��ż��������д�� ���� ��n=5 ���Ȱ� n= 4��������д��
		if (n % 2 == 1)  up_bound--;
		for (int i = 1; i <= up_bound; i =i + 2) p[i] = a[i];
		for (int i = 2; i < up_bound ; i = i + 2)
		{
			if (a[i] != p[i - 1] && a[i] != p[i + 1]) p[i] = a[i];
			else if (b[i] != p[i - 1] && b[i] != p[i + 1]) p[i] = b[i];
			else if (c[i] != p[i - 1] && c[i] != p[i + 1]) p[i] = c[i];
		}

		// ������ ��ʣ�� nΪż�� ��ʣ���һ������û��д   nΪ���� ��ʣ�������������û��д
		if (up_bound != n) //˵�����������������Ҫ��
		{
			tmp1[1] = a[up_bound], tmp1[2] = b[up_bound], tmp1[3] = c[up_bound];
			tmp2[1] = a[n], tmp2[2] = b[n], tmp2[3] = c[n];
			//����ö���������п���
			bool sucess = false;
			for (int i = 1; i <= 3; i++)
			{
				for (int j = 1; j <= 3; j++)
				{
					// ������  �����ڶ������������ tmp1[i] ������һ��������д����tmp2[j]
					if (tmp1[i] != p[up_bound - 1] && tmp1[i] != tmp2[j] && tmp2[j] != p[1])
					{
						p[up_bound] = tmp1[i];
						p[n] = tmp2[j];
						sucess = true;
						break;
					}
				}
				if (sucess) break;
			}
		}
		else //���� ����ֻ��Ҫ��д���һ����
		{
			tmp1[1] = a[n], tmp1[2] = b[n], tmp1[3] = c[n];
			for (int i = 1; i <= 3; i++)
			{
				//������ ���һ��������д���� tmp1[i]
				if (tmp1[i] != p[up_bound - 1] && tmp1[i] != p[1])
				{
					p[n] = tmp1[i];
					break;
				}
			}
		}
		//������
		for (int i = 1; i <= n; i++) cout << p[i] << " ";
		cout << endl;
	}
	return 0;
}