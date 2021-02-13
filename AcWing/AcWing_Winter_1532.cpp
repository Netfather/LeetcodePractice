//思路：

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


// 非常普通的哈希表寫法
//int main()
//{
//	int N, M;
//	cin >> N >> M;
//	unordered_set<int> HashTable;
//	int res = INT_MAX;
//	for (int i = 0; i < N ; i++)
//	{
//		int tmp;
//		cin >> tmp;
//		if (HashTable.count(M - tmp))
//		{
//			if (tmp > M - tmp && res > M - tmp) res = M - tmp;
//			else if (res > tmp) res =  tmp;
//		}
//		HashTable.insert(tmp);
//	}
//
//	if (res == INT_MAX) cout << "No Solution" << endl;
//	else cout << res << " " << M - res << endl;
//	return 0;
//}

//試一試雙指針寫法，也是門板的寫法
//門板寫法的關鍵在於要定義好這兩個量到底代表什麼，然後當一方在運動時，保證另一方在同樣單調變化

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> Table(N,INT_MIN);
	for (int i = 0; i < N - 1; i++) cin >> Table[i];
	sort(Table.begin(), Table.end());

	int i = 0,j = N - 1;

	while (i < j)
	{
		while (Table[j] > M - Table[i]) j--;
		if(i < j && Table[i] + Table[j] == M)
		{
			cout << Table[i] << " " << Table[j] << endl;
			return 0;
		}
		i++;	
	}
	cout << "No Solution" << endl;
	system("Pause");
	return 0;
}
