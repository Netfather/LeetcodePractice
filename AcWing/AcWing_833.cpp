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


// ��������Ҫ�Լ���ͼ�����  ����ne����ĺ������ͼ��������
//

const int N = 100010;
int ne[N];
int main()
{
	string p = "?";
	string s = "?";
	int n;
	string a;
	cin >> n >> a;
	p = p + a;
	int m;
	string b;
	cin >> m >> b;
	s = s + b;

	// Ϊ�˷��㣬 �������е��ַ���ͳһ��1��ʼ����  ԭ������ ���ǻᾭ���ж�j+1 ����Ϊ�˱���Խ��  j���Դ�0��ʼ 
	// ��ʼ������ne������д���
	// ��i��ʼö�� ÿһ�δ�i�㿪ʼ��ǰ�������ַ��� �Ƿ�������ne�����
	//  ���ʵ�ڲ���� �ʹ�ϵ�һ��������
	// ��������±�Ķ��廹�Ƿǳ����м��ɵ�   
	for (int i = 2, j = 0; i <= n; i++)
	{
		while (j != 0 && p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) j++;
		ne[i] = j;
	}


	// �õ�ne����֮�����ǿ�ʼ��s�Ͻ���ƥ��
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j != 0 && s[i] != p[j + 1]) j = ne[j];  // ��jû�е�ͷ�������޷�ƥ���ʱ�� ���Ǿ�һֱ��תj
		if (s[i] == p[j + 1]) j++; //���������֮���������Ϊ�ɹ�ƥ��ų����ģ���ô���Ǿ�ֱ�ӽ�j++
		if (j == n)
		{
			 //˵��jƥ�䵽ͷ��
			cout << i - n << endl;
			j = ne[j]; // ͬʱ jҪ�ٴ���ת
		}
	}
	return 0;
}



//#include <iostream>
//
//using namespace std;
//
//const int N = 10010, M = 100010;
//
//int n, m;
//int ne[N];
//char s[M], p[N];
//
//int main()
//{
//    cin >> n >> p + 1 >> m >> s + 1;
//
//    for (int i = 2, j = 0; i <= n; i++)
//    {
//        while (j && p[i] != p[j + 1]) j = ne[j];
//        if (p[i] == p[j + 1]) j++;
//        ne[i] = j;
//    }
//
//    for (int i = 1, j = 0; i <= m; i++)
//    {
//        while (j && s[i] != p[j + 1]) j = ne[j];
//        if (s[i] == p[j + 1]) j++;
//        if (j == n)
//        {
//            printf("%d ", i - n);
//            j = ne[j];
//        }
//    }
//
//    return 0;
//}
