//思路：

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

// 没什么太好的办法， 只能使用暴力搜索。 
// 先用试除法 求出目标数的所有 约数
// 然后从大到小开始遍历   基于找遍历这个数的约数，然后考察所有约数中是否有能被a平方 整除的

typedef long long LL;
// 试除法求约数  固定模板
vector<LL> get_divisors(LL n)
{
    vector<LL> res;
    for (int i = 1; i <= n / i; i++)
        if (n % i == 0)
        {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i); // 两个数不能相同
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
        //从大到小开始遍历res
        for (int i = res.size() - 1; i >= 0; i--)
        {
            auto sub_res = get_divisors(res[i]);
            flag = true;
            for (auto key : sub_res)
            {
                if (key != 1)
                {
                    //遍历一下所有的约数 查看约数中是否有 平方项目
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
                //说明找到了   一个 res[i] 他的所有约数中不含平方项
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