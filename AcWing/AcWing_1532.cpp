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


// �ǳ���ͨ�Ĺ�ϣ�팑��
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

//ԇһԇ�pָᘌ�����Ҳ���T��Č���
//�T�匑�����P�I���Ҫ���x���@�ɂ������״���ʲ�N��Ȼ�ᮔһ�����\�ӕr�����C��һ����ͬ�ӆ��{׃��

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
