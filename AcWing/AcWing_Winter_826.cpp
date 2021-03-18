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

// ���ڵ����� ʹ���������� һ��Ϊe���� �洢���д��ڵ�λ�� ne���� �洢����e�����Ӧλ�õ���һ������
// ����Ҫһ�����ұ� ������ұ��Ӧ���� ��k����������� ��Ӧ��e���ĸ��±�����
// һ�ι��������� ţ�ƣ���
// ������Ŀ����k�Ǵ�1��ʼ�� ��������cin��k Ҫ��ȥ1

const int N = 100010;
int e[N];  //�洢ÿһ�β����Ԫ��   ��ʾ��i�������Ԫ���Ƕ���
int ne[N]; // �洢��i��Ԫ�ص���һ��Ԫ�ص������Ƕ���
int idx = 0; // ���������Ϊ�����������ڷ���ÿһ��Ԫ�ص�Ψһ���б�־
int head = -1; // ���ڱ����������ı�ͷ�±�����  ������-1 ����Ϊ�ڸտ�ʼ��ʱ�� ne[idx] = head ��ôʹ��-1 �Ϳ������ý���λԪ�ظ�ֵ�ɹ�
// ����һ��ʼû�����ֵ�ʱ�� ���ǿ�����Ϊ��ͷ��0���ұ� Ҳ����-1��λ��

// �ڱ�ͷ�������һ����
void insert(int x)
{
	// ���Ȳ������߶�ʮһ �����ֲ���e��
	e[idx] = x;
	// �����������һ��ָ��λ��ָ�����ڵı�ͷ
	ne[idx] = head;
	//Ȼ��������ڵ�head;
	head = idx++;
}
// ɾ����k�����������
void deletee(int k)
{
	// ����idxֻ���ڲ���ʱ�Ż����  ��������k��ʵ����e���±�����
	if (k != -1)
	{
		ne[k] = ne[ne[k]];
	}
	//���ɾ������ͷ�ڵ�
	else
	{
		head = ne[head];
	}
}
// �ڵ�k����������ֺ������һ����x
void insertK(int k, int x)
{
	// �����¿ռ�
	e[idx] = x;
	// ��ԭ����ne���浽�¿��ٵĿռ�
	ne[idx] = ne[k];
	// ����ǰ�¿ռ����k����
	ne[k] = idx++; //ע�����++��ʵ��ʡ���˲���  ��һ��ͬʱ����������� 1.���¿ռ����k֮��2. Ϊ��һ���õ��Ŀռ�++
}


int main()
{
	int m;
	cin >> m;
	while (m--)
	{
		char O;
		cin >> O;
		if (O == 'H')
		{
			int x;
			cin >> x;
			insert(x);
		}
		else if (O == 'I')
		{
			int k, x;
			cin >> k >> x;
			insertK(k-1, x);
		}
		else
		{
			int k;
			cin >> k;
			deletee(k-1);
		}
	}

	//���
	for (int i = head; i != -1; i = ne[i]) cout << e[i] << " ";


	return 0;
}