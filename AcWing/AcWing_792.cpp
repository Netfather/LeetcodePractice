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


vector<int> Minus(vector<int>& A, vector<int>& B)
{
    vector<int> C; //定义结果

    int t = 0;
    int i = 0;
    int tmp = 0;

    while (i < A.size())
    {
        if (i < B.size())
        {
            tmp = A[i] - t - B[i];
        }
        else tmp = A[i] - t;
        C.push_back( (tmp + 10) % 10);  // 为了避免非负数，这里在填入C的时候，我们保证+ 10
        if (tmp < 0) t = 1;  // 这里开始处理，如果tmp小于0 说明我们已经借过一位，那么这里t就要 = 1
        else t = 0; // 否则就不用处理
        i++;
    }
    // 由于减法，我们保证了A一定比B大，那么结果的长度就一定不会超过A 因此不需要处理进位
    while (C.size() > 1 && C.back() == 0) C.pop_back();  // 弹出前导0 然后倒着输出就可以得到最终的结果
    return C;
}


int main()
{
    string a, b;
    cin >> a >> b;
    // 交换二者大小，保证A为最大，B为最小  
    // 如下部分直接判别 输出是否为负数 
    int l_a = a.length();
    int l_b = b.length();
    bool Negtive = false;
    if (l_a < l_b) Negtive = true;
    if (l_a == l_b)
    {
        for (int i = 0; i  < l_a ; i++)
        {
            if (a[i] > b[i]) break;
            else if (a[i] < b[i])
            {
                Negtive = true;
                break;
            }
        }
    }
    // 将两个数据放入数组中
    vector<int> A(l_a,0);
    vector<int> B(l_b,0);
    vector<int> C;
    for (int i = a.size() - 1; i >= 0; i--) A[i] = (a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B[i] = (b[i] - '0');
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    // 根据结果是否为负数来指定 A B分别是谁
  
    if ( Negtive) C = Minus(B, A);
    else C = Minus(A, B);
    if (Negtive) cout << "-";
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
   
	return 0;
}

