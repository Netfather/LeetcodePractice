/*
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

//T�п��ܴ����ظ�Ԫ��
string minWindow(string s, string t) {
	int m = s.length();
	int n = t.length();
	string temp_res;
	if (m < n) return temp_res;
	if (n == 1)
	{
		for (auto k : s) if (k == t[0]) return t;
	}
	if (n == 1) return temp_res;
	string res = s;
	vector<int> Standard(128,0);

	//��ʼ����׼��
	for (auto k : t) ++Standard[k];
	int start = 0;
	int end = 0;
	int flag = 0;
	for (int i = 0; i < m; i++)
	{
		flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (s[i] == t[j])
			{
				flag = 1;
				start = i;
				break;
			}
		}
		if (flag == 0)	continue;
		else if (flag == 1) break;
	}
	//��ʼ��s��
	while (end < m)
	{
		if (--Standard[s[end++]] >= 0) n--;
		while (n == 0)
		{
			if (end - start < res.length())
			{
				res = s.substr(start, end - start);
			}
			if (++Standard[s[start++]] > 0) n++;
		}
	}
	return res;
}

int main()
{
	string a = "ADOBECODEBANC";
	string b = 	"ABC";
	cout << minWindow(a, b) << endl;
	system("Pause");
	return 0;
}

*/

