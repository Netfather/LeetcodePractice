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

// ��������������  ǰk��Сд��ĸ�� ���ִ��� ���ٵ���ĸ ���ֵĴ��������ܶ�

// ��ô�����������  ��ê��һ�� ���ִ���������ĸ��Ȼ����������ĸ�Ĵ��� ��Ϊ m -1
// ���������������� ��ʵ����  ��k��С�������� Ȼ�󲻶��ظ� ֱ������s�ĳ��ȼ���

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		while (s.length() < n)
		{
			for (int i = 0; i < k; i++)
			{
				char word = 'a' + i;
				s += word;
				if (s.length() >= n) break;
			}
		}
		cout << s << endl;
	}


	return 0;
}