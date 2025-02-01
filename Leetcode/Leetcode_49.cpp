
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

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> res; //�����
	vector<string> tempres;
	if (strs.empty()) return res;
	tempres.push_back(strs[0]);
	res.push_back(tempres); //��ʼ��������
	if (strs.size() == 1) return res;
	vector<map<char, int>> Dic;  //�ֵ��
	map<char, int> Fre;
	for (char c : strs[0]) ++Fre[c];
	Dic.push_back(Fre);
	Fre.clear();
	tempres.clear();
	//�����ʼ�����

	for (int i = 1; i < strs.size(); i++)
	{
		for (char c : strs[i]) ++Fre[c]; //ͳ���ֵ�
		tempres.push_back(strs[i]);
		//���Ŀǰͳ���ֵ������е��ֵ����Ƿ�����ͬ�ģ��У��������£�û�н������ͬʱ�ֵ����
		int flag = 0;
		for (int j = 0; j < Dic.size();j++)
		{
			if (strs[i].length()==res[j][0].length() && Dic[j] == Fre)
			{
				res[j].push_back(strs[i]);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			Dic.push_back(Fre); //�ֵ����		
			res.push_back(tempres); //���������һ��
		}
		tempres.clear();
		Fre.clear();
	}
	return res;

}


int main()
{
	vector<vector<string>> res; //�����
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	res = groupAnagrams(strs);
	for (vector<string> m : res)
	{
		for (string n : m)
		{
			cout << n << "  ";
		}
		cout << endl;
	}

	system("Pause");
	return 0;
}

*/