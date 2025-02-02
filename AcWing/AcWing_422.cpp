//思路：先排序，然后通过pre_right和pre_left来维护每一次合并的子区间的起始位置和终止位置，注意 pre_right 是要用max来进行维护的！！！！


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

class Point
{
public:
	int x;
	int y;
	Point(int a, int b)
	{
		x = a;
		y = b;
	}
	Point()
	{
		x = -1;
		y = -1;
	}

};



bool compare(Point &st1, Point  &st2)
{
	if (st1.x == st2.x) return st1.y < st2.y;
	return st1.x < st2.x;
}

bool compare2(Point &st1, Point  &st2)
{
	return st1.y < st2.y;
}



int main()
{
	int L, M;
	cin >> L >> M;
	L++;
	vector<Point> Points(M, Point());

	while (M--)
	{
		int a, b;
		cin >> a >> b;
		Points[M] = Point(a, b);
	}
	if (Points.size() == 1) return (L - Points[0].y + Points[0].x - 1);

	sort(Points.begin(), Points.end(), compare);

	int pre_right = Points[0].y;
	int pre_left = Points[0].x;
	for (int i = 1; i < Points.size(); i++)
	{
		if (Points[i].x <= pre_right)
		{
			pre_right = max(pre_right,Points[i].y);  //千万别忘了这一步！！！！
			continue;
		}
		else
		{
			L = L - (pre_right - pre_left + 1);
			pre_left = Points[i].x;
			pre_right = Points[i].y;
		}
	}
	L = L - (pre_right - pre_left + 1);
	cout << L << endl;
	system("Pause");
	return 0;
}