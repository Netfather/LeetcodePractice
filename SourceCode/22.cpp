/*

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;
//n��ʾ���ٴΣ�index��ʾ�ݹ鵽���ٲ�,resΪ�洢������,temp��ʾ��ǰ�洢����λ�ã���indexΪnʱ��temp����
//stratΪ��ǰ��ʼλ��
void backtrack(vector<string> &ans, string cur, int open, int close, int max){
	if (cur.length() == max * 2) {
		ans.push_back(cur);
		return;
	}

	if (open < max)
		backtrack(ans, cur + "(", open + 1, close, max);
	if (close < open)
		backtrack(ans, cur + ")", open, close + 1, max);
}


vector<string> generateParenthesis(int n) {
	vector<string> res;
	backtrack(res, "", 0, 0, n);
	return res;
}


int main()
{
	vector<string> res;
	string temp;
	generateParenthesis(3);
	cout << "Hello" << endl;
	system("Pause");
	return 0;
}

*/