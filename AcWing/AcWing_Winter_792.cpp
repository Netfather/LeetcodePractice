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


vector<int> Minus(vector<int>& A, vector<int>& B)
{
    vector<int> C; //������

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
        C.push_back( (tmp + 10) % 10);  // Ϊ�˱���Ǹ���������������C��ʱ�����Ǳ�֤+ 10
        if (tmp < 0) t = 1;  // ���￪ʼ�������tmpС��0 ˵�������Ѿ����һλ����ô����t��Ҫ = 1
        else t = 0; // ����Ͳ��ô���
        i++;
    }
    // ���ڼ��������Ǳ�֤��Aһ����B����ô����ĳ��Ⱦ�һ�����ᳬ��A ��˲���Ҫ�����λ
    while (C.size() > 1 && C.back() == 0) C.pop_back();  // ����ǰ��0 Ȼ��������Ϳ��Եõ����յĽ��
    return C;
}


int main()
{
    string a, b;
    cin >> a >> b;
    // �������ߴ�С����֤AΪ���BΪ��С  
    // ���²���ֱ���б� ����Ƿ�Ϊ���� 
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
    // ���������ݷ���������
    vector<int> A(l_a,0);
    vector<int> B(l_b,0);
    vector<int> C;
    for (int i = a.size() - 1; i >= 0; i--) A[i] = (a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B[i] = (b[i] - '0');
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    // ���ݽ���Ƿ�Ϊ������ָ�� A B�ֱ���˭
  
    if ( Negtive) C = Minus(B, A);
    else C = Minus(A, B);
    if (Negtive) cout << "-";
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];
   
	return 0;
}

