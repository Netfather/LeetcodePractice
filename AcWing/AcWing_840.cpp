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


int main()
{
	unordered_set<int> res;
	int op;
	cin >> op;
	while (op--)
	{
		char Op;
		int a;
		cin >> Op >> a;
		if (Op == 'I') res.insert(a);
		else
		{
			if (res.count(a)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}


	}
	return 0;
}