
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

/*
//Way 1 : ��֦�� ��ʵ����������������ѧ��ϵ��
//���ڼ�֦�������жϵ�ǰi���е��Ƿ���index������������һ��
bool check(int index, int m, int n,int i)
{
	int j_pre = (index-1) / m + 1; //��
	int k_pre = (index-1) % m + 1 ; //��
	int j = (i-1) / m + 1;
	int k = (i-1) % m + 1;
	if (
		   (j_pre < n && k_pre < m && (j == j_pre + 1 && k == k_pre ))
		|| (j_pre < n && k_pre < m && (j == j_pre && k == k_pre + 1))
		|| (j_pre == n && k == k_pre + 1 && j == j_pre)
		|| (k_pre == m && j == j_pre + 1 && k == k_pre)
		) return true;
	return false;
}

//resΪ������棬mΪ��,nΪ�У�stepΪ��ǰ��д�˶��ٲ�,indexΪ��һ����д�����ĸ���
void Search(vector<vector<int>> &res,vector<int> &tempres, int m, int n, int step, int index)
{
	if (step == m + n - 2)
	{
		if (index == m*n && tempres.size() == m+n -2)	res.push_back(tempres);
		return;
	}

	for (int i = index + 1; i < m*n + 1; i++)
	{
		tempres.push_back(i);
		if(check(index,m,n,i)) Search(res, tempres, m, n, step + 1, i);
		tempres.pop_back();
	}
	return;
}


int uniquePaths(int m, int n) {
	vector<int> tempres;
	vector<vector<int>> res;
	Search(res, tempres, m, n, 0, 1);
	return res.size();
}


int calC(int n, int m) {
	if (m == 1)
		return n;
	else if (n == m)
		return 1;
	else return (calC(n - 1, m - 1) + calC(n - 1, m));
}

int uniquePaths(int m, int n) {
//���ʾ���ʵ�ָ��������е�  (m+n-2) C (m - 1)
	//����ʹ�ù�ʽ�����������������˿���ʹ�ò��+�ݹ�ķ���
	return calC(m + n - 2, m - 1);
}


int main()
{
	cout << uniquePaths(7, 3) <<endl;
	system("Pause");
	return 0;
}

*/