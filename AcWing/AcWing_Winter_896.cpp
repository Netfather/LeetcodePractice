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

//�µ�����������еķ����Ͳ���dp������ ����ά��һ��ջ
//���ջ�洢�������µĸ�ʽ  �������� ����������еĳ���   ��Ӧ��ֵ Ϊ ��ǰ�������������е����һ��Ԫ�ء�
// ���ִ洢��ʽ�����������ڶ���һ���µ�����֮��������ֱȵ�ǰջ��Ԫ�ش� ˵�����������еĳ��ȿ��Լ�1
// ����ȵ�ǰջ��Ԫ��С  ���Ǿ��ҵ��������滻����Ԫ�ص��½磬Ȼ���滻���ɡ�

//Ϊ�˿��ټ����½�  ����ʹ�ö��� ����ֱ��ʹ��vector�����洢
int main()
{
	int n;
	cin >> n;
	vector<int> w(n, 0);
	for (int i = 0; i < n; i++) cin >> w[i];

	//ά��һ����ջ
	vector<int> stk;
	// ����ÿ��Ԫ��
	stk.push_back(w[0]); //ѹ�����ʼ��״̬ ���㴦��
	for (int i = 1; i < n; i++)
	{
		//�����ǰ���ֱ�ĩβ���ִ� �Ǻܺ�ϲ+1
		if (w[i] > stk.back())
			stk.push_back(w[i]);
		else
			*lower_bound(stk.begin(), stk.end(), w[i]) = w[i]; //�����ĩβ����С����� ���Ǿ��Ҵ�ǰά����ջ��ӦԪ�ص���ȷλ�� ���޸�ֵ��
	}
	cout << stk.size() << endl;
	return 0;
}