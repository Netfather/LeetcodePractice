//思路： 這道題就是動態規劃思路最簡單的應用，自底向上和自頂向下。 使用法1 使用的內存會大，使用法2 使用的時間其實應該更短，但是偷懶使用了隊列
// 同時由於法2 使用了隊列，非常的節省內存空間

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <stdlib.h>
#include <math.h>
#include <climits>
using namespace std;


//法1 自底向上的memo法
//int PathSum(vector<vector<int>> &Triangle, vector<vector<int>> &Memo,int i,int j)
//{
//	if (Memo[i][j] != INT_MIN) return Memo[i][j];
//	if (i == 0) return Triangle[0][0];
//	if (i == 1 && j == 0) return  Triangle[1][0];
//	if (i == 1 && j == 1) return  Triangle[1][1];
//
//	if (j == 0) Memo[i][j] = Triangle[i][j] + PathSum(Triangle, Memo, i - 1, 0);
//	else if (j < Triangle[i].size() - 1) Memo[i][j] = Triangle[i][j] +  max( PathSum(Triangle, Memo, i - 1, j-1) , PathSum(Triangle, Memo, i - 1, j));
//	else Memo[i][j] = Triangle[i][j] + PathSum(Triangle, Memo, i - 1, Triangle[i].size() - 2);
//	return Memo[i][j];
//}
//
//int main()
//{
//	int N = -1;
//	cin >> N;
//	vector<vector<int>> Triangle;
//	vector<vector<int>> Memo;
//	for (int i = 0; i < N; i++)
//	{
//		vector<int> EveryLine(i + 1, INT_MIN);
//		vector<int> Memo_temp(i + 1, INT_MIN);
//		for (int j = 0; j < i + 1; j++) cin >> EveryLine[j];
//		Triangle.push_back(EveryLine);
//		Memo.push_back(Memo_temp);
//	}
//	int res = INT_MIN;
//	for (int i = 0; i < Triangle[N - 1].size(); i++)
//	{
//		res = max(res, PathSum(Triangle, Memo, N - 1, i));
//	}
//	cout << res << endl;
//
//	return 0;
//}


//法2 自定向下的DP法
//int main()
//{
//	int N = -1;
//	cin >> N;
//	int res = INT_MIN;
//	queue<vector<int>> Memo;
//	int first = INT_MIN;
//	cin >> first;
//	Memo.push(vector<int>(1, first));
//
//	for (int i = 1; i < N; i++)
//	{
//		vector<int> Memo_last(i + 1, INT_MIN);
//		Memo.push(Memo_last);
//		for (int j = 0; j < i + 1; j++)
//		{
//			int temp;
//			cin >> temp;
//			if (j == 0) Memo.back()[j] = temp + Memo.front()[j];
//			else if (j == i) Memo.back()[j] = temp + Memo.front()[j-1];
//			else Memo.back()[j] = temp + max(Memo.front()[j-1], Memo.front()[j]);
//			if (i == N - 1) res = max(res, Memo.back()[j]);
//		}
//		Memo.pop();
//	}
//	cout << res << endl;
//
//	return 0;
//}
