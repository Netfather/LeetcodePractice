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

// ������Ŀû����ϸ˵�������������ر�˵��һ�£��ǿ����ظ�ѡȡ��
// ��ô���������Ϳ��Խ�һ���˻�������ȡֵ��Χ��һ�����������
// ���ʵ���Ϲؼ����� 2 3 �������ʡ�
// ������ѡȡ��ʱ��ֱ�ӱ�֤  ��λ����ֵ��С��y  Ȼ������������� �ҵ� ����Ԫ�غ͵���Сֵ
// �鿴�����Сֵ�Ƿ񲻴���x����  ��������˻�Ϊ ��α�֤ ��λ����ֵ��С��y
// ������λ�������ʣ� �������͵������У��ض��� n / 2�� С��y��  �ض��� n/2 + 1�� ���ڵ���y��
// ��ô���Ƕ���δ��ɵ����鲹��  ����  

// ���� ��Ҫ��֤���ĺͱض�������x ��˽�����y�ʹ���y���ֵ�һ����û������ģ��������Ա�֤ С��y�Ĳ��־����ĳ�
// ���������λ����Ŀ��ֵǡ���� ��Сȡֵ�½磬��ô��ʱ�ͻ������⡣ ������������Ҫ����һ��

const int N = 1004;
int w[N];

int main()
{
	int n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;
	int cnt_less_y = 0, cnt_larg_y = 0; //�洢��֪������ С��y �ʹ���y�ĸ���
	int sum_smlst = 0; //�洢������ܴﵽ����С�ĺ�

	for (int i = 0; i < k; i++)
	{
		cin >> w[i];
		if (w[i] < y) ++cnt_less_y;
		else ++cnt_larg_y;
		sum_smlst += w[i];
	}
	// ����һ�� y�Ƿ�������ȡֵ���½�
	if (y == 1)
	{
		// ���y��1 ��ôȡֵֻ�п���ȡ1����������������
		sum_smlst += (n - k); 
		if (sum_smlst > x)
		{
			cout << -1 << endl;
			return 0;
		}
		for (int i = 0; i < n - k; i++) cout << 1 << " ";
		return 0;
	}
	//�ж��Ƿ���ں�����
	if (cnt_less_y > n / 2 || cnt_larg_y > n / 2 + 1 || sum_smlst > x) cout << -1 << endl;
	else
	{
		//�����Ӧ��1 �Ͷ�Ӧ��y
		sum_smlst += (n / 2 - cnt_less_y) * 1 + (n / 2 + 1 - cnt_larg_y ) * y;
		if (sum_smlst > x)
		{
			cout << -1 << endl;
			return 0;
		}
		for (int i = 0; i < n / 2 - cnt_less_y; i++) cout << 1 << " ";
		for (int i = 0; i < n / 2 + 1 - cnt_larg_y ; i++) cout << y << " ";
	}
	return 0;
}