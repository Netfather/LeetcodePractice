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

//˼·��ʹ��ǰ׺��˼�룬�������ת��Ϊ �ʸ���һ�����飬����
//�ж��ٸ���ԣ�ʹ���������ΪK�ı���
// ��ô��һ������ת��Ϊ������һ�����飬ʹ���������������K��ͬ���������ĵ���м���
// ����Ϳ���ʹ�ù�ϣ��ÿ����һ���㣬���ǾͰѵ�ǰ������������ϣ����
// ������������ֱ�Ӳ��Ĺ�ϣ����֪���������֮ǰ�ж��ٸ����뵱ǰ����ͬ�����������ж��ٸ��������ж��ٸ����
// ��˵ý�
const int N = 100010;

long long int s[N];
int Hash[N];
long long int res = 0;
int main()
{
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] += s[i - 1];
	}

	//�����ϣ��
	Hash[0] ++;
	for (int i = 1; i <= n; i++)
	{
		res += Hash[s[i] % k];
		++Hash[s[i] % k];
	}

	cout << res;
	return 0;
}