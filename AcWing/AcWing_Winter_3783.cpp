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

//��������Լ������   ���� һ������n �ҵ�n������Լ��
typedef long long LL;

int main()
{
	LL n, k;
	cin >> n >> k;
	vector<LL> Yueshu;

	for (int i = 1; i <= int(sqrt(n)); i++)
	{
		if (n % i == 0)
		{
			Yueshu.push_back(i);
			if (n / i != i) Yueshu.push_back(n / i); //�õ��ĳ���Ҳ��Լ��֮һ
		}
	}
	sort(Yueshu.begin(), Yueshu.end());
	if (k <= Yueshu.size()) cout << Yueshu[k - 1] << endl;
	else cout << -1 << endl;
	return 0;
}