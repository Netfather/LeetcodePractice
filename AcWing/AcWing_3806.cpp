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

// �����ɾ���κ��ַ�  �ǲ����ܵģ���Ϊ����һ������ͨ��ɾ�����һ���ַ� ʹ�����ַ������ֵ����� ���е�֮ǰ
// ��������˻�Ϊ  �Ƴ�ĳ�����ַ��� ʹ���ַ������ֵ����Ͼ�����С
// �����ת��Ϊ�������� ���ǿ���֪��  ���ֵ�����С  ��ӳ������ʵ���� �������ֵ�ֵ�����ܵ�С�� 
// ���� �� 1 2 3 4 5 ���ɵ�����  ���ǹ��ɵ���СֵΪ 12345 ���ֵΪ 54321
// ������������ֻ��Ҫ ö��һ�����еĿ���  �������������ŵ��Ǹ��⼴�ɡ�
// ��������˼·  �޷���0(1)ʱ�����  ɾ��ĳ���ַ������֮��  ʣ���ַ������Ľ��ƴ�С

// ��˽�һ���۲� ���ǿ��Է���
// �����һ�����ֱȵ�ǰ���ִ�  ��ô��Ȼ������ɾ����ǰ�������    ����  aba ����
// �����һ�����ֺ͵�ǰ������� ��ô��Ȼ������ɾ����ǰ�������   ���� aaab����
// �����һ�����ֱȵ�ǰ����С  ��ô��ɾ����������һ�����ּ���  
// Ϊʲôɾ����� ����Ϊ�ֵ�������ԣ�Խ������� ���������ֵ�����ռ�ݵ�Ȩ�ؾ�Խ�����


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		// Ԥ����ǰ׺��
		string res = s;
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i + 1] < s[i])
			{
				res = s.substr(0, i) + s.substr(i + 1);
				break;
			}
		}
		// �������ѭ�� res �ĳ���δ�����仯 ˵��ǰ���n-1�������Ѿ����ֵ����е���Сֵ�ˣ���ʱֻ��Ҫֱ��ɾ�����һ�����ּ���
		if (res.length() == s.length()) res = s.substr(0, n - 1);
		cout << res << endl;

	}
	return 0;
}