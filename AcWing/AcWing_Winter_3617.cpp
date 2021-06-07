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

//��Ȼ���ɵľ���c ���� ����ȫ�� ����a�е����־����ģ� ���a����һ������Ϊ0����ô��ӳ����Ӧ���� �ض�ȫ��0
// ͬ�� ����ȫ�� ����b�е����־��������b����һ������Ϊ0����ô��ӳ����Ӧ���� �ض�ȫ��0
// ����Ŀ��Ҫ�����ҵ����Ϊk ��ֻ����1���Ӿ��� 
// ���������������ǿ��Ժܿ��жϳ���Щ�����ж���һ��k,дһ����������������߳��������������ĸ���
// Ԥ����һ��k �õ�k�ĸ�����ʽ����һ��������,Ȼ���������Ĵ�С����������ö�Ӧ�ĸ���

// ˼·��ȷ �ɹ�AC

typedef unsigned long long ULL;
const int N = 40010;
vector<int> A;  //��¼a�г��ֵ�����1�ĸ��������߳��洢a��
vector<int> B;  // ��¼b�г��ֵ�����1�ĸ���������ɴ洢b��
vector<int> inshu;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	A.push_back(0);
	B.push_back(0);
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x == 1) ++tmp;
		else
		{
			if (tmp) A.push_back(tmp);
			tmp = 0;
		}
	}
	if (tmp) A.push_back(tmp);
	tmp = 0;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		if (x == 1) ++tmp;
		else
		{
			if (tmp) B.push_back(tmp);
			tmp = 0;
		}
	}
	if (tmp) B.push_back(tmp);
	//����ȥ�� ���ǿ���sortһ��
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	//Ԥ����k ȡ����������

	for (int i = 1; i < sqrt(k); i++)
	{
		if (k % i == 0) inshu.push_back(i);
	}
	//����A,B�����еĿ��� ��ʱ�����ݱ�Ϊ  ��A[i] �� B[j] ��ɵ������ڣ����Ի��ֳ����ٸ�k��С���Ӿ���
	// Step1�� ��������kС ��ôֱ��continue
	// Step2�� �������ǡ�õ���k ��ôres+=1
	// Step3�� ��������k����ô����k�������ֽ�������ȷ���߳������������ǰ����  ����ɵľ������ = �߳� - ���� + 1
	// �������һ�£���Ϊ������Ա������ţ���ô��ɵ�k��һ�����δ�С���Ͳ���Ҫ2���ж���
	ULL res = 0;
	ULL res_tmp = 0;
	// �ݴ�i j��ǰһ��Ԫ�� ���п��ټ���
	for (int i = 1; i < A.size(); i ++)
	{
		for (int j = 1; j < B.size(); j++)
		{
			//�ж�һ�� ��ǰ�����ܷ�װ��k����
			if (A[i] * B[j] < k) continue;
			else if (A[i] * B[j] == k) res += 1;
			else
			{
				// ��� ��εľ��κ��ϴεľ���ǡ����ͬ�����Ǿ�ֱ�ӽ����κ��ϴεĽ����¼��һ��
				// ��Ȼ����ط��ǿ����Ż��ģ�����ά��һ����񣬱��keyΪ�����߳���valueΪ ���������ܳ��k��С�Ӿ���ĸ���
				if (A[i] == A[i - 1] && B[j] == B[j - 1])
				{
					res += res_tmp;
					continue;
				}

				res_tmp = 0;
				for (auto u : inshu)
				{
					if (A[i] >= u && B[j] >= k / u)
					{
						res_tmp += (A[i] - u + 1) * (B[j] - k / u + 1);
					}
					if (A[i] >= k / u && B[j] >= u)
					{
						res_tmp += (A[i] - k / u + 1) * (B[j] - u + 1);
					}
				}
				//����һ�� ����
				int x = int(sqrt(k));
				if (x * x == k)
				{
					if (A[i] >= x && B[j] >= x)
					{
						res_tmp += (A[i] - x + 1) * (B[j] - x + 1);
					}
				}
				res += res_tmp;
			}
		}
	}
	cout << res << endl;
	return 0;
}