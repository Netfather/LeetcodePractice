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

// �۲췭�Ʋ��������� ���ǿ����ܽ��һ�¹���
// ����ĵ�������  ���Ʋ���һ�����Խ��ַ�����Ϊ ǰȫΪB  ����ȫΪW�����
// ������Կ���ͨ����֤��֤�� �����ȫΪB��ǰ��  ��һ��������W  ��ô���ǿ���ͨ�����ƽ� BWB ��Ϊ  BBW ������ʵ����һ��W�ĺ���

// ��� ���ǿ���ֱ���ڶ���һ������֮�� �����жϳ� ���ַ����Ƿ��н�  ���ĳ�ֱ�Ҫ�������� B������Ϊż������W������Ϊż����
// ���������ǲ�����
// һ�������ܹ��ж���������Ƿ��н� �Լ� �����޸��ĸ����Ǿ���ֱ��ʹ�õ�������ʵ�������
// ���ƹ�������  ����һ��s һ����ǰָ��� ��ɫ����Ҫ�ı����ɫ ֱ�Ӹı� ͬʱ������������ ����Operation ���鼴��
//

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

		int cnt_B = 0; //ͳ��B�����˼���
		int cnt_W = 0; //ͳ��W�����˼���
		bool Change_B = false; //true��ʾ ��Sͨ���޸�BΪW 
		bool Change_W = false; //true��ʾ ��sͨ���޸� W ���ս����ȫB��
		vector<int> Operation; //��¼�޸ĵ������
		
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'B') cnt_B++;
			else cnt_W++;
		}
		
		//������ִ�W ���� ��B�����
		if (cnt_B == n || cnt_W == n)
		{
			cout << 0 << endl;
			continue;
		}

		if ((cnt_B % 2 == 0) && (cnt_W % 2 == 1)) Change_B = true;   // B������Ϊż���� ˵��Ҫ��B
		else if ((cnt_B % 2 == 1) && (cnt_W % 2 == 0)) Change_W = true; // W������Ϊż���� ˵��Ҫ��W
		else if ((cnt_B % 2 == 0) && (cnt_W % 2 == 0)) //�����Ϊż���� ���Ǿ�ȡ������С���Ǹ������޸�
		{
			if (cnt_B < cnt_W) Change_B = true;
			else Change_W = true;
		}

		if (!Change_B && !Change_W) cout << -1 << endl;  //�����Ϊ���� ��ôֱ�ӷ��� -1 ˵���޽�
		else {
			for (int i = 0; i < n - 1; i++)
			{
				if (Change_B && s[i] == 'B')
				{
					Operation.push_back(i + 1);
					s[i] = 'W';
					if (s[i + 1] == 'B') s[i + 1] = 'W';
					else if (s[i + 1] == 'W') s[i + 1] = 'B';
				}
				if (Change_W && s[i] == 'W')
				{
					Operation.push_back(i + 1);
					s[i] = 'B';
					if (s[i + 1] == 'B') s[i + 1] = 'W';
					else if (s[i + 1] == 'W') s[i + 1] = 'B';
				}
			}
			cout << Operation.size() << endl;
			if (Operation.size())
			{
				for (auto key : Operation) cout << key << " ";
				cout << endl;
			}
		}

		//����һ�±�־���ݴ�
		Operation.clear();
	}
	return 0;
}