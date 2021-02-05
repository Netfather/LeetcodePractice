//思路：

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

class Student
{
public:
	int num;
	int Chin;
	int sum;
	Student(int a, int b, int c)
	{
		num = a;
		Chin = b;
		sum = c;
	}
	Student()
	{
		num = 0;
		Chin = 0;
		sum = 0;
	}
};
// campare函数 如果a 比b排名高则返回true 否则返回false
bool campare(Student* a, Student* b)
{
	if (a->sum > b->sum) return true;
	else if (a->sum < b->sum) return false;

	if (a->Chin > b->Chin) return true;
	else if (a->Chin < b->Chin) return false;

	if (a->num < b->num) return true;
	else if (a->num > b->num) return false;

	return false;
}


int main()
{
	int N;
	cin >> N;
	vector<Student> Stus(N, Student());

	for (int i = 1; i < N + 1; i++)
	{
		int b, c, d;
		cin >> b >> c >> d;

		Stus[i - 1] = Student(i, b, b + c + d);
	}

	Student Stu1 = Student(0, -1, 0), Stu2 = Student(0, -2, 0), Stu3 = Student(0, -3, 0), Stu4 = Student(0, -4, 0), Stu5 = Student(0, -5, 0);

	for (auto stu : Stus)
	{
		if (campare(&stu, &Stu1))
		{
			Stu5 = Stu4;
			Stu4 = Stu3;
			Stu3 = Stu2;
			Stu2 = Stu1;
			Stu1 = stu;
		}
		else if (campare(&stu, &Stu2))
		{
			Stu5 = Stu4;
			Stu4 = Stu3;
			Stu3 = Stu2;
			Stu2 = stu;
		}
		else if (campare(&stu, &Stu3))
		{
			Stu5 = Stu4;
			Stu4 = Stu3;
			Stu3 = stu;
		}
		else if (campare(&stu, &Stu4))
		{
			Stu5 = Stu4;
			Stu4 = stu;
		}
		else if (campare(&stu, &Stu5)) Stu5 = stu;
	}

	cout << Stu1.num << " " << Stu1.sum << endl;
	cout << Stu2.num << " " << Stu2.sum << endl;
	cout << Stu3.num << " " << Stu3.sum << endl;
	cout << Stu4.num << " " << Stu4.sum << endl;
	cout << Stu5.num << " " << Stu5.sum << endl;
	return 0;
}