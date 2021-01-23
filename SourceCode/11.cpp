

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

//method 1 Ŀǰ������ ����ѭ�����м��������������� ���ǿ϶����и����
/*
int maxArea(vector<int>& height) {
	int length = height.size();
	int temp_con = 0; //�洢��һ��������ˮ����
	int pre_con = 0; //�洢����������ˮ����
	int i = 0;
	int j = 0;
	for (; i < length; i++)
	{
		if (Ai < height[0]) continue;
		if (length >= 2 && i> 1 && Ai < height[i - 1]) continue;
		for (j = i+1; j < length; j++)
		{
			//��ѭ���м��������������Ը�����
			pre_con = min(Ai,Aj) * (abs(i - j));
			//temp update
			if (pre_con > temp_con) temp_con = pre_con;
			else temp_con = temp_con;
		}
	}
	return temp_con;
}


//method 2
//�������ڲ�û�кܿ� 
//���ʹ���㷨�Դ���Ѱ����Сֵ�ĺ��������Դﵽ����ٶ� //ͬʱ����ֻ��Ҫһ��ѭ������
//�����ǻ������� ��������ͬʱ��ʼ��С���ı߸�С�ͷ��ı�
//����һ�ֻ������ڵĸĽ����ҵ��뷨�� ͨ�����������ҵ�ÿһ�λ�������Сֵ
//Ȼ��ʵ����ÿ�ζ�̬���ڿ��-1��ʱ��ֻ��Ҫȷ�����ߵ���Сֵ���Ϳ��Ա�֤���һ�������d�����ֵ��
//������ԭ�����ڣ������d-1����ô��һ��Ҫ��֤��ε�����һ��Ҫ����һ�ε�����Ҫ�����У�
//���������С����Ϊbase_window���µģ���ô��һ�ξ͸ı�dy_window

int maxArea(vector<int>& height) {
	int length = height.size();
	int pre_con = 0; //�洢����������ˮ����

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