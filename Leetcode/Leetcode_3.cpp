

/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;

//�ж�Array�������Ƿ���ں�Ŀ����һ���Ķ����������һ���ķ�����������������е�ָ�� ���ȫ����һ������0
int CheckRepeat(int *Array, int length, int target)
{
	int j = 0;
	for (int i = length-1; i >= 0; i--)
	{
		j++;
		if (Array[i] != target) continue;
		if (Array[i] == target) return j-1 ;
	}
	return -1;
}


int lengthOfLongestSubstring(string s) {
	if (s.begin() == s.end())
	{
		return 0;
	}
	int result = 0;
	int lenbup1 = 1;
	int lenbup2 = 0;
	int flag = 0; //��־λ��������Ҫ��ÿ��ѭ������Ҫ����ά����0��ʾĿǰ���ڶ�bup1��ֵ��1��ʾ���ڶ�bup2��ֵ
	string::const_iterator it = s.begin();  //����Ҫ����ά��
	int length = s.length();
	int *bup1 = new int[length];
	int *bup2 = new int[length];
	//��ʼ����ά��bup1
	bup1[0] = *it;
	//��ʼ����ɺ�it����1
	if (it == s.end()) return 1; //����ֻ��һ�����ֵ��������
	for (int i = 0; i < length-1; i++)
	{
		it++;
		int Index1 = CheckRepeat(bup1, lenbup1, *it);
		int Index2 = CheckRepeat(bup2, lenbup2, *it);
		//����ά��bup1����
		//һ��Ҫ����Ѱ��
		if ( Index1 == -1 && (flag == 0))
		{
			flag = 0; //flag ά�� ά�ֶ���������ĸ�ֵ
			bup1[lenbup1] = *it; //��ֵ
			lenbup1++; //����ά��
		}
	    else if (Index1 != -1 && (flag == 0))
		{

			if (lenbup1 < lenbup2)
			{
				for (int i = 0; i < lenbup1; i++) bup1[i] = 0;
				lenbup1 = 1; //����ά��  
				flag = 0; //flagά��
				for (int i = 0; i < Index1; i++)
				{
					it--;
				}
				i = i - Index1;
				bup1[0] = *it;
			}
			else if (lenbup1 >= lenbup2)
			{
				for (int i = 0; i < lenbup2; i++) bup2[i] = 0;
				lenbup2 = 1; //����ά��
				flag = 1; //flagά��
				for (int i = 0; i < Index1; i++)
				{
					it--;
				}
				i = i - Index1;
				bup2[0] = *it;
			}
		}
		else if ((Index2 == -1) && (flag == 1))
		{
			flag = 1; //flag ά�� ά�ֶ���������ĸ�ֵ
			bup2[lenbup2] = *it; //��ֵ
			lenbup2++; //����ά��
		}
		//һ������������� ��Ҫת��
		else if ((Index2 != -1) && (flag == 1))
		{
			//��bup1����ɾ�����¹���
			if (lenbup1 < lenbup2)
			{
				for (int i = 0; i < lenbup1; i++) bup1[i] = 0;
				lenbup1 = 1; //����ά��  
				flag = 0; //flagά��
				for (int i = 0; i < Index2; i++)
				{
					it--;
				}
				i = i - Index2;
				bup1[0] = *it;
			}
			else if (lenbup1 >= lenbup2)
			{
				for (int i = 0; i < lenbup2; i++) bup2[i] = 0;
				lenbup2 = 1; //����ά��
				flag = 1; //flagά��
				for (int i = 0; i < Index2; i++)
				{
					it--;
				}
				i = i - Index2;
				bup2[0] = *it;
			}			
		}
	}
	if (lenbup1 > lenbup2) return lenbup1;
	else return lenbup2;
	
}


int main()
{
	string a = "aabaab!bb";
	int num = lengthOfLongestSubstring(a);
	system("Pause");
	return 0;
}
*/