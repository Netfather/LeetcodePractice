

/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;

//判断Array数组中是否存在和目标数一样的东西，如果有一样的返回这个数字在数组中的指引 如果全都不一样返回0
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
	int flag = 0; //标志位，极其重要，每次循环必须要进行维护，0表示目前正在对bup1赋值，1表示正在对bup2赋值
	string::const_iterator it = s.begin();  //必须要认真维护
	int length = s.length();
	int *bup1 = new int[length];
	int *bup2 = new int[length];
	//初始化并维护bup1
	bup1[0] = *it;
	//初始化完成后it递增1
	if (it == s.end()) return 1; //考虑只有一个数字的数组情况
	for (int i = 0; i < length-1; i++)
	{
		it++;
		int Index1 = CheckRepeat(bup1, lenbup1, *it);
		int Index2 = CheckRepeat(bup2, lenbup2, *it);
		//首先维护bup1数组
		//一定要回溯寻找
		if ( Index1 == -1 && (flag == 0))
		{
			flag = 0; //flag 维护 维持对现在数组的赋值
			bup1[lenbup1] = *it; //赋值
			lenbup1++; //长度维护
		}
	    else if (Index1 != -1 && (flag == 0))
		{

			if (lenbup1 < lenbup2)
			{
				for (int i = 0; i < lenbup1; i++) bup1[i] = 0;
				lenbup1 = 1; //长度维护  
				flag = 0; //flag维护
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
				lenbup2 = 1; //长度维护
				flag = 1; //flag维护
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
			flag = 1; //flag 维护 维持对现在数组的赋值
			bup2[lenbup2] = *it; //赋值
			lenbup2++; //长度维护
		}
		//一旦进入这种情况 需要转换
		else if ((Index2 != -1) && (flag == 1))
		{
			//把bup1数组删除重新构造
			if (lenbup1 < lenbup2)
			{
				for (int i = 0; i < lenbup1; i++) bup1[i] = 0;
				lenbup1 = 1; //长度维护  
				flag = 0; //flag维护
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
				lenbup2 = 1; //长度维护
				flag = 1; //flag维护
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