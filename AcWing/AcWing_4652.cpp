//思路：
// 最简单的办法直接查表  
// 但是这里想锻炼一下递归的思路 这道题可以递归的求解
// 定义一个pair   分别为两个边长  同时维护好  first 一定为长边 second 一定为短边

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

typedef pair<int, int> PII;
PII res = make_pair(1189, 841);

PII PaperSize(int layer)
{
    if (layer <= 0) return res; // 递归终止
    PII tmp_res = PaperSize(layer - 1);
    tmp_res.first = tmp_res.first / 2;
    tmp_res.second = tmp_res.second;
    if (tmp_res.second > tmp_res.first) swap(tmp_res.second, tmp_res.first);
    return tmp_res;
}

int main()
{
    string s;
    cin >> s;
    int layer = s[1] - '0';
    PII out = PaperSize(layer);
    cout << out.first << endl;
    cout << out.second << endl;
    return 0;
}