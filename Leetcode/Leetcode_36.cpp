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

map<char, int> Fre = { { '1', 0 }, {'2',0}, {'3',0}, {'4',0}, {'5',0}, {'6',0}, {'7',0}, {'8',0}, {'9',0} };

bool horizan(vector<vector<char>>& board)
{
	int i = 0;
	int j = 0;
	int m = 48;
	for (i = 0; i < 9; i++)
	{
		//reset map
		for (m = 48; m < 58; m++)
		{
			char c = (char)m;
			Fre[m] = 0;
		}
		for (j = 0; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				if (++Fre[board[i][j]] > 1) return false;
			}
		}
	}
	return true;
}

bool vitical(vector<vector<char>>& board)
{
	int i = 0;
	int j = 0;
	int m = 48;
	for (j = 0; j < 9; j++)
	{
		//reset map
		for (m = 48; m < 58; m++)
		{
			char c = (char)m;
			Fre[m] = 0;
		}
		for (i = 0; i < 9; i++)
		{
			if (board[i][j] != '.')
			{
				if (++Fre[board[i][j]] > 1) return false;
			}
		}
	}
	return true;
}

bool subnine(vector<vector<char>>& board)
{
	int i = 0;
	int j = 0;
	int m = 48;
	for (m = 48; m < 58; m++)
	{
		char c = (char)m;
		Fre[m] = 0;
	}
	for (i = 0; i < 3; i++)
	{
		//reset map
		for (j = 0; j < 3; j++)
		{
			if (board[i][j] != '.')
			{
				if (++Fre[board[i][j]] > 1) return false;
			}
		}
	}
	for (m = 48; m < 58; m++)	Fre[(char)m] = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 3; j < 6; j++)
		{
			if (board[i][j] != '.')
			{
				if (++Fre[board[i][j]] > 1) return false;
			}
		}
	}
	for (m = 48; m < 58; m++)	Fre[(char)m] = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 6; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				if (++Fre[board[i][j]] > 1) return false;
			}
		}
	}
	for (m = 48; m < 58; m++)	Fre[(char)m] = 0;	
	for (i = 3; i < 6; i++)
	{
		//reset map
		for (j = 0; j < 3; j++)
		{
			if (board[i][j] != '.')
			{
				if (++Fre[board[i][j]] > 1) return false;
			}
		}
	}
	for (m = 48; m < 58; m++)	Fre[(char)m] = 0;
	for (i = 3; i < 6; i++)
	{
		for (j = 3; j < 6; j++)
		{
			if (board[i][j] != '.')
			{
				if (++Fre[board[i][j]] > 1) return false;
			}
		}
	}
	for (m = 48; m < 58; m++)	Fre[(char)m] = 0;
	for (i = 3; i < 6; i++)
	{
		for (j = 6; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				if (++Fre[board[i][j]] > 1) return false;
			}
		}
	}
	for (m = 48; m < 58; m++)	Fre[(char)m] = 0;
	for (i = 6; i < 9; i++)
	{
		//reset map
		for (j = 0; j < 3; j++)
		{
			if (board[i][j] != '.')
			{
				if (++Fre[board[i][j]] > 1) return false;
			}
		}
	}
	for (m = 48; m < 58; m++)	Fre[(char)m] = 0;
	for (i = 6; i < 9; i++)
	{
		for (j = 3; j < 6; j++)
		{
			if (board[i][j] != '.')
			{
				if (++Fre[board[i][j]] > 1) return false;
			}
		}
	}
	for (m = 48; m < 58; m++)	Fre[(char)m] = 0;
	for (i = 6; i < 9; i++)
	{
		for (j = 6; j < 9; j++)
		{
			if (board[i][j] != '.')
			{
				if (++Fre[board[i][j]] > 1) return false;
			}
		}
	}
	for (m = 48; m < 58; m++)	Fre[(char)m] = 0;
	return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
	if (horizan(board) && vitical(board) && subnine(board))	return true;
	else return false;
}


int main()
{

	vector<vector<char>> board = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, { '.', '6', '.', '.', '.', '.', '2', '8', '.' }, { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
	if (isValidSudoku(board)) cout << 1 << endl;;
	system("Pause");
	return 0;
}

*/