//#include <iostream>
//#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
//#include <sstream>
//#include <map>
//#include <string>
//#include <vector>
//#include <queue>
//#include <list>
//#include <stdlib.h>
//#include <math.h>
//using namespace std;
//
//void CurFind(vector<vector<char>>& board, vector<vector<bool>> &res, int depth, int length, int m, int n)
//{
//	if (depth >= n || length >= m || depth < 0 || length < 0) return;
//	res[depth][length] = false;
//
//	if(depth <= n-2 && res[depth+1][length] == true && board[depth+1][length] == 'O') CurFind(board, res, depth + 1, length, m, n);
//	if (depth >= 1 && res[depth - 1][length] == true && board[depth - 1][length] == 'O') CurFind(board, res, depth - 1, length, m, n);
//	if (length <= m-2 && res[depth][length +1] == true && board[depth][length+1] == 'O') CurFind(board, res, depth, length+1, m, n);
//	if (length >= 1 && res[depth][length-1] == true && board[depth][length-1] == 'O') CurFind(board, res, depth, length-1, m, n);
//
//	return;
//}
//
//void solve(vector<vector<char>>& board) {
//
//	if (board.empty()) return;
//	int m = board[0].size();
//	int n = board.size();
//	if (m <= 2 || n <= 2) return;
//	vector<vector<bool>> res(n,vector<bool>(m,false));   //结果矩阵，最后完成后根据结果矩阵，凡是true的全部改成X即可
//	//初始化res
//	for (int i = 0; i < n; i++) 
//		for (int j = 0; j < m; j++) if (board[i][j] == 'O') res[i][j] = true;
//	//遍历迭代res
//	for (int i = 0; i < n;i++)
//		for (int j = 0; j < m; j++) if (i == 0 || i == n - 1 || j == 0 || j == m - 1) if (board[i][j] == 'O' && res[i][j] == true) CurFind(board, res, i, j, m, n);
//	//赋值结果
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)	if (res[i][j] == true) board[i][j] = 'X';
//	return;
//}
//
//int main()
//{
//	// vector<vector<char>> input = { {'X', 'X', 'O', 'X'},{'O', 'O', 'X', 'O'},{'O', 'X', 'O', 'X'},{'X', 'O', 'O', 'O'},{'X', 'O', 'X', 'O'} };
//	vector<vector<char>> input = { {'O', 'O', 'X', 'O'},{'O', 'X', 'O', 'X'},{'X', 'O', 'O', 'O'},{'X', 'O', 'X', 'O'} };
//	solve(input);
//	for (auto i : input)
//	{
//		for (auto j : i) cout << j << "  ";
//		cout << endl;
//	}
//
//	system("Pause");
//	return 0;
//}