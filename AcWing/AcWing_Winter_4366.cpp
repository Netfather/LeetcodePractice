// ����۲�
// 1. ����ÿ��ʯ�Ӷ���ͬ ����������ֻ��֣���ô�ض�����������ֵ�� ͨ����֤������֤�����������ĳ����СֵΪ�����������
//    ��ô�����ֵ��������ǲ�����ͨ���ϲ������õ��ġ�
// 2. ���������ܻ���Ϊһ�ѣ�����Ҫ�ֳ����ɸ���ȵ�ֵ�����ֵ�ض����ڵ�����������ֵ�����ܱ��ܺ�����
// 3. ���ȷ��������λ�õ������ܹ�ͨ����ϵķ�ʽ�õ�������ֵ��

// 4. ����˵�� ����T��С ���Ա���ö�����д� Ԫ�����ֵ��N//2�����п��ܽ⣬Ȼ����O(N)���ӶȲ��ҽ�ĺ����Լ��ɡ�



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
            while (biggest <= int(sum / 2)) //����ö�����п��ܵķ���ֵ
            {
                int flag = 0;
                if (sum % biggest == 0) // ���ܵķ���ֵ�ض��ܹ�����sum
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
