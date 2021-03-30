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

//�ַ�����ϣ�Ƿǳ��ǳ�ǿ��һ������ ��Ȼ�п���ʧЧ ���Ǵ�������ʧЧ�ĸ��ʺܵ�
// ʵ�ִ˷����Ĺؼ�������������һ��  h  һ��p
// h���ڴ洢ǰ ���ٸ� �ַ������Ĺ�ϣֵ
// p���ڴ洢ǰ ���� l r ���䳤��ʱ��Ĺ�ϣֵ    ͬʱΪ�˱���mod  ֱ�ӿ�һ�� ULL ����
// һ���ϣ������ ���ַ�����Ϊһ��p���Ƶ����� Ȼ�����mod һ�� 2��64�η�
typedef unsigned long long ULL;
const int N = 1000010;
int P = 13331;
ULL h[N];
ULL p[N];   // ����ǽ��ƴ洢�� ���ڴ洢��kλ��p����  ��ӳ��ʮ�����Ƕ�������(ֻ�е�kλλ1 ����λ����0)

// ��ѯ����  ���� �������߶˵� 
ULL query(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	int n, m;
	string a;
	cin >> n >> m;
	cin >> a;
	a = "?" + a;


	p[0] = 1;  // ��Ϊ��ʱֵΪ1
	for (int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + a[i];
	}

	while (m--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		if (query(l1, r1) == query(l2, r2)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}