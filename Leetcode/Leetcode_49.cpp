
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
	vector<vector<string>> res; //结果表
	vector<string> tempres;
	if (strs.empty()) return res;
	tempres.push_back(strs[0]);
	res.push_back(tempres); //初始化输出结果
	if (strs.size() == 1) return res;
	vector<map<char, int>> Dic;  //字典表
	map<char, int> Fre;
	for (char c : strs[0]) ++Fre[c];
	Dic.push_back(Fre);
	Fre.clear();
	tempres.clear();
	//两表初始化完成

	for (int i = 1; i < strs.size(); i++)
	{
		for (char c : strs[i]) ++Fre[c]; //统计字典
		tempres.push_back(strs[i]);
		//检测目前统计字典在已有的字典中是否有相同的，有，则结果更新，没有结果更新同时字典更新
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
			Dic.push_back(Fre); //字典更新		
			res.push_back(tempres); //结果更新新一行
		}
		tempres.clear();
		Fre.clear();
	}
	return res;

}


int main()
{
	vector<vector<string>> res; //结果表
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