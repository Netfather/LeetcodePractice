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

// ������ѧ�Ƶ� ���Ǽٶ�n��¥�㴦�ڦ��㣬��ô�ض���
//  2 + (�� - 2) * x < n < =  2 + (�� - 1) * x
// �򻯺� ���ǵõ�  ��  < (n - 2) / x + 2
//   �� >= (n-2) / x + 1
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