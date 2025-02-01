/*
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

//Way1�� �Զ����µĶ�̬�滮
//���ȣ�����һ���ܹ���һ������ֽ�Ϊ������ṹ������
//Ȼ��Ȼ�����е���������ÿһ�ֽ��ж������ظ��ṹ
//�������� �� word1[0,1,����i����m] word2[0,1,����j����n]
//dp[i][j]ֻ������������ʽ��ȷ��
//		  = dp[i-1][j-1] //if word[i] == word[j]
//        = min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j]) + 1 //if word[i] != word[j]
//			�ⲿ�ֱ�־���ظ�������                    �ⲿ�ֱ�־������ɾ�����滻����Ӳ����е��κ�һ��
//Ȼ���Զ����µĹ��������񼴿̵õ����
int minDistance(string word1, string word2) {
	int m = word1.length();
	int n = word2.length();

	//����dp[m+1][n+1]��С�Ķ�̬�滮����һ����Ϊ�˷������߽�����
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));
	//Ӧ��ע�⵽�߽������ڴ˴������һ���ִ�Ϊ�գ���һ���ִ�Ϊ1�����
	//Step1: ��ʼ���б߽�
	for (int i = 0; i < m+1; i++) dp[i][0] = i;
	//Step2: ��ʼ���б߽�
	for (int j = 0; j < n + 1; j++) dp[0][j] = j;
	//Step3: �Զ����µ����ɱ��
	for (int i = 1; i < m + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (word1.at(i-1) == word2.at(j-1)) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
		}
	}
	return dp[m][n];
}

int main()
{
	cout << minDistance("horse", "rose") << endl;
	system("Pause");
	return 0;
}

*/