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

// �ǳ��ǳ��򵥵�һ����
// ��A���� k��  ��B����ѡm��  ʹ�� A�е��������� һ��С�� B�е���������
// ����������Ȼ�ǽ���  ��� ��Ҳ����ζ��  ���ǼǴ�A��������Ϊ Sa  ��B�е�����Ϊ Sb
// max Sa  <   min Sb
// ��maxSa  ������  Ҳ��Ȼ�� A�еĵ�k����
// min Sb ������ Ҳ��Ȼ�� B�дӺ���ǰ�� m������
// ��������ý�



int main()
{
	int na, nb;
	cin >> na >> nb;
	int k, m;
	cin >> k >> m;
	int maxSa = 0, minSb = 0;
	for (int i = 1; i <= na; i++)
	{
		int tmp;
		cin >> tmp;
		if (i == k) maxSa = tmp;
	}
	for (int i = 1; i <= nb; i++)
	{
		int tmp;
		cin >> tmp;
		if (i == (nb - m + 1)) minSb = tmp;
	}
	if (maxSa < minSb) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}