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

// ֱ�ӱ��ѾͿ�����  ����Ϊ5000  TΪ100 ʱ�临�Ӷ�Ϊ10��5�η� ���Թ�
// �������� �������е������߼���
// ����˼·���� ���������п��Բ����� ��˶��������������е����������ֻ��Ҫ�ҵ�����������������������ּ���
// ����ż���������е���������ǿ��Է��� ����Ҳֻ��Ҫ�ҵ�����������������������ּ���
// �����������˻�Ϊ�� �����ܷ��ҵ� �����������������������
// �����п��Բ�����  ��������ѡ  ��ô������ڳ���Ϊ3�������� ֻ��Ҫ�������������������������
const int N = 5010;
int w[N];
int Loc[N]; //���ڴ洢ĳ������w�е�λ�����ĸ� ��1��ʼ����

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		memset(Loc, 0, sizeof Loc);
		bool is_valid = false;
		for (int i = 0; i < n; i++)
		{
			cin >> w[i];
			if (!Loc[w[i]]) Loc[w[i]] = i + 1; //���w[i]��λ��û�б���¼������ô�ͼ�¼һ��
			else if (Loc[w[i]] + 1 != i + 1) is_valid = true; //�������¼�� ��������λ�ò���������ô��֤���ҵ���
			// �������λ�����������ǾͲ���Ҫ�޸� ��Ϊ��֤Loc�����ܺ����ڵ�ָ��i�����ܵ�Զ  ��Խ�����ҵ�
		}
		if (is_valid) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}