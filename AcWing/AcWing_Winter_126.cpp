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

//һά��������ǿ���ͨ����֤����֤�����������ĵ�ǰ�����ʹ�Ӻͼ�С����ô�����¿�ʼ��¼
//int res = INT_MIN;
//const int N = 110;
//int w[N];
//void One_dim(int n )
//{
//	int tmpres = w[1];
//	for (int i = 2; i <= n; i++)
//	{
//		if (tmpres + w[i] < tmpres)
//		{
//			//Ҫ���浱ǰ��tmpres Ȼ��tmpres���
//			res = max(res,tmpres);
//			tmpres = w[i];
//			continue;
//		}
//		tmpres += w[i];
//	}
//}

const int N = 110;
int s[N][N]; //���ڴ��ǰ׺������
int res;
int main()
{
	//�����ȿ���һά�����������1ά��ʱ��������λ������һ�����������������
	// ��ɿ���һά���֮�����������Ƕ�ά
	// ����ֻ��Ҫ���Ƕ�ά�����ϵ�ǰ׺�����飬Ȼ��ֱ�ӵ���1ά����ö�ټ���
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int tmp;
			cin >> tmp;
			s[i][j] = s[i-1][j] + tmp;
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				int input = s[j][k] - s[i][k];
				int tmpres = 0;
				if (k == 1) tmpres = input;
				else
				{
					if (tmpres + input < tmpres)
					{
						res = max(res, tmpres);
						tmpres = input;
						continue;
					}
					tmpres += input;
				}
			}
		}
	}
	cout << res;



	return 0;
}