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

//1. ����һ��mex��ʲô��˼�� ����һ�����ϣ���0��1��2һֱ������󣬵�һ��û�е����� ����������ϵ�mexֵ
//2. ���ǵ��Ӽ������ԣ��������Ҫ mexA+mexB�����ܴ���ô����ζ�ţ�������ϵĵ�һ���������ݵ����֣��ض����ǽ���еĵ�һ��
//3. ��Ϊ�κ�һ������Ҫô��A Ҫô��B������������ݣ���ζ��������ֱض�����һ�������жϵ���
//4. Ȼ���ٿ���Ӹõ�֮�󣬵�һ���ϵ�����ּ���

//5. �������Ϲ۲죬ֱ��ͳ��һ�����ֳ���Ƶ�ʱ���ǳ���
const int N = 110;
int w[N];
int Table[N]; //ͳ��ĳ�������Ƿ���ֹ�


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(w, 0, sizeof w);
		memset(Table, 0, sizeof Table);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> w[i];
			++Table[w[i]];
		}
		int res = 0;
		int flag = 0;
		for (int i = 0; i <= 100; i++)
		{
			//1.�ҵ���һ������С��2�ĵ�
			if (flag == 0 && Table[i] < 2) res += i,flag = 1;
			//2.�ҵ�����֮��ĵ�һ���ϵ� Ҳ�����Ҳ����ĵ�
			if (flag == 1 && Table[i] == 0)
			{
				res += i;
				break;
			}
		}
		cout << res << endl;
	}
	return 0;
}