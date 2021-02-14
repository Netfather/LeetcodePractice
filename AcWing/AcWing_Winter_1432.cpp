//˼·��

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
#include <cstring>
#include <climits>
using namespace std;

const int n = 15;
bool dig[2 * n];
bool cdig[2 * n];
bool Checktable[n];
int cnt = 0;
//�@���}�ĺ���˼·��춣���ξS�o�Ãɂ����I�Č��Ǿ�ꇣ��@�ӽo��һ��������ֱ���M���Д࣬�������M��ѭ�h

void dfs(vector<int> &tmpres, int depth, int N)
{
	//�l���Д��^
	if (depth == N)
	{
		++cnt;
		if (cnt <= 3)
		{
			for (auto i : tmpres) cout << i << " ";
			cout << endl;
		}
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		tmpres.push_back(i);
		//Checktable[i] =dig[i] = cdig[-i + N] = true ;
		if (!Checktable[i] && !dig[depth + i] && !cdig[depth - i + N])
		{
			Checktable[i] = dig[depth + i] = cdig[depth -i + N] = true;
			dfs(tmpres, depth + 1, N);
			Checktable[i] = dig[depth+ i] = cdig[depth -i + N] = false;
		}
		tmpres.pop_back();
	}
	return;
}

int main()
{
	int N;
	cin >> N;
	vector<int> tmpres;

	for (int i = 1; i <= N; i++)
	{
		tmpres.push_back(i);
		Checktable[i] = dig[i] = cdig[-i + N] = true;
		dfs(tmpres, 1, N);
		tmpres.pop_back();
		Checktable[i] = dig[i] = cdig[-i + N] = false;
	}

	cout << cnt << endl;
	system("Pause");
	return 0;
}