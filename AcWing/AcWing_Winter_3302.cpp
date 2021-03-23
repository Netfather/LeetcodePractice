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

//�������ʵ�ǹ�����׺��׺ǰ׺���ʽ�����֡�
//�������ֱ��һ����β���ڴ��������ͬ��������ʽ��ֵ�����ѵĻ� �����Ȱ���׺���ʽ����Ϊ��׺���ʽ
// Ȼ���׺���ʽ��ֵ  ���ں�׺���ʽ��ֵֻ��һ���ǳ��򵥵�ջ��Ӧ�ã����û���Ѷ�
//�����ѶȾ�������ΰ�һ�������ŵ���׺���ʽ ת��Ϊ �ܹ���ȷ����ĺ�׺���ʽ��

// ֻ��Ҫ��ѭ���µ�˼·��
// ����һ����׺���ʽ�����ǰ������²���Ϳ�����ȷת��
// �������б��ʽ�е����֣��ǲ���Ҫ���κδ���ģ��õ��Ϳ���ֱ��ѹ��������
// Ȼ����ʽ�е����ſ�ʼ��ͬ������Ҫ�κδ����õ�ѹ�� ������ջ  ע���������������ȫ��ͬ�������ṹ�� һ���ǽ�����У�һ�����ݴ���ʽ��ջ
//		���ʽ�е����Ž�����Ҳ����Ҫ�κδ���һ����������ֱ�ӵ���������ջ��ֱ����������ſ�ʼΪֹ
// Ȼ����� ���� + - * / �Ĵ���   ��������ֻ��Ҫ��ѭһ������ �������������ʱ�����ǾͿ���������ջ�Ķ����������
// ��֤��������������ȼ�һ���ȵ�ǰ�õ���������ͣ������Ҫһֱ��ջ��ֱ��ջΪ�� ����ջ��Ϊ���ſ�ʼ

// �������϶��� �Ϳ��Է�Ϊ + - �� �� * / �������ǡ�
// ���� + - �� ��������ͼ��Ĳ������ȼ�����������ջ�� + - ����Ҫ����ģ���������ջҲ�ȵ�ǰ �Ĳ������и������ȼ�
//				��ˣ����� + - �� ����ֱ�ӽ�������ջ������Ԫ�ص�����ֱ��ջΪ�� ����ջ��Ϊ ���ſ�ʼ
// ���� * / ������������߼��Ĳ��������ܱ�������ȼ��ߵ� ֻ��֮ǰ����� * / ����
//				��ˣ����� * / �� ���Ǽ��ջ��Ԫ�� ��� Ϊ * ���� / �͵����� ��Ȼ��Ҫ��֤ջ��Ϊ��
// ��˾Ϳ�����ȷ����������еĲ����� ʵ����׺ת��׺


queue<string> convert(string a)
{
	queue<string> LastPrefix;
	stack<string> Opera;

	for (int i = 0; i < a.length(); )
	{
		if (a[i] == '(')
		{
			Opera.push("(");
			i++;
		}
		else if (a[i] == ')')
		{
		// ֱ�ӵ������� ֱ����һ����¼�����ſ�ʼλ��
			while (Opera.top() != "(")
			{
				LastPrefix.push( Opera.top());
				Opera.pop();
			}
			Opera.pop(); // ����Ӧ������ŵ� �洢����
			i++;
		}
		else if (a[i] >= '0' && a[i] <= '9' )
		{
			// �������߶�ʮ�� ֱ����������
			int sum = 0;
			while (i < a.length() && a[i] >= '0' && a[i] <= '9')
			{
				sum = sum * 10 + a[i++] - '0';
			}	
			LastPrefix.push(to_string(sum));
		}
		else if (a[i] == '+' || a[i] == '-')
		{
			while (!Opera.empty() && Opera.top() != "(")  //����� + - �� ��ô����Ҫ��֤��ʱ��ջ�еĶ���洢������������ȼ�һ���� + - С //��ô��������������� ֻ�ж�ջΪ�� ����  ��ջ�������ſ�ʼ
			{
				LastPrefix.push(Opera.top());
				Opera.pop();
			}
			Opera.push(a.substr(i, 1));
			i++;
		}
		else    //�����ʱ�� * / �� ��ô����һ���������������Ǿ�ֱ�ӵ����ˣ���� * / ��ֻ��Ҫ����֮ǰѹ���  * /
		{
			while (!Opera.empty() && (Opera.top() == "*" || Opera.top() == "/"))  //����� + - �� ��ô����Ҫ��֤��ʱ��ջ�еĶ���洢������������ȼ�һ���� + - С //��ô��������������� ֻ�ж�ջΪ�� ����  ��ջ�������ſ�ʼ
			{
				LastPrefix.push(Opera.top());
				Opera.pop();
			}
			Opera.push(a.substr(i, 1));
			i++;
		}
	}
	while (!Opera.empty())  //���������� ����û������Ĳ����� �Ͱ���˳��һ����ջ
	{
		LastPrefix.push(Opera.top());
		Opera.pop();
	}
	return LastPrefix;

}



//�������Ҫ�Ȱ���׺��ʾ�ı��ʽת��Ϊǰ׺ Ȼ���ٶ�ǰ׺���ʽ��ֵ����
int main()
{
	string a;
	cin >> a;
	queue<string> lastpre = convert(a);
	stack<int> res;

	//����ת���õĺ�׺���ʽ ֱ����ֵ
	while (!lastpre.empty())
	{
		string key = lastpre.front();
		if (key == "+")
		{
			int a = res.top();
			res.pop();
			int b = res.top();
			res.pop();
			res.push(a + b);
		}
		else if (key == "-")
		{
			int a = res.top();
			res.pop();
			int b = res.top();
			res.pop();
			res.push(b - a);
		}
		else if (key == "*")
		{
			int a = res.top();
			res.pop();
			int b = res.top();
			res.pop();
			res.push(a * b);
		}
		else if (key == "/")
		{
			int a = res.top();
			res.pop();
			int b = res.top();
			res.pop();
			res.push(b / a);
		}
		else
		{
			res.push(stoi(key));
		}
		lastpre.pop();
	}
	cout << res.top() << endl;
	//while (!lastpre.empty())
	//{
	//	cout << lastpre.front();
	//	lastpre.pop();
	//}


	return 0;
}