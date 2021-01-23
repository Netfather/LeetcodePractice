
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

// Way1 : 时间和空间复杂度都特别高，应该可以考虑DP，而不是暴力搜索+减枝
//DP不行  这是唯一的办法，我使用方法的问题在于。检测路径重复过程的复杂度过高，应该
//改为这一步有重复的改为* 在这次检测完成之后，再改回来。
int flag = 0;
//如下函数用于检测路径是否有重复
bool Judge(vector<vector<int>>& step)
{
	int flag_judge = 0;
	if (step.size() > 1)
	{
		for (int i = 0; i < step.size() - 2; i++)
		{
			if (step[i] == step[step.size() - 1])
			{
				flag_judge = 1;
				break;
			}
		}
	}
	if (flag_judge == 1) return false;
	else return true;
}

//step用于记录目前走的路径，用于排除重复的格子。 i用于记录目前在word字符串中检测到什么位置了
// m 代表行 n代表列
void Search(vector<vector<char>>& board, string word, vector<vector<int>>& step, int i, int m, int n)
{
	if (i == word.size())
	{
		flag = 1;
		return;
	}

	if (Judge(step) && word[i] == board[step[i][0]][step[i][1]] && flag == 0)
	{
		//下检测
		if (step[i][0] <m - 1 && flag == 0)
		{
			step.push_back({ step[i][0] + 1, step[i][1] });
			Search(board, word, step, i + 1, m, n);
			step.pop_back();
		}
		//上检测
		if (step[i][0] > 0 && flag == 0)
		{
			step.push_back({ step[i][0] - 1, step[i][1] });
			Search(board, word, step, i + 1, m, n);
			step.pop_back();
		}
		//左检测
		if (step[i][1] > 0 && flag == 0)
		{
			step.push_back({ step[i][0], step[i][1] - 1 });
			Search(board, word, step, i + 1, m, n);
			step.pop_back();
		}
		//右检测
		if (step[i][1] < n - 1 && flag == 0)
		{
			step.push_back({ step[i][0], step[i][1] + 1 });
			Search(board, word, step, i + 1, m, n);
			step.pop_back();
		}
	}
	return;

}

bool exist(vector<vector<char>>& board, string word) {
	vector<vector<int>> step;
	int search_i = 0;
	if (board.empty()) return false;
	int m = board.size();
	int n = board[0].size();
	if (m == 1 && n == 1)
	{
		if (word.size() > 1) return false;
		else
		{
			if (board[0][0] == word[0]) return true;
			return false;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == word[search_i] && flag == 0)
			{
				step.push_back({ i, j });
				Search(board, word, step, 0, m, n);
				if (flag == 0) step.clear();
			}
			else if (flag == 1) break;
		}
		if (flag == 1) break;
	}
	if (flag == 1) return true;
	else return false;
}



int main()
{
	vector<vector<char>> board =
	{
		{ 'A' },
	};
	string word = "A";

	bool res = exist(board, word);
	
	cout << res << endl;
	system("Pause");
	return 0;
}

*/