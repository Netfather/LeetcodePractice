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
////Way1: 融合list和哈希表存储地址，不断维护一个全新的最小值序列。
////class MinStack {
////private:
////	int loc;
////	stack<int> Stack;
////	list<int> Listmin;
////	unordered_map<int, list<int>::iterator> ListAddress;
////public:
////	/** initialize your data structure here. */
////	MinStack() {
////		loc = 0;
////	}
////
////	void push(int x) {
////		list<int>::iterator SearchLoc = Listmin.begin();
////		for (; SearchLoc != Listmin.end(); ++SearchLoc) if (*SearchLoc > x) break;
////		SearchLoc = Listmin.insert(SearchLoc, x);
////		ListAddress.insert({ loc,SearchLoc });
////		++loc;
////		Stack.push(x);
////	}
////
////	void pop() {
////		--loc;
////		Listmin.erase(ListAddress[loc]);
////		ListAddress.erase(loc);
////		Stack.pop();
////	}
////
////	int top() {
////		//cout << Stack.top()<<endl;
////		return Stack.top();
////	}
////
////	int getMin() {
////		//cout << Listmin.front() << endl;
////		return Listmin.front();
////	}
////};
//
//
//class MinStack {
//private:
//	int min_temp;
//	stack<int> Sta;
//	stack<int> Min_Store;
//public:
//	/** initialize your data structure here. */
//	MinStack() {
//		min_temp = INT_MAX;
//	}
//
//	void push(int x) {
//		if (x <= min_temp) Min_Store.push(x);
//		min_temp = Min_Store.top();
//		Sta.push(x);
//	}
//
//	void pop() {
//		if (Min_Store.top() == Sta.top()) Min_Store.pop();
//		if(!Min_Store.empty()) min_temp = Min_Store.top();
//		else min_temp = INT_MAX;
//		Sta.pop();
//	}
//
//	int top() {
//		cout << Sta.top() << endl;
//		return Sta.top();
//	}
//
//	int getMin() {
//		cout << Min_Store.top() << endl;
//		return Min_Store.top();
//	}
//};
//
//
//
//int main()
//{
//	MinStack minStack;
//	minStack.push(2147483646);
//	minStack.push(2147483646);
//	minStack.push(2147483647);
//	minStack.top();
//	minStack.pop();    // return 0
//	minStack.getMin(); // return -3
//	minStack.pop(); // return -2
//	minStack.getMin(); // return -3
//	minStack.pop(); // return -2
//	minStack.push(2147483647);
//	minStack.top();
//	minStack.getMin(); // return -3
//	minStack.push(INT_MIN);
//	minStack.top();
//	minStack.getMin(); // return -3
//	minStack.pop();    // return 0
//	minStack.getMin(); // return -3
//
//
//	system("Pause");
//	return 0;
//}