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

//�ǳ��򵥵�һ���⣬�����������Ҫ�� a�����ܶ��Զ��b��ͬʱ��Ҫ��֤ max pi�����ܵ�С
// ��ôֻ��һ����� �Ǿ���  pi�����е����ֶ�����ȵ� �� piֻ���� ai= 1��λ�òŻ�ȡ��ֵ
// �����������  ��ai = bi pi�Ķ��ٲ���Բ���ʽ����κ�Ӱ��
// �� ai = 1 bi = 0��ʱ�� �˲���ʽ����ٳ�����

// ���������˻�Ϊ   ͳ��һ��  ai ���ж��ٸ� ֻ���Լ�Ϊ1�� ���� ��Ϊcnt_ai
// ͳ��һ�� bi���ж��ٸ� ֻ���Լ�Ϊ1�Ĵ��� ��Ϊcnt_bi
// ���ͳ��һ��  ai bi��Ϊ1�Ĵ��� ��Ϊcnt_both
// Ѱ��ʹ��   cnt_ai * res > cnt_bi ��������С ����
// ���޽�ֻ��һ����� �Ǿ��� cnt_ai Ϊ0 ��ʱ����res��� ���޷�ʹ�ò���ʽ����

const int N = 110;
int a[N], b[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	//ͳ��
	int cnt_ai = 0, cnt_bi = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1 && b[i] != 1) cnt_ai++;
		if (a[i] != 1 && b[i] == 1) cnt_bi++;
	}
	if (cnt_ai == 0) cout << -1 << endl;
	else cout << cnt_bi / cnt_ai + 1 << endl;

	return 0;
}