//˼·��
// ��ϣ���ѯ �������ǵ���Ŀ

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


unordered_set<int> hash_check;
int res = 0;

int main()
{
	int n, k;
	cin >> n >> k;
	hash_check.insert(0); //��������� 0��ʾ���� �����ĸ�ֵһ���ǺϷ���
	while (k--)
	{
		int xi, yi;
		cin >> xi >> yi;
		if (!hash_check.count(yi)) res++;
		hash_check.insert(xi);
	}
	cout << res << endl;
}