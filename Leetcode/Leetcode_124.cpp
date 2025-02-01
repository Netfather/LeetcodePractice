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
// //单源最长路径和函数，函数返回从当前源点开始，最长的路径和
// //输入为源点下标，key值矩阵，目前已经计算得到的路径和矩阵
// //测试完成 输出成功！ 但是时间复杂度无法达标考虑使用 floyd算法
// //void maxsumfuncfloyd(vector<vector<int>> &summax, vector<int> &key, vector<vector<int>> &path)
// //{
//	// //step1 初始化sunmax矩阵
//	// for (int i = 0; i < key.size(); i++)
//	// {
//	//	 for (int j = 0; j < key.size(); j++)
//	//	 {
//	//		 if (i == j) summax[i][j] = 0;
//	//		 else summax[i][j] = -10000;
//	//	 }
//	// }
//	// //step2 从邻接矩阵赋值必要数据
//	// for (int i = 0; i < key.size(); i++)
//	// {
//	//	 for (auto j : path[i])
//	//	 {
//	//		 summax[i][j] = key[i] + key[j];
//	//	 }
//	// }
//	// //floyd算法
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
//	// //遍历每一个与index有关的节点，如果存在一个已经归纳好的值，就直接赋值，同时将那个节点归纳为已收录
//
//	// while (1)
//	// {
//	//	 //寻找未被收录到s中的距离最大值的那个顶点
//	//	 int flag = 0;
//	//	 for (int i = 0; i < key.size(); i++)
//	//	 {
//	//		 if (flag == 1 && collected[i] == false && dis[i] > maxtemp) //如果这个dis比maxtemp还要大 而且未被收录
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
//	//	 if (flag == 0) break; //如果标志位一直是0 说明找不到没有被收录的点了，跳出循环
//	//	 collected[index] = true;
//	//	 for (auto i : path[index])
//	//	 {
//	//		 if (collected[i] != true && dis[i] < key[i] + dis[index]) dis[i] = key[i] + dis[index];
//	//	 }
//	// }
//	// //跳出循环后 返回dis数组中的最大值，该值就是从该源点出发的路径最大值
//	// maxtemp = int_min;
//	// for (int i = 0; i < key.size(); i++)
//	// {
//	//	 maxtemp = max(maxtemp, dis[i]);
//	// }
//	// return maxtemp;
// //}
//
//
//  //完成转置函数，将一颗二叉树转置为一个含有二维矩阵，矩阵包含所有路径信息 和一个含有key值的一维矩阵 同时返回树中最大的元素值
// //测试完成 转置成功！
// //法1  通过转置为邻接矩阵，然后自底向上生成maxtemp，得到结果
// //int convert(treenode* root, vector<vector<int>> &path, vector<int> &key)
// //{
//	// treenode *temp; //定义遍历指针
//	// queue<treenode*> que; //构建队列
//	// que.push(root); //初始化队列
//	// int cnt = 0; //下标计数器
//	// int maxtemp = int_min;
//	// while (!que.empty())
//	// {
//	//	 temp = que.front(); //指定队列第一个
//	//	 if (temp->left != null)
//	//	 {
//	//		 que.push(temp->left);
//	//		 path[cnt].push_back((cnt + que.size() - 1));  //父类节点路径写入子类节点
//	//		 path.push_back(vector<int>(1, cnt)); //子类节点写入父类节点
//	//	 }
//	//	 if (temp->right != null)
//	//	 {
//	//		 que.push(temp->right);
//	//		 path[cnt].push_back((cnt + que.size() - 1));  //父类节点路径写入子类节点
//	//		 path.push_back(vector<int>(1, cnt)); //子类节点写入父类节点
//	//	 }
//	//	 key.push_back(temp->val); //当前值压入
//	//	 maxtemp = max(maxtemp, temp->val);
//	//	 ++cnt; //计数器维护
//	//	 que.pop(); //出队列,当前节点可抛弃
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
//	// queue<int> que; //队列迭代器
//	// vector<bool> collected(key.size(), false); //队列标志位
//	// vector<bool> done(key.size(), false); //队列标志位
//	// int cnt = 0;
//	// //初始化队列 压入所有叶节点
//	// for (int i = 1; i < key.size(); i++)
//	// {
//	//	 if (path[i].size() == 1)
//	//	 {
//	//		 que.push(i); //所有的叶子节点入队
//	//		 collected[i] = true; //入队标志
//	//	 }
//	// }
//	// while (!que.empty())
//	// {
//	//	 int index = que.front();
//	//	 if (path[index][0] > 0 && collected[path[index][0]] == false)
//	//	 {
//	//		 collected[path[index][0]] = true;
//	//		 que.push(path[index][0]); //当前节点的父类节点入队 根节点排除在外
//	//	 }
//	//	 if (path[index].size() == 3)
//	//	 {
//	//		 if (done[path[index][1]] == true && done[path[index][2]] == true)
//	//		 {
//	//			 maxtemp = max(maxtemp, key[index] + key[path[index][1]] + key[path[index][2]]);
//	//			 int temp = max(key[index] + key[path[index][1]], key[index] + key[path[index][2]]);
//	//			 key[index] = max(key[index], temp); //更新key值 取较大者
//	//			 if (key[index] < 0) key[index] = 0;
//	//			 done[index] = true;
//	//			 que.pop();
//	//		 }
//	//		 else
//	//		 {
//	//			 done[index] = false;
//	//			 que.push(index); //重新入队
//	//			 que.pop(); //对首出队
//	//		 }
//	//	 }
//	//	 else if (path[index].size() == 2)
//	//	 {
//	//		 if (done[path[index][1]] == true)
//	//		 {
//	//			 key[index] = max(key[index], key[index] + key[path[index][1]]); //更新key值 取较大者
//	//			 maxtemp = max(maxtemp, key[index]);
//	//			 if (key[index] < 0) key[index] = 0;
//	//			 done[index] = true;
//	//			 que.pop();
//	//		 }
//	//		 else
//	//		 {
//	//			 done[index] = false;
//	//			 que.push(index); //重新入队
//	//			 que.pop(); //对首出队
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
////法2 通过递归，因为每一个节点的最大值，一定只存在4中情况， 
////1. 自己 2.自己+左边 3.自己+右边 4.自己+左+右
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
