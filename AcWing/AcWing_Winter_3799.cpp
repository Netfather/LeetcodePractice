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
//�õȲ�������ѧ�Ƶ�һ�¿��Եõ�
//�ڵ�i��   dik �ܼƸ�����x���ǹ�    era�ܼƸ�����y���ǹ�
// ��iΪ����ʱ   x = (i+1)ƽ�� / 4
// �� iΪż��ʱ   y = ��2+i��*i / 4

// ��������ֻ��Ҫ�����ҵ���������֧���ļ���  ͨ������ʽ���Եõ�
//  �� dik��˵   i > 2����a - 1  �����������ʽ�Ĵ�С�����һ������
//  �� era��˵  i  > ����(4*b + 1) - 1�����������ʽ�Ĵ�С�����һ��ż��

// �������ֹ����Ӵ�  ��int�п��ܻ��б�int���� ����Ҫ��longlong ���洢ab �Լ��м����

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long a, b;
		cin >> a >> b;
		long long res1 = 0, res2 = 0; //�洢dik��ߵ����� ��  ear��ߵ�����
		res1 = int(2 * sqrt(a));
		if (res1 % 2 == 0) res1 = res1 + 1;
		res2 = int(sqrt(4 * b + 1));
		if (res2 % 2)res2 = res2 + 1;
		if (res1 < res2) cout << "Vladik" << endl;
		else cout << "Valera" << endl;

	}
	return 0;
}