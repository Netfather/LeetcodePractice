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

// ���ǿ��������һ������ ��֪����ι����� ��������Ҫ����һ�� 10���ȵ��ַ���
// �ٶ� ��һ�ڶ�λ�Ѿ�ȷ����  ab ��ôΪ�˱�����ֳ���Ϊ3�Ļ��� ����ֻ�����¹���
//  abbaabbaabb ����
// �����һ�ڶ�Ϊ�� bb ���� aa ��ôֱ���ظ�����
// ��˹��췽ʽ�ͺ���ȷ��


//���췽ʽ��ȷ ���ǳ�ʱ�ˣ�  �Ǿ�ֱ������ͺ��� ���������λ�������Ƶ�ǰ����ĸ�����
int main()
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		if (((i + 1) / 2) % 2 != 0) cout << "a";
		else cout << "b";
 	}
	return 0;
}