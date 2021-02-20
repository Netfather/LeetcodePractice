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


const int N = 1010;
int Height[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> Height[i];
	}
	int res = INT_MAX;
	//�҂�����ͨ����֤��֤�������յ����н���ض����ڡ�0��100�����䡿
	//Ȼ���ϸ�����ǿ������������ߺ���Ͳ�����17
	//���ǿ���ȷ�����п��ܴ��������ڡ�0��17�� �� ��83��100��֮��
	for (int i = 0; i <= 83; i++)
	{
		//��ÿ�������ڣ����ǿ��Զ϶����е����䣬
		//����߶ȱ�������������ڣ���ô���øı�
		//����߶Ȳ�����������ڣ���ôֱ���ƶ�������ı߽磬��Ϊ����
		int left_bound = i;
		int right_bound = i + 17;
		int tmp = 0;
		for (int j = 0; j < n; j++)
		{
			if (Height[j] < left_bound) tmp += (Height[j] - left_bound) * (Height[j] - left_bound);
			else if (Height[j] > right_bound) tmp += (Height[j] - right_bound) * (Height[j] - right_bound);
		}
		//ö����һ���������䣬���ǱȽ�һ����ֵ
		res = min(res, tmp);
	}

	cout << res << endl;
	return 0;
}