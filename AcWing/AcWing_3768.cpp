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



int main()
{
	int n;
	cin >> n;
	string a;
	cin >> a;

	int cnt_x = 0;// ��¼�ж��ٸ�������x
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != 'x')
		{
			if (cnt_x >= 3) res += cnt_x - 2;
			cnt_x = 0; //�������  ��¼���
		}
		else cnt_x++;
	}
	//����һ��β��
	if (cnt_x >= 3) res += cnt_x - 2;
	cout << res << endl;
	return 0;
}