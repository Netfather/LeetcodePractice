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

// ûʲô̫�õİ취�� ֻ��ʹ�ñ��������� 
// �����Գ��� ���Ŀ���������� Լ��
// Ȼ��Ӵ�С��ʼ����   �����ұ����������Լ����Ȼ�󿼲�����Լ�����Ƿ����ܱ�aƽ�� ������

typedef long long LL;
// �Գ�����Լ��  �̶�ģ��
vector<LL> get_divisors(LL n)
{
    vector<LL> res;
    for (int i = 1; i <= n / i; i++)
        if (n % i == 0)
        {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i); // ������������ͬ
        }
    sort(res.begin(), res.end());
    return res;
}


int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        LL n;
        cin >> n;
        auto res = get_divisors(n);
        bool flag = true;
        //�Ӵ�С��ʼ����res
        for (int i = res.size() - 1; i >= 0; i--)
        {
            auto sub_res = get_divisors(res[i]);
            flag = true;
            for (auto key : sub_res)
            {
                if (key != 1)
                {
                    //����һ�����е�Լ�� �鿴Լ�����Ƿ��� ƽ����Ŀ
                    LL tmp = LL(sqrt(key));
                    if (tmp * tmp == key)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag == true)
            {
                //˵���ҵ���   һ�� res[i] ��������Լ���в���ƽ����
                cout << res[i] << endl;
                break;
            }
        }
        if (flag == false)
        {
            cout << 1 << endl;
        }
    }
	return 0;
}