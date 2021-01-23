//#include <iostream>
//#include <algorithm>
//#include <map>
//#include <string>
//#include <vector>
//#include <queue>
//#include <list>
//#include <stdlib.h>
//#include <math.h>
//using namespace std;
//
//
// struct treenode {
//      int val;
//      treenode *left;
//      treenode *right;
//      treenode(int x) : val(x), left(null), right(null) {}
//  };
//
//
//
// //��Դ�·���ͺ������������شӵ�ǰԴ�㿪ʼ�����·����
// //����ΪԴ���±꣬keyֵ����Ŀǰ�Ѿ�����õ���·���;���
// //������� ����ɹ��� ����ʱ�临�Ӷ��޷���꿼��ʹ�� floyd�㷨
// //void maxsumfuncfloyd(vector<vector<int>> &summax, vector<int> &key, vector<vector<int>> &path)
// //{
//	// //step1 ��ʼ��sunmax����
//	// for (int i = 0; i < key.size(); i++)
//	// {
//	//	 for (int j = 0; j < key.size(); j++)
//	//	 {
//	//		 if (i == j) summax[i][j] = 0;
//	//		 else summax[i][j] = -10000;
//	//	 }
//	// }
//	// //step2 ���ڽӾ���ֵ��Ҫ����
//	// for (int i = 0; i < key.size(); i++)
//	// {
//	//	 for (auto j : path[i])
//	//	 {
//	//		 summax[i][j] = key[i] + key[j];
//	//	 }
//	// }
//	// //floyd�㷨
//	// for (int k = 0; k < key.size(); k++)
//	// {
//	//	 for (int i = 0; i < key.size(); i++)
//	//	 {
//	//		 for (int j = 0; j < key.size(); j++)
//	//		 {
//	//			 if (summax[i][k] + summax[k][j] > summax[i][j]) summax[i][j] = summax[i][k] + summax[k][j];
//	//		 }
//	//	 }
//	// }
// //}
//
//
//// int maxsumfunc(int index, vector<int> &key, vector<vector<int>> &path)
// //{
//	// // if (summax[index] != int_min) return summax[index] + key[index];
//	// vector<int> dis(key.size(), int_min);
//	// vector<bool> collected(key.size(), false);
//	// dis[index] = key[index];
//	// int maxtemp = int_min;
//	// //����ÿһ����index�йصĽڵ㣬�������һ���Ѿ����ɺõ�ֵ����ֱ�Ӹ�ֵ��ͬʱ���Ǹ��ڵ����Ϊ����¼
//
//	// while (1)
//	// {
//	//	 //Ѱ��δ����¼��s�еľ������ֵ���Ǹ�����
//	//	 int flag = 0;
//	//	 for (int i = 0; i < key.size(); i++)
//	//	 {
//	//		 if (flag == 1 && collected[i] == false && dis[i] > maxtemp) //������dis��maxtemp��Ҫ�� ����δ����¼
//	//		 {
//	//			 index = i;
//	//			 maxtemp = dis[i];
//	//		 }
//	//		 if (flag == 0 && collected[i] == false)
//	//		 {
//	//			 index = i;
//	//			 maxtemp = dis[i];
//	//			 flag = 1;
//	//		 }
//	//	 }
//	//	 if (flag == 0) break; //�����־λһֱ��0 ˵���Ҳ���û�б���¼�ĵ��ˣ�����ѭ��
//	//	 collected[index] = true;
//	//	 for (auto i : path[index])
//	//	 {
//	//		 if (collected[i] != true && dis[i] < key[i] + dis[index]) dis[i] = key[i] + dis[index];
//	//	 }
//	// }
//	// //����ѭ���� ����dis�����е����ֵ����ֵ���ǴӸ�Դ�������·�����ֵ
//	// maxtemp = int_min;
//	// for (int i = 0; i < key.size(); i++)
//	// {
//	//	 maxtemp = max(maxtemp, dis[i]);
//	// }
//	// return maxtemp;
// //}
//
//
//  //���ת�ú�������һ�Ŷ�����ת��Ϊһ�����ж�ά���󣬾����������·����Ϣ ��һ������keyֵ��һά���� ͬʱ������������Ԫ��ֵ
// //������� ת�óɹ���
// //��1  ͨ��ת��Ϊ�ڽӾ���Ȼ���Ե���������maxtemp���õ����
// //int convert(treenode* root, vector<vector<int>> &path, vector<int> &key)
// //{
//	// treenode *temp; //�������ָ��
//	// queue<treenode*> que; //��������
//	// que.push(root); //��ʼ������
//	// int cnt = 0; //�±������
//	// int maxtemp = int_min;
//	// while (!que.empty())
//	// {
//	//	 temp = que.front(); //ָ�����е�һ��
//	//	 if (temp->left != null)
//	//	 {
//	//		 que.push(temp->left);
//	//		 path[cnt].push_back((cnt + que.size() - 1));  //����ڵ�·��д������ڵ�
//	//		 path.push_back(vector<int>(1, cnt)); //����ڵ�д�븸��ڵ�
//	//	 }
//	//	 if (temp->right != null)
//	//	 {
//	//		 que.push(temp->right);
//	//		 path[cnt].push_back((cnt + que.size() - 1));  //����ڵ�·��д������ڵ�
//	//		 path.push_back(vector<int>(1, cnt)); //����ڵ�д�븸��ڵ�
//	//	 }
//	//	 key.push_back(temp->val); //��ǰֵѹ��
//	//	 maxtemp = max(maxtemp, temp->val);
//	//	 ++cnt; //������ά��
//	//	 que.pop(); //������,��ǰ�ڵ������
//	// }
//	// return maxtemp;
// //}
//
// //int maxpathsum(treenode* root) {
//	// vector<vector<int>> path(1, vector<int>());
//	// vector<int> key;
//	// int maxtemp = convert(root, path, key);
//	// if (maxtemp < 0) return maxtemp;
//	// if (key.size() == 1) return key[0];
//	// queue<int> que; //���е�����
//	// vector<bool> collected(key.size(), false); //���б�־λ
//	// vector<bool> done(key.size(), false); //���б�־λ
//	// int cnt = 0;
//	// //��ʼ������ ѹ������Ҷ�ڵ�
//	// for (int i = 1; i < key.size(); i++)
//	// {
//	//	 if (path[i].size() == 1)
//	//	 {
//	//		 que.push(i); //���е�Ҷ�ӽڵ����
//	//		 collected[i] = true; //��ӱ�־
//	//	 }
//	// }
//	// while (!que.empty())
//	// {
//	//	 int index = que.front();
//	//	 if (path[index][0] > 0 && collected[path[index][0]] == false)
//	//	 {
//	//		 collected[path[index][0]] = true;
//	//		 que.push(path[index][0]); //��ǰ�ڵ�ĸ���ڵ���� ���ڵ��ų�����
//	//	 }
//	//	 if (path[index].size() == 3)
//	//	 {
//	//		 if (done[path[index][1]] == true && done[path[index][2]] == true)
//	//		 {
//	//			 maxtemp = max(maxtemp, key[index] + key[path[index][1]] + key[path[index][2]]);
//	//			 int temp = max(key[index] + key[path[index][1]], key[index] + key[path[index][2]]);
//	//			 key[index] = max(key[index], temp); //����keyֵ ȡ�ϴ���
//	//			 if (key[index] < 0) key[index] = 0;
//	//			 done[index] = true;
//	//			 que.pop();
//	//		 }
//	//		 else
//	//		 {
//	//			 done[index] = false;
//	//			 que.push(index); //�������
//	//			 que.pop(); //���׳���
//	//		 }
//	//	 }
//	//	 else if (path[index].size() == 2)
//	//	 {
//	//		 if (done[path[index][1]] == true)
//	//		 {
//	//			 key[index] = max(key[index], key[index] + key[path[index][1]]); //����keyֵ ȡ�ϴ���
//	//			 maxtemp = max(maxtemp, key[index]);
//	//			 if (key[index] < 0) key[index] = 0;
//	//			 done[index] = true;
//	//			 que.pop();
//	//		 }
//	//		 else
//	//		 {
//	//			 done[index] = false;
//	//			 que.push(index); //�������
//	//			 que.pop(); //���׳���
//	//		 }
//	//	 }
//	//	 else if (path[index].size() == 1)
//	//	 {
//	//		 maxtemp = max(maxtemp, key[index]);
//	//		 if (key[index] < 0) key[index] = 0;
//	//		 done[index] = true;
//	//		 que.pop();
//	//	 }
//	// }
//	// if (path[0].size() == 1) maxtemp = max(maxtemp, key[0] + key[path[0][0]]);
//	// if (path[0].size() == 2) maxtemp = max(maxtemp, key[0] + key[path[0][0]] + key[path[0][1]]);
//	// return maxtemp;
// //}
//
//
////��2 ͨ���ݹ飬��Ϊÿһ���ڵ�����ֵ��һ��ֻ����4������� 
////1. �Լ� 2.�Լ�+��� 3.�Լ�+�ұ� 4.�Լ�+��+��
//int cur(treenode* temp, int &maxsum)
//{
//	maxsum = max(maxsum, temp->val);
//	if (!temp->left && !temp->right) return temp->val;
//
//	if (temp->left && temp->right)
//	{
//		int left = cur(temp->left, maxsum);
//		int right = cur(temp->right, maxsum);
//
//		int maxpath = max(temp->val + left, temp->val + right);
//		maxsum = max(maxpath, maxsum);
//		maxsum = max(maxsum, temp->val+left +right);
//		return max(temp->val,maxpath);
//	}
//	else if (temp->left)
//	{
//		int left = cur(temp->left, maxsum);
//		maxsum = max(maxsum, temp->val + left);
//		return max(temp->val + left, temp->val);
//	}
//	else if (temp->right)
//	{
//		int right = cur(temp->right, maxsum);
//		maxsum = max(maxsum, temp->val +right);
//		return max(temp->val + right, temp->val);
//	}
//	return 0;
//}
//
//int maxpathsum(treenode* root) 
//{
//	int maxsum = int_min;
//	cur(root, maxsum);
//	return maxsum;
//}
// int main()
// {
//	 treenode *t0 = new treenode(9);
//	 treenode *t1 = new treenode(-8);
//	 treenode *t2 = new treenode(3);
//	 treenode *t3 = new treenode(7);
//	 treenode *t4 = new treenode(2);
//	 treenode *t5 = new treenode(1);
//	 treenode *t6 = new treenode(9);
//	 treenode *t7 = new treenode(10);
//	 treenode *t8 = new treenode(11);
//
//	 ////construction
//	 //t0->left = t1;
//	 //t0->right = t2;
//	 //t1->left = t3;
//	 //t2->left = t4;
//	 //t2->right = t5;
//	 //t4->left = t6;
//	 //t4->right = t7;
//	 //t5->right = t8;
//
//	 //treenode *t0 = new treenode(1);
//	 //treenode *t1 = new treenode(2);
//	 //treenode *t2 = new treenode(3);
//	 //t0->left = t1;
//	 //t0->right = t2;
//
//	 //treenode *t0 = new treenode(-3);
//	 //treenode *t1 = new treenode(2);
//	 //treenode *t2 = new treenode(3);
//	 //treenode *t3 = new treenode(-6);
//	 //treenode *t4 = new treenode(2);
//
//
//	 //construction
//	 t0->left = t1;
//	 t1->right = t3;
//	 t1->left = t2;
//	 t3->left = t4;
//
//
//	 cout << maxpathsum(t0) << endl;
//	 system("pause");
//
//	 return 0;
// }
