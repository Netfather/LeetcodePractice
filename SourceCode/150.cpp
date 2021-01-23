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
//int evalRPN(vector<string>& tokens) {
//	stack<int> operation;
//	int opera1;
//	int opera2;
//	for (int i = 0; i < tokens.size(); i++)
//	{
//		if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") operation.push(stoi(tokens[i]));
//		else
//		{
//			opera1 = operation.top();
//			operation.pop();
//			opera2 = operation.top();
//			operation.pop();
//			if (tokens[i] == "+") operation.push(opera1 + opera2);
//			if (tokens[i] == "-") operation.push(opera2 - opera1);
//			if (tokens[i] == "*") operation.push(opera1 * opera2);
//			if (tokens[i] == "/") operation.push(opera2 / opera1);
//		}
//	}
//	return operation.top();
//}
//
//int main()
//{
//	vector<string> tokens = { "4", "13", "5", "/", "+" };
//	cout << evalRPN(tokens)<<endl;
//	system("Pause");
//	return 0;
//}