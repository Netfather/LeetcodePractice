/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;
string convert(string s, int numRows) {
	string result;
	int length = 0; //s�ĳ���
	int i, j = 0;
	length = s.length();
	if (length == 0) return s;
	else if (length == 1 || length == 2 || numRows == 1) return s;
	else
	{

		//��̬��ά��������
		int **p = new int*[numRows];
		for (int k = 0; k < numRows; k++)
		{
			p[k] = new int[length];
		}
		//��ʼ��Ϊ0
		for (i = 0; i < numRows; i++)
		{
			for (j = 0; j < length; j++)
			{
				p[i][j] = 0;
			}
		}
		//ͷ����ʼ����ͷ����Ψһ�Ķ��⡣
		p[0][0] = int(s.at(0));

		i = 1;
		j = 0;
		//���½���srting���͵ķ��� ��Ϊ�½����̺���������
		int times = 1; //�����½����� Ϊ����ʱ����ʾ�½���Ϊż����ʾ����
		int counts = 1;//С�����������ڱ�־�Ƿ���ɱ����½���������
		for (string::iterator ita = (s.begin()+1); ita != s.end(); ita++)
		{
			if (counts == numRows && times % 2 == 1)
			{
				times = times + 1;
				counts = 1;//�½�����+1 ͬʱcounts��1
				i = i - 1;//i��Ҫ����ά��һ��
			}
			if (counts == numRows && times % 2 == 0)
			{
				times = times + 1;
				counts = 1;//�½�����+1 ͬʱcounts��1
				i = i + 1;//i��Ҫ����ά��һ��
			}
			if (times % 2 == 1) //�½�����
			{
				counts++; //������ά��
				p[i][j] = (int)*ita; //��ֵ���һ��
				i = i + 1;//�±�ά��
				continue;
			}
			if (times % 2 == 0) //��������
			{
				j = j + 1;
				i = i - 1;//�±�ά��
				counts++; //������ά��
				p[i][j] = (int)*ita;
				continue;
			}
		}
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (p[i][j] != 0)
				{
					result = result + char(p[i][j]);
				}
			}
		}
		for (int k = 0; k < numRows; k++)
		{
			delete[] p[k];
		}
		delete[]p;
	}
	return result;
}

int main()
{
	string s = "ABC";
	string res;
	res = convert(s, 1);
	cout << res << endl;
	system("Pause");
	return 0;
}

//PAYPALISHIRING
*/