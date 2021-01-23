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


bool Match(string s, string p, int i, int j,vector<vector<bool>> &memo) 
{
		if (s.empty() && p.empty()) return true;
		else if (s.empty() && !p.empty())
		{
			for (char c : p) if (c != '*') return false;
			return true;
		}
		else if (p.empty() && !s.empty()) return false;

		if (memo[i][j] != NULL) return memo[i][j];

		memo[i][j] = false;
		if (s.at(0) == p.at(0) || p.at(0) == '?')	memo[i][j] = Match(s.substr(1), p.substr(1), i + 1, j + 1, memo);
		else if (p.at(0) == '*')
		{
			if (p.length() == 1) return true;
			else
			{
				memo[i][j] = Match(s.substr(1), p, i + 1, j, memo) || Match(s, p.substr(1), i, j + 1, memo);
				memo[i][j] = memo[i][j] || Match(s.substr(1), p.substr(1), i + 1, j + 1, memo);
			}
		}
		return memo[i][j];
}

bool isMatch(string s, string p) {
	if (s == p) return true;
	if (p == "*") return true;
	if (s.empty() && p != "*") return false;
	if (p.empty()) return false;
	vector<vector<bool>> memo(s.length());
	for (int i = 0; i < s.length(); i++)
	{
		memo[i].resize(p.length());
	}
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < p.length(); j++)
		{
			memo[i][j] = NULL;
		}
	}
	return Match(s, p,0,0,memo);
}

int main()
{
	string s = "abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb";
	string p = "*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa*";
	cout <<isMatch(s,p) << endl;
	system("Pause");
	return 0;
}
*/