
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
map<char, char> cc = { { '(', ')' }, { '[', ']' }, { '{', '}' } };

//Way1 : 递归
bool isValid(string s) {
	int  lenth = s.length();
	int flag = 1;
	int i = 0;
	if (lenth == 2)
	{
		if (s.at(1) == cc[s.at(0)]) return true;
		else return false;
	}
	else if (lenth % 2 != 0) return false;
	else if (lenth == 0) return true;
	else 
	{
		for (i = 0; i < lenth -1 ;i++)
		{
			if (s.at(i + 1) != cc[s.at(i)] && i < lenth - 2)
			{
				flag = flag + 1;
				continue;
			}
			else if (s.at(i + 1) == cc[s.at(i)] && i < lenth - 2)
			{
				s.at(i) = 'a';
				s.at(i + 1) = 'a';
				continue;
			}
			else if ( i == lenth - 2)
			{
				if (flag == s.length()-1) return false;
				for (int j = 0; j < s.length();)
				{
					if (s.at(j) == 'a')
					{
						s = s.erase(j, 1);
						continue;
					}
					j++;
				}
				return isValid(s);
			}
		}
	}
	return isValid(s);
}
*/

/*
bool isValid(string s) {
	vector<char> a;
	int  lenth = s.length();
	int i = 0;
	if (lenth == 2)
	{
		if (s.at(1) == cc[s.at(0)]) return true;
		else return false;
	}
	else if (lenth % 2 != 0) return false;
	else if (lenth == 0) return true;
	else
	{
		for (i = 0; i < s.length(); i++)
		{
			if (  (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{') )
			{
				a.push_back(s.at(i));
			}
			else if ( (s.at(i) == ')' || s.at(i) == ']' || s.at(i) == '}') && a.size() == 0)
			{
				return false;
			}
			else if ( (s.at(i) == ')' || s.at(i) == ']' || s.at(i) == '}') && a.size() != 0)
			{
				if (s.at(i) != cc[a.back()]) return false;
				else
				{
					a.pop_back();
					continue;
				}
			}
		}
	}
	if (a.size() != 0) return false;
	return true;
}


int main()
{
	cout << isValid("(([]){})") << endl;
	system("Pause");
	return 0;
}


*/