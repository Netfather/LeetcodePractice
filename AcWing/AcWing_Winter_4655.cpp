//˼·��
// ��������˼·�������¹���ݽ�
// ���ڸ�����һ���ѯ L R  �ڲ�ѯ������Ϻ�һ�����Եõ�һ������ ���еĸ���Ϊ w[i] �� ����LR �����Ĵ���
// �� ���ݴ����Ķ��٣�����һ���ܹ���������Ӵ�С��˳�� ʹ�� ��ѯ������ܺ����
// �� ����һ�����Ա�֤ ����µİ��հ�������˳������� ��һ�����Ի�õ�

// ���ԭ�����˻�Ϊһ�� һά������⣬ �� ÿһ�β�ѯ����ζ�Ÿ�һ�� ԭʼȫ0������ L��R������+1
// Ȼ��ԭ����Ӵ�С���� �������� Ԫ����˲���� ��Ϊ����ѯ����ĺ͡�

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
typedef long long LL;
const int N = 100010;
int w[N];
LL b[N];  //�������
LL s[N];  // ǰ׺����
long long res_1, res_2 = 0;

void InsertB(int l, int r)
{
    b[l] = b[l] + 1;
    b[r + 1] = b[r + 1] - 1;
}

int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        s[i] = s[i - 1] + w[i];
    }
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        res_1 += (s[r] - s[l - 1]);
        InsertB(l, r);
    }
    // ���ݲ������ ��ԭ��ÿ���Ĵ���
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + b[i]; // ע�������ǽ���ԭ�����鸳ֵ��b�Խ�Լ�ռ�
    sort(w + 1, w + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) res_2 += LL(w[i] * b[i]);
    cout << res_2 - res_1 << endl;

    return 0;
}