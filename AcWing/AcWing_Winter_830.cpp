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

//�����ߵ�һ������С������ �����ĺ��ľ����� ����վ�ڵ�i������ ��ǰ�� ������i֮ǰ ��a[i]������� �Ǿ��Բ�������֮���õ���
// ����÷�֤������֤�� ��˻�����һ�� ����ÿһ��ά��һ��ջ��ָ�����һ���µ����� ��ȥ�鿴ջ����Ԫ�أ��������б�i������֣�Ȼ���i��ջ
const int N = 100010;
int w[N];
int res[N];


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> w[i];

	int l = 0; // ָ��
	stack<int> s; // ջ��ά��
	while (l < n)
	{
		int t = w[l]; // �õ�Ŀǰ��������� վ�����������ǰ����ջ
		while (!s.empty() && s.top() >= t) s.pop(); // һֱ���������ջ��ֱ����ջΪ�� ���� ջ��Ԫ�ر�  tС
		if (s.empty()) res[l] = -1; // ����һ��ѭ������ֻ�����ֿ��ܣ� �ֱ��������ֿ���
		else res[l] = s.top();
		s.push(t); // �����˰�Ŀǰվ�ڵ������ѹ��ջ��
		l++;
	}
	for (int i = 0; i < n; i++) cout << res[i] << " ";


	return 0;
}