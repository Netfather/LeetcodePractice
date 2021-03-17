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

// �൱���ӵ�һ����  �ֲ�������
// ��һ�� ������ĳһλ��x ����c ��������ô��
//   һ��n���ȵ����飬 ��������λpair �����¼����Щλ��+c  ��ô��Ч�� ����һ�����飬��������λpair�е�first Ԫ�� �����Ӧλ��Ԫ��λsecondԪ��
// ͨ�������ʽ ���ǿ��԰���������޳������Ͻ��в��������⣬ͶӰ��һ�� n������������ Ȼ��ʹ��ǰ׺�����ָ������ĺ�

// ����˼·������ ����һ�� all ���飬��������¼����������������õ�������
// Ȼ���ڹ���ǰ׺�������ʱ������ʹ��all�Ĵ�С�����й���  Ҳ�������all ����е��� �������lr ��ѯ ͶӰ��ָ�����꣬Ȼ���ٰ�ָ�����꽻��s���

// �ڶ��� ����all�洢�����꣬������Ҫ���������������ʹ�õ������꣬ͳͳ����¼������Ȼ�������ȥ��

typedef pair<int, int> PII; //�������ڴ洢  add ���� �Ͳ�ѯ����ÿһ��Ԫ�ض�
vector<int> alls; //����洢���е������������ϵ�����
vector<PII> add;  //�洢 �ӷ���������������
queue<PII> Query; //����洢��ѯlr�����Ķ���
const int N = 300010;
int s[N]; //�洢ǰ׺������   ��ʵ����ʹ��vector<int> S Ҳ����
int a[N]; //�洢 ����add������

int find(int x)
{
	int l = 0, r = alls.size() - 1;

	while (l < r)
	{
		int mid = l + r >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;

	}
	return r + 1;

}

int main()
{
	int n, m;
	cin >> n >> m;
	//����ӷ�����
	while (n--)
	{
		int x, c;
		cin >> x >> c;
		add.push_back({ x, c }); //������¼
		alls.push_back(x); //�����¼
	}
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		Query.push({ l,r });
		alls.push_back(l);
		alls.push_back(r);
	}

	// �������õ�����������ȥ��   ������ Ȼ����һ��ȥ�� ������ɽ����������λ�� Ȼ��erase�����ظ�Ԫ��
	sort(alls.begin(), alls.end());
	auto it = unique(alls.begin(), alls.end());
	alls.erase(it, alls.end());

	// ����ӷ����� ������Ҫ��������Ϊ������Ȼ������+c ���Ƕ�Ӧλ��+c
	for (auto elements : add)
	{
		// ����������Ҫ�Ȱ� elements.first�洢������ֵ �ҵ���Ӧ�� alls�е�����
		int alls_index = find(elements.first);
		a[alls_index] += elements.second;
	}
	// Ȼ�����a���� ����alls�Ĵ�С ת��λ ǰ׺������
	for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

	//��� ����������ѯ������
	while (!Query.empty())
	{
		auto elements = Query.front();
		Query.pop();
		int l = find(elements.first);
		int r = find(elements.second);
		cout << s[r] - s[l - 1] << endl;

	}

	return 0;
}