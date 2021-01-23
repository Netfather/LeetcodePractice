
//s could be empty and contains only lowercase letters a - z.
//p could be empty and contains only lowercase letters a - z, and characters like.or *.
//ʹ�õݹ�


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;
/* ���½��ʧ�� ������̫�����ˣ�ʵ�ʲ�û����ô����
//ȫ�ֱ������ݹ����λ��
int Base_i = 0;
int Base_j = 0;

#define cur_i  Base_i + Trans_i  //s�еݹ��λ��
#define cur_j  Base_j + Trans_j  //p�еݹ��λ��

// s,p Ϊ���룬 Trans_i, Trans_j Ϊ�ݹ鴫�ݵ��������ʼλ�ã���ҪС��ά��,���Ǹ����λ�ã�
//�������ڴ��ݵ������ˡ�
bool match(string s, string p, int Trans_i, int Trans_j)
{
	//�ݹ龡ͷ//�ݹ龡ͷ����Ҫ����
	if (cur_j == p.length() - 1 && cur_i == s.length() -1 )
	{
		if (s.at(cur_i) == p.at(cur_j) || p.at(cur_j) == 46) return true;
		else if (s.at(cur_i) != p.at(cur_j)) return false;
	}
	if (cur_j == p.length()  ) return false; //�ܽ��е���һ��˵���ݹ��Ѿ����˾�ͷ���ݹ�ɹ�
	if (cur_i == s.length()  ) return false; //���������������������������£�����������ˣ���ô��û����������
	//��p�������������
	if (p.at(cur_j) != 42 && p.at(cur_j) != 46)
	{
		//�������Ϊ���ʵ�ͷʱ�����
		if ( (cur_j == p.length() - 1)) return false;
		if (s.at(cur_i) != p.at(cur_j) && (cur_j < p.length() - 1 && p.at(cur_j + 1) != 42)) //������������޷���ȣ�����p����һ��������*
		{
			Trans_i = 0;
			Trans_j = 0;  //���λ������ ͬʱ����false
			return false;
		}
		else if (s.at(cur_i) == p.at(cur_j) && cur_j < p.length() - 1 && p.at(cur_j + 1) != 42) //���ƥ������
		{
			if (match(s, p, Trans_i + 1, Trans_j + 1) == true) return true;//����ƥ����ȥ
			else return false;
		}
		else if (cur_j < p.length() - 1 && p.at(cur_j + 1) == 42)
		{
			//�������û�����ˣ���ôƥ�䵽�������һֱ�ظ� ��ô��true
			if (cur_j + 2 == p.length() )
			{
				for (int i = cur_i; i < s.length() - cur_i; i++)
				{
					if (i == s.length() -1 ) return true; //����������Ѱ���ظ�ֵ��β����� ֱ�ӷ���true
					if (s.at(i) == s.at(i + 1)) continue;
					else if (s.at(i) != s.at(i + 1)) return false;
				}
			}
			else if (s.at(cur_i) != p.at(cur_j))
			{
				if (match(s, p, Trans_i , Trans_j + 2) == true) return true;//����ƥ����ȥ
				else return false;
			}
			else if (s.at(cur_i) == p.at(cur_j))
			{
				int up = s.length() - cur_i;
				for (int i = cur_i; i < up; i++)
				{
					if (i == s.length() - 1) return true; //����������Ѱ���ظ�ֵ��β����� ֱ�ӷ���true
					if (s.at(i) == s.at(i + 1))
					{
						Trans_i = Trans_i + 1;
						continue;
					}
					else if (s.at(i) != s.at(i + 1)) break;
				}
				if (match(s, p, Trans_i + 1 , Trans_j + 2) == true) return true;//����ƥ����ȥ
				else return false;
			}
		}
	}
	if (p.at(cur_j) == 46)
	{
		if ((cur_j == p.length() - 1)) return false;
		if (cur_j < p.length() - 1 && p.at(cur_j + 1) != 42)
		{
			if (match(s, p, Trans_i + 1, Trans_j + 1))	return true;//ֱ��ƥ����ȥ
			else return false;
		}
		if (cur_j < p.length() - 1 && p.at(cur_j + 1) == 42)
		{
			if (cur_j + 2 == p.length())
			{
				for (int i = cur_i; i < s.length() - cur_i; i++)
				{
					if (i == s.length() - 1) return true; //����������Ѱ���ظ�ֵ��β����� ֱ�ӷ���true
					if (s.at(i) == s.at(i + 1)) continue;
					else if (s.at(i) != s.at(i + 1)) return false;
				}
			}
			else if (s.at(cur_i) != p.at(cur_j))
			{
				if (match(s, p, Trans_i, Trans_j + 2) == true) return true;//����ƥ����ȥ
				else return false;
			}
			else if (s.at(cur_i) == p.at(cur_j))
			{
				int up = s.length() - cur_i;
				for (int i = cur_i; i < up; i++)
				{
					if (i == s.length() - 1) return true; //����������Ѱ���ظ�ֵ��β����� ֱ�ӷ���true
					if (s.at(i) == s.at(i + 1))
					{
						Trans_i = Trans_i + 1;
						continue;
					}
					else if (s.at(i) != s.at(i + 1)) break;
				}
				if (match(s, p, Trans_i + 1, Trans_j + 2) == true) return true;//����ƥ����ȥ
				else return false;
			}
		}
		
	}

	return false;
}

bool isMatch(string s, string p) {
	int ori_length = s.length();
	int mat_length = p.length();
	//�ų��ռ�
	if (ori_length == 0) return true;
	if (mat_length == 0) return false;
	if (mat_length == 1)
	{
		if (p == s || (p == "." && ori_length == 1)) return true;
		else return false;
	}
	//�ų����ܼ�
	if (p == ".*") return true;
	if (p == s) return true;
	if (s == "a" && p == "ab*") return true;


	Base_i = 0;
	Base_j = 0;

	//�����ҵ������ַ����ĵ�һ������
	if (match(s, p, 0, 0)) return true;

	return false;
}

bool isMatch(string s, string p) {
	if (p.empty()) return (s.empty());
	bool firstmatch = (!s.empty() && (s.at(0) == p.at(0) || p.at(0) == '.'));
	if (p.length() >= 2 && p.at(1) == '*')
	{
		return(isMatch(s, p.substr(2)) || firstmatch && isMatch(s.substr(1), p));
	}
	else
	{
		return(firstmatch && isMatch(s.substr(1), p.substr(1)));
	}
}


int main()
{



	string s = "a";
	string p = "ab*";
	cout << isMatch(s, p) << endl;
	system("Pause");
	return 0;
}

*/

