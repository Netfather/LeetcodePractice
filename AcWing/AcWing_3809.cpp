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

//����ѡַ����ĸ��Ѷȱ��� �ڻ���ѡַ��  ��ʵ��������  ai - t�ľ���ֵ <= 0 �����ڱ����1
// ����ζ�� �����м�ĵ�ַ ��ʵ�и��ߵ�ԣ��  ��Ҳ����ζ��  ������Ҫ������λ��ǰ�� һ��������ͬ������ �۲�����ʹ�ô�����С����ϼ���
const int N = 1010;
int w[N];


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> w[i];
		if (n == 1)
		{
			cout << w[0] << " " << 0 << endl;
			continue;
		}

		sort(w, w + n);
		int t = 0;
		int res = INT_MAX;

		int bind = w[n / 2] - 1;
		for (; bind <= w[n / 2] + 1; bind++)
		{
			int tempres = 0;
			for (int i = 0; i < n; i++)
			{
				if (w[i] < bind) tempres += (bind - w[i] - 1);
				else if (w[i] > bind) tempres += (w[i] - bind - 1);
			}
			if (tempres < res)
			{
				t = bind;
				res = tempres;
			}
		}
		cout << t << " " << res << endl;
	}


	return 0;
}