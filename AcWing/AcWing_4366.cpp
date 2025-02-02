// 几点观察
// 1. 首先每堆石子都相同 如果存在这种划分，那么必定是数组的最大值， 通过反证法可以证明，如果存在某个较小值为这个划分数字
//    那么比这个值大的数字是不可能通过合并操作得到的。
// 2. 如果结果不能划分为一堆，而是要分成若干个相等的值，这个值必定大于等于数组的最大值，且能被总和整除
// 3. 如何确定，其他位置的数字能够通过组合的方式得到这个最大值。

// 4. 补充说明 由于T很小 所以暴力枚举所有从 元素最大值到N//2的所有可能解，然后以O(N)复杂度查找解的合理性即可。



#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010;
int w[N];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int total_res = 9999999;
        int biggest = -1;
        int sum = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
            sum += w[i];
            if (w[i] > biggest) biggest = w[i];
        }
        if (biggest == 0) cout << 0 << endl;
        else
        {
            while (biggest <= int(sum / 2)) //暴力枚举所有可能的分类值
            {
                int flag = 0;
                if (sum % biggest == 0) // 可能的分类值必定能够整除sum
                {
                    int res = 0;
                    int p_start = 0;
                    int tmp_sum = 0;
                    int tmp_cnt = 0;
                    for (; p_start <= n;)
                    {
                        // cout << tmp_sum << "xx ";
                        if (tmp_sum < biggest)
                        {
                            tmp_cnt++;
                            tmp_sum += w[p_start++];
                        }
                        else if (tmp_sum > biggest)
                        {
                            flag = 1;
                            break;
                        }
                        else
                        {
                            // cout << tmp_cnt << "xx";
                            tmp_sum = 0;
                            res += tmp_cnt - 1;
                            tmp_cnt = 0;
                        }
                    }
                    if (flag != 1) total_res = min(total_res, res);
                }
                biggest++;
            }
            cout << min(n - 1, total_res) << endl;
        }
    }


    return 0;
}
