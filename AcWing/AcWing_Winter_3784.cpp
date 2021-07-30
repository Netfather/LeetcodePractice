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

//ͨ���۲�  �������� ���ǿ��Է���  ���ֲ��� ��� ָ��λ�õ��ַ������� ���Լ�Ϊ����ģʽ
// ֻҪΪ1�Ĳ��� ��ô��λ�ú����һ��λ�õ����� ֻҪ��֤ ��Χ��ȷ����   
// 0�Ĳ��־����ǵ��壬 ����� 1֮�������
// ���� 1 0 1 ����  ǰ1 ֮ǰ������ ��Զ�����ܴ��ݵ� ��1 ���� 
// ����ж��ܷ��Ϊ���������  ��Ҫ����1����   ȷ��1 ��������1 ���ֵ�����  ������ȷ����ķ�Χ��
// ��Ҫ����2 ȷ�� ����0���ֵ�����  �ٷְٶ�Ӧ 

//����ٸ�������˵�� ������˼·
// ����������һ���ַ�����  0110001010
// �����������֪ ����֪�� 0�����þ���������� �����1֮������� �����ζ������1 �ڰ�����������Ҫ ����ȷ�ķ�Χ�� ���ǳ�Ҫ����1
// ��ֻ��������1�����У����ǻ���Ҫ���ǵ� ����0 ����0�� 0��λ�ñ��뱣֤λ����ȫ��ȷ ���ǳ�Ҫ����2
// ��������⿼����˫ָ�����ʽ�� һ��ָ��p_1���� �������� �ַ�����־λ  һ��ָ��p_2���ڼ�¼ ����1����ʼλ�� �����ж�


const int N = 200010;
int w[N];
int flags[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	string flags;
	cin >> flags;
	flags = "?" + flags + "0";  //�������ĩβ�ڱ�Ԫ�أ� ĩβ�ڱ�Ҳ������������ ��Ϊ�Ѿ�û��Ԫ���ˣ� ����״̬ҲΪ0

	int prev = 0; //�洢��һ�ε� flags�б�־   ע���±�Ϊ0��Ԫ�� Ҳ����-1λ�ã�����1��Ԫ�ز�������ǰ�� ����prev����ʼ״̬Ϊ0
	int p_1 = 1;// ָ��1 ����̽�� flags�е�����
	int p_2 = 1;// ָ��2 ���ڼ�¼����̽�����ʼλ�� �����ж�

	for (; p_1 <= n;)
	{
		//���ڱ���p_2ʱ�򣬴洢��Χ��Ԫ�ص������Сֵ
		int max_temp = INT_MIN;
		int min_temp = INT_MAX;
		//��Ҫ����2�жϣ����������������0 ��ô���Ǳ��뱣֤��ǰ��Ԫ�� �ض�������ȷλ���ϵ�
		if (prev == 0 && flags[p_1] == '0')
		{
			//����Ϊ����0�ĵڶ���  
			if (w[p_1] != p_1)
			{
				cout << "NO" << endl;
				return 0;
			}
			//����ָ�� ��  ��һ�ε�prev
			prev = 0;
			p_1++;
			p_2 = p_1;
		}
		// ��ʱΪ���ܵ���ʼλ��  ��ʱ��Ҫ��p_2��¼p_1λ�� 
		else if (prev == 0 && flags[p_1] == '1')
		{
			p_2 = p_1;
			p_1++;
			prev = 1;
		}
		// ��Ҫ����1 �жϣ�����1���˾�ͷ  ��ʱ��Ҫ�ж� [p2,p1]��Χ�������Ƿ�����ȷ��Χ
		else if (prev == 1 && flags[p_1] == '0')
		{
			int lower_bound = p_2;
			//��ʱ˵������1 ��ͷ��
			while (p_2 <= p_1)
			{
				max_temp = max(w[p_2], max_temp);
				min_temp = min(w[p_2], min_temp);
				p_2++;
			}
			if (max_temp > p_1 || min_temp < lower_bound)
			{
				cout << "NO" << endl;
				return 0;
			}
			//����ָ�� �� ��һ�ε�prev
			p_1++;
			prev = 0;
		}
		// ����1��ʱ��   ���±�Ҫ��������
		else if (prev == 1 && flags[p_1] == '1') p_1++, prev = 1;
	}

	cout << "YES" << endl;
	return 0;
}