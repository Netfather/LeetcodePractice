//思路： 可以很容易想明白对于偶数个点，取在中间任何一个都是没问题的
//		对于奇数个点，只能取在正中间那个点所在的位置，否则任何的偏离都会导致不是最小值
//       因此这道题只需要排序，然后取中位数所在的点即可！

//#include <iostream>
//#include <algorithm>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include <sstream>
//#include <map>
//#include <stack>
//#include <string>
//#include <vector>
//#include <queue>
//#include <list>
//#include <stdlib.h>
//#include <math.h>
//using namespace std;
//
//int main()
//{
//	int N = -1;
//	cin >> N;
//	vector<int> Points(N, 0);
//	for (int i = 0; i < N; i++) cin >> Points[i];
//	sort(Points.begin(),Points.begin()+N);
//	int res = 0;
//	for (int i = 0; i < N; i++) res += abs(Points[i] - Points[N >> 1]);
//	cout << res << endl;
//	return 0;
//}