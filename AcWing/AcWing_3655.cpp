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

// 根据数学推导 我们假定n号楼层处于α层，那么必定有
//  2 + (α - 2) * x < n < =  2 + (α - 1) * x
// 简化后 我们得到  α  < (n - 2) / x + 2
//   α >= (n-2) / x + 1
 int main()
{
	 int T;
	 cin >> T;
	 while (T--)
	 {
		 int n, x;
		 cin >> n >> x;
		 if (n <= 2)
		 {
			 cout << 1 << endl;
			 continue;
		 }
		 if ((n - 2) % x == 0)
		 {
			 cout << (n - 2) / x + 1 << endl;
			 continue;
		 }
		 cout << int((n - 2) / x) + 2 << endl;
	 }


	return 0;
}