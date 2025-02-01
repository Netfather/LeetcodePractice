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
////Way1: HashMap
//int singleNumber(vector<int>& nums) {
//	unordered_map<int,int> memo;
//	for (auto i : nums)
//	{
//		if (!memo.count(i)) memo.insert({ i,1 });
//		else ++memo[i];
//		if (memo[i] == 3) memo.erase(i);
//	}
//	return memo.begin()->first;
//}
