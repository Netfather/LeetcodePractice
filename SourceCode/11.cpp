

/*
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define Ai  height[i]
#define Aj  height[j]

//method 1 目前最快的是 两次循环其中加入限制条件即可 但是肯定还有更快的
/*
int maxArea(vector<int>& height) {
	int length = height.size();
	int temp_con = 0; //存储上一次容器的水容量
	int pre_con = 0; //存储本次容器的水容量
	int i = 0;
	int j = 0;
	for (; i < length; i++)
	{
		if (Ai < height[0]) continue;
		if (length >= 2 && i> 1 && Ai < height[i - 1]) continue;
		for (j = i+1; j < length; j++)
		{
			//在循环中加入限制条件可以更快解决
			pre_con = min(Ai,Aj) * (abs(i - j));
			//temp update
			if (pre_con > temp_con) temp_con = pre_con;
			else temp_con = temp_con;
		}
	}
	return temp_con;
}


//method 2
//滑动窗口并没有很快 
//如果使用算法自带的寻找最小值的函数，可以达到最快速度 //同时这里只需要一个循环即可
//并不是滑动窗口 而是两边同时开始缩小，哪边更小就放哪边
//这是一种滑动窗口的改进，我的想法是 通过滑动窗口找到每一次滑动的最小值
//然而实际上每次动态窗口宽度-1的时候，只需要确定两边的最小值，就可以保证这个一定是这次d的最大值了
//归根结底原因在于，你这次d-1，那么你一定要保证这次的两边一定要比上一次的两边要长才行，
//如果这次面积小是因为base_window导致的，那么下一次就改变dy_window

int maxArea(vector<int>& height) {
	int length = height.size();
	int pre_con = 0; //存储本次容器的水容量

	int base_window = 0;
	int dy_window = length - 1;

	for (; base_window < dy_window;)
	{
		pre_con = max(pre_con ,min(height[base_window], height[dy_window]) * (dy_window-base_window));
		if (height[base_window] < height[dy_window]) base_window++;
		else dy_window--;



	}

	return pre_con;
}


int main()
{

	int iArray[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	vector<int> input(iArray, iArray + 9);
	cout << maxArea(input) << endl;;
	system("Pause");
	return 0;
}


*/