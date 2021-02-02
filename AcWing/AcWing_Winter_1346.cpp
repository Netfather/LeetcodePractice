//思路：  非常基礎的進制轉換問題


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
#include <climits>
using namespace std;
string res = "";
char c[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
bool convertB(int num,int B)
{
	res.clear();
	while (num != 0)
	{
		res += c[num % B];
		num = num / B;
	}
	string temp = res;
	reverse(res.begin(), res.end());
	if (temp == res) return true;
	return false;
}


int main()
{
	int B = -1;
	cin >> B;
	for (int i = 1; i <= 300; i++)
	{
		if(convertB(i*i, B))
		{
			string temp = res;
			convertB(i, B);
			cout << res << " " << temp << endl;
		}
	}
	system("Pause");
	return 0;
}