
//1. ��һ���������ַ����ĳ���˳�򣬴�С��������

/*

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

void swap(vector<string> &strs)
{
	string temp;
	int len_ele = 0; //���ڱ���ÿһ��Ԫ�س���
	int len_ele_temp = strs[0].length(); //���ڱ���ÿһ��Ԫ�ص���һ������
	int pos_ele = 0; //���ڱ��浱ǰ�±�
	int pos_ele_temp = 0; //���ڱ���ǰһ��Ԫ�ص��±�
	for (int i = 0; i < strs.size(); i++)
	{
		len_ele = strs[i].length();
		pos_ele = i;
		if (len_ele_temp > len_ele)
		{
			len_ele_temp = len_ele;
			pos_ele_temp = pos_ele;
		}
	}//���֮����Сֵ���±�ͱ�����pos_ele_temp��
	temp = strs[0];
	strs[0] = strs[pos_ele_temp];
	strs[pos_ele_temp] = temp;
}

string longestCommonPrefix(vector<string>& strs) {
	string s;
	if (strs.size() == 0) return s; 
	if (strs.size() == 1) return strs[0];
	string temp_s; //������һ����� ���ڱȽ��Ƿ����ֵ
	swap(strs);
	//Switch������Ԫ�غ���С���ȵ�Ԫ��
	int length = strs[0].length();
	int i=0,j=0,len = 0; //�ֱ����ѭ���Ĳ���
	for (i = 0; i < 1; i++)
	{
		for (j = i ; j < length; j++)
		{
			s = strs[0].substr(i, j + 1);
			for (len = 1; len < strs.size(); len++)
			{
				if (s != strs[len].substr(i, j + 1) ) break;
				else if (s == strs[len].substr(i, j + 1) && len == strs.size() - 1)
				{
					if (temp_s.length() < s.length()) temp_s = s;
				}
			}
		}
	}
	return temp_s;
}

int main()
{
	vector<string> strs = { "flower", "flow", "flight" };
	
	cout << longestCommonPrefix(strs) << endl;
	system("Pause");
	return 0;
}

*/