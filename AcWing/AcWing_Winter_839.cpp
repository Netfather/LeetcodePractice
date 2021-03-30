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

//����һ����������ȫ��������Ȼ�����ֶ������ǰ����б����ʽ�洢�� 
// �������б�洢������������ӵ��һ���ǳ��õ����� ��֪ĳ�����ڵ���±�Ϊu ��ô������ڵ�ض���2u �ҽڵ������ض���2u+1
// ������������������ ����һ�����ڵ� ����ֵ һ�������������ڵ㶼ҪС  �������ݹ�����  ���down up�������� �Ϳ���ʵ�ּ������еĶѲ���
const int N = 100010;
int w[N];
int ph[N];  //��ŵ�k���������±�
int hp[N];  //��Ŷ��е�Ĳ������
int mysize = 0;  //�����mysize�Ĺ��ܾ���һ����ַ������ ����������������׼ȷά��mysize��С ���������0��ʼ

// ��Ҫʵ�� �����ݹ���� down �� up
// ���������ĺ����ѵ��������δ�������ɾ����k���� ���ֲ���
// �����ڹ��������Ǿ�������swap  ���� ÿ�����ĵ�ַ�Ǿ���������  ���߻���˵�� ĳ����ַ�洢��ֵ�Ǿ��������
// �����ÿ��swap����ʱ�� ���Ƕ�Ҫά��ph �� hp   ph �ǽ� k������תΪ �����õ��±� ͬ��hp�ǽ������õ��±�תΪ ���������ĵ�k������

// u v �������õĵ�ַ ���Ӧ���ǳ���ȷ
void heap_swap(int u, int v)
{
	swap(w[u], w[v]);
	swap(hp[u], hp[v]); // ������Ŀָ���˵�k���� ������Ҫά��������ӳ����ܰѵ�k����תΪĿǰ�������е�����λ��
	swap(ph[hp[u]], ph[hp[v]]);

}

void down(int u)
{
	int t = u; //�ٶ�����ĵ�ַ������Сֵ  ��Сֵ����u��
	if (2 * u <= mysize && w[2 * u] < w[t]) t = 2 * u;
	if (2 * u + 1 <= mysize && w[2 * u + 1] < w[t]) t = 2 * u + 1;

	if (t != u)
	{
		heap_swap(t, u);
		down(t);
	}
	return;
}

void up(int u)
{
	int t = u;
	if ( u/2 && w[u / 2] > w[t]) t = u / 2;

	if (t != u)
	{
		heap_swap(t,u);
		up(t);
	}
	return;

}


int main()
{
	int n;
	cin >> n;
	int m = 0;
	while (n--)
	{
		string opera;
		int a;
		cin >> opera;
		if (opera == "I")
		{
			cin >> a;
			m++; //�ڼ����������
			w[++mysize] = a;
			ph[m] = mysize;
			hp[mysize] = m;
			up(mysize);

		}
		else if (opera == "PM")
		{
			cout << w[1] << endl;
		}
		else if (opera == "DM")
		{
			heap_swap(1, mysize);
			mysize--;
			//w[1] = w[mysize--]; // ��w[1] ֱ���޸�Ϊ��ĩβ��Ԫ�� Ȼ���ַ������-1 Ȼ����down
			down(1);
		}
		else if (opera == "D")
		{
			cin >> a;
			int u = ph[a];
			heap_swap(u, mysize);
			mysize--;
			down(u);
			up(u);
		}
		else if (opera == "C")
		{
			int k;
			cin >> k >> a;

			w[ph[k]] = a;
			down(ph[k]);
			up(ph[k]);
		}
	}


	return 0;
}


