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

//�ǳ��򵥵�ģ����   Ԥ����һ�� ����Ϊn������ ��ÿ������֮���ʱ��¼��
// ����������   ������λ�õ�   >c λ�õ� ���� �鿴�������鼴��  �ǳ��ļ�

int res = 1; 
const int N = 100010;
int t[N];
int b_t[N];

int main()
{
	int n, c;
	cin >> n >> c;

	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 1; i < n; i++) b_t[i] = t[i + 1] - t[i];

	for (int i = n - 1; i >= 1; i--)
	{
		if (b_t[i] <= c) res++;
		else break;
	}
	cout << res << endl;
	return 0;
}