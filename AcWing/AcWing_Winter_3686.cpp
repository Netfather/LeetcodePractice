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

//�����ƶ���˵ѡȡһ������1���ɵ�   ��ô�п���ѡ���� ��������λ�� [l,r] l-1λ��Ϊ0  r+1λ��Ϊ1
//������ֻ��������ƶ��ģ��������������ѱ����ۼ���һ���1��������������������Ǿ��Բ����ܱ�ѡ����
// ��������֤�� ���ǿ��Եõ�һ�����ۣ� ÿ���ƶ�������1���� �ض��Ǳ�����0����һ��ģ�����������£�
// �����ڶ���1��ʱ��������1 ֻ��Ҫдһ��1 ����


// �����ƶ�λ�ã���ʵ��Ч�� �ƶ�һ�� Ϊ�˽����е�1�ۼ���һ��ʹ���ƶ�������С  ���ǿ���ͨ������ö�ٵķ�ʽ
// ���ٶ����ľۼ�λ������Ϊ  [m,n] ����ӵ�ǰλ��ת�Ƶ� m,n����Ҫ����̾��뼴��
// ��ʱ������˻�Ϊ ����һ������  Ȼ�����һ����ɢ01���У���������� �ƶ�Ϊ ����������С�����Ƕ��٣�
// �������۴���  ʵ���ϵĲ��� �ڲ��������л��Ю�Ѿ��ۼ���һ��� 1 һ���˶� �������ֻ��Ҫͳ�� ��һ��1 �����һ��1֮���ж��ٸ�0
// �Ϳ�����

const int N = 55;
int w[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(w, 0, sizeof w);
		int n;
		cin >> n;
		int w_prev = 0;
		int tail = 1;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			// ��������1 ֻ��¼һ��
			if (x == w_prev && x == 1) continue;
			w[tail++] = x;
			w_prev = x;
		}
		// ����ӵ�һ��1 �����һ��1֮�� �ж��ٸ�0
		vector<int> tmp;
		for (int i = 1; i < tail; i++)
		{
			if (w[i] == 1) tmp.push_back(i); //ÿ���ҵ�1  �Ͱ�1��Ӧ�������洢����
		}
		//cout << tmp.back() << " " << tmp.front() << " " << tmp.size() << endl;
		cout << tmp.back() - tmp.front() + 1 - tmp.size() << endl;

	}
	return 0;
}

