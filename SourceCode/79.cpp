
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

// Way1 : ʱ��Ϳռ临�Ӷȶ��ر�ߣ�Ӧ�ÿ��Կ���DP�������Ǳ�������+��֦
//DP����  ����Ψһ�İ취����ʹ�÷������������ڡ����·���ظ����̵ĸ��Ӷȹ��ߣ�Ӧ��
//��Ϊ��һ�����ظ��ĸ�Ϊ* ����μ�����֮���ٸĻ�����
int flag = 0;
//���º������ڼ��·���Ƿ����ظ�
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

//step���ڼ�¼Ŀǰ�ߵ�·���������ų��ظ��ĸ��ӡ� i���ڼ�¼Ŀǰ��word�ַ����м�⵽ʲôλ����
// m ������ n������
void Search(vector<vector<char>>& board, string word, vector<vector<int>>& step, int i, int m, int n)
{
	if (i == word.size())
	{
		flag = 1;
		return;
	}

	if (Judge(step) && word[i] == board[step[i][0]][step[i][1]] && flag == 0)
	{
		//�¼��
		if (step[i][0] <m - 1 && flag == 0)
		{
			step.push_back({ step[i][0] + 1, step[i][1] });
			Search(board, word, step, i + 1, m, n);
			step.pop_back();
		}
		//�ϼ��
		if (step[i][0] > 0 && flag == 0)
		{
			step.push_back({ step[i][0] - 1, step[i][1] });
			Search(board, word, step, i + 1, m, n);
			step.pop_back();
		}
		//����
		if (step[i][1] > 0 && flag == 0)
		{
			step.push_back({ step[i][0], step[i][1] - 1 });
			Search(board, word, step, i + 1, m, n);
			step.pop_back();
		}
		//�Ҽ��
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