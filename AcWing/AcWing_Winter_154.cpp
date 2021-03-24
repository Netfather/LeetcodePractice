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

//�Ȳ������ֵ�Ĳ��� ���ǿ��� k����Сֵ �����漰���Ƿ�����ڵ����� ���ǵĶ��д洢��������
//  վ��һ������Ҫ�������iλ�� ��ǰ�� ��Сֵ����
// �����ж� ��ͷԪ���Ƿ񳬳��� ���� �Ǿ͵�������
// Ȼ���ж� ��βԪ���Ƿ�ȵ�ǰ�����Ԫ�ظ����Ǿ͵�����β����Ϊ����������֮ǰ����ģ�����ȴ�ȵ�ǰ����Ĵ���ô����Զ�����ܱ�ȡ����
// �������������
// ����� ����Ҫ��΢����һ�µ�һ�����ڵ�Ԫ��
const int N = 1000010;
int w[N];



int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> w[i];

	deque<int> small;  //�洢���Ƕ�Ӧֵ������  ��������ͬʱҪ�����ͷ�Ͷ�β �����Ҫʹ��˫�˶���

// �Ȱ�ǰk���������
	small.push_back(0); // ��ʼֵ���
	// ���´����һ�����ڵ��������֣���һ�����ڲ���Ҫ���ǳ��� ���ֻ��Ҫ��֤�ҵ�ǰk����Сֵ  Ȼ�����small ���м���
	for (int i = 1; i < k; i++)
	{
		while (!small.empty() && w[small.back()] >= w[i]) small.pop_back();
		small.push_back(i);
	}
	cout << w[small.front()] << " ";
// ��ʼ��������
	for (int i = k; i < n; i++)
	{
		while (!small.empty() && small.front() + k <= i) small.pop_front(); // ����Ԫ������ ����k���ڴ�С ��Ҫpop
		while (!small.empty() && w[small.back()] >= w[i]) small.pop_back();
		// ��push֮ǰ����һ���ж� ��� ��ǰ����Ԫ�س������ڷ�Χ��
		small.push_back(i);
		cout << w[small.front()] << " ";
	}
	cout << endl;

	//����big���
	deque<int> big;
	big.push_back(0);
	for (int i = 1; i < k; i++)
	{
		while (!big.empty() && w[big.back()] <= w[i]) big.pop_back();
		big.push_back(i);
	}
	cout << w[big.front()] << " ";
	for (int i = k; i < n; i++)
	{
		while (!big.empty() && big.front() + k <= i) big.pop_front();
		while (!big.empty() && w[big.back()] <= w[i]) big.pop_back();
		big.push_back(i);
		cout << w[big.front()] << " ";
	}

	return 0;
}