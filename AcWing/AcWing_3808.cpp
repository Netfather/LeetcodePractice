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

// �����ܽ���n����������֯��  һ���������ε���ʽ
// Լ��  (k-1)ƽ��  < n < kƽ��
// ���nǡ�õ���ĳ��k��ƽ����ʱ��  ����ض��� 2k
// ���������k��ƽ��  ����ض���  k +  n % (k)   ����಻���1 ȡ���� �ܷ񱻳��� �Ƿ���β��

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int k_l = int(sqrt(n));
		if (k_l * k_l == n)
		{
			cout << 2 * k_l << endl;
			continue;
		}
		int k_r = k_l + 1;
		if (n % k_r) cout << (k_r)+n / (k_r)+1 << endl;
		else cout << (k_r)+n / (k_r) << endl;
	}
	return 0;
}