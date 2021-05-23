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

// ����֤�� ������������� Ҫ��ֽ�Ϊ 2���ݴκ���ʽ ֻ��Ҫ�ҵ����������λ�� ��ȥ��Ӧ������ Ȼ�󲻶��ظ�����
// ��Ԥ����һ��string���͵Ĺ�ϣ���ұ� ������ൽ 2��14�η�  �����Ԥ����һ��
unordered_map<int, string> table = {
	{3,"2+2(0)"},
	{4,"2(2)"},
	{5,"2(2)+2(0)"},
	{6,"2(2)+2"},
	{7,"2(2)+2+2(0)"},
	{8,"2(2+2(0))"},
	{9,"2(2+2(0))+2(0)"},
	{10,"2(2+2(0))+2"},
	{11,"2(2+2(0))+2+2(0)"},
	{12,"2(2+2(0))+2(2)"},
	{13,"2(2+2(0))+2(2)+2(0)"},
	{14,"2(2+2(0))+2(2)+2"},
};
// ���������x ���ٷ��ض�Ӧ��2���ݴ�
int Gaowei(int x)
{
	if (x >= 16384) return 14;
	else if (x >= 8192) return 13;
	else if (x >= 4096) return 12;
	else if (x >= 2048) return 11;
	else if (x >= 1024) return 10;
	else if (x >= 512) return 9;
	else if (x >= 256) return 8;
	else if (x >= 128) return 7;
	else if (x >= 64) return 6;
	else if (x >= 32) return 5;
	else if (x >= 16) return 4;
	else if (x >= 8) return 3;
	else if (x >= 4) return 2;
	else if (x >= 2) return 1;
}
// ��������x ���ٷ��������ַ���
string Convert(int x)
{
	string a;
	while (x > 1)
	{
		int i = Gaowei(x);
		if ((i) > 2)	a += ("+2(" + table[i] + ")");
		else if ((i) == 2)  a += "+2(2)";
		else if ((i) == 1)  a += "+2";
		x = x - pow(2, i);
	}
	if (x == 1) a += "+2(0)";
	if (a[0] == '+') a.erase(0, 1);

	return a;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << Convert(n) << endl;
	}

	return 0;
}