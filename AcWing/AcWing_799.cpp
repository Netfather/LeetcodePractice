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



//˫ָ������  
//const int N = 100010;
//int w[N];
//int Table[100000]; //���ڼ�¼ ÿ�����ֵ����� ��w�е��±�������ַ
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> w[i];
//	int res = INT_MIN;
//	// ˫ָ�� ά��һ������
//	int l = 1, r = 1;
//	while (r != n + 1)
//	{
//		// ÿ��rǰ��һλ�� �����������ݲ�������Table�� ��ô�ͼ�������
//		// �����Ӧ�������Ѿ����� ��ô
//		if (Table[w[r]] != 0)
//		{
//			res = max(res, r - 1 - l + 1);
//			// �޸�l���µ�����  ע������Ҫ�޸ĵĻ���Ҫ�ѵ�Ŀ��λ��֮ǰ���м�¼��Table�е��������
//			while (l < Table[w[r]] + 1) Table[w[l++]] = 0;
//		}
//		Table[w[r]] = r;
//		r++;
//	}
//	res = max(res, r - 1 - l + 1);
//	cout << res << endl;
//	return 0;
//}


//ע �˷��ͱ�׼�𰸽ⷨ�ǲ�����˼��ͬ������Table��¼���ڵĴ��������Ǹ��Ӽ���һЩ
const int N = 100010;
int w[N];
int Table[N]; //�洢֮ǰ����Ԫ�س��ֵĸ���

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}

	//˫ָ�룬 ��ָ�벻����ǰ̽����ָ��ά���ܹ�ά����ָ������ظ����±�����
	int l = 1, r = 1;
	int res = INT_MIN;
	while (r < n + 1)
	{
		// ÿ����һ���� ���Ǿ�ֱ�Ӷ�Table++
		++Table[w[r]];
		// �ж���ʱ��Table�Ĵ�����û�д���2
		while (Table[w[r]] > 1) --Table[w[l++]]; //һ��ȷ���д���2�Ĵ��ڣ���˵㿪ʼ�ж���һ·�ң�ֱ���ҵ�ʹ��Table > 1���������
		res = max(res, r - l + 1 );
	}
	res = max(res, r - l );
	cout << res << endl;
	return 0;
}