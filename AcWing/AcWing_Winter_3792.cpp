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

// ������� 2��1000��Χ�ڵ���������  Ȼ�� ������Щ���� ����
const int N = 1010;
vector<int> ZhiShu; //��¼����
int Table[N]; //��¼ĳ�������Ƿ�Ϊ����


int main()
{
	//�ڽ������֮ǰ ��Ԥ����һ��  ��2��1000����������
	for(int i = 2; i <= 1000; i++)
	{
		bool is_ZhiShu = true;
		for (int j = 2; j <= int(sqrt(i)); j++) //�Գ���
		{
			if (i % j == 0)  //��������� ˵��i��������
			{
				is_ZhiShu = false;
				break;
			}
		}
		if (is_ZhiShu)
		{
			ZhiShu.push_back(i);
			Table[i] = 1; //������������ ͬʱTable��¼
		}
	}

	int T;
	cin >> T;
	while (T--)
	{
		int cnt = 0;
		int n, k;
		cin >> n >> k;
		//�������еĿ���
		for (int i = 0; i < ZhiShu.size() - 1; i++)
		{
			if (ZhiShu[i] > n) break; //�� ��������������ƴ�ʱ ֱ��break
			if (ZhiShu[i] + ZhiShu[i + 1] + 1 <= n && Table[ZhiShu[i] + ZhiShu[i + 1] + 1] == 1  ) cnt++; //��������д������
		}
		if (cnt >= k) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}