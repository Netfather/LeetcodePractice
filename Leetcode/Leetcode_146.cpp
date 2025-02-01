//#include <iostream>
//#include <algorithm>
//#include <set>
//#include <unordered_map>
//#include <unordered_set>
//#include <sstream>
//#include <map>
//#include <stack>
//#include <string>
//#include <vector>
//#include <queue>
//#include <list>
//#include <stdlib.h>
//#include <math.h>
//using namespace std;
//
//
////Way1: 使用List  插入，删除非常快速，但是在find过程中非常耗时
////class LRUCache {
////public:
////	unordered_map<int, int> HashMap;  //存放数据
////	list<int> List;  //每一次操作后，首元素一定是待删除的元素
////	int size;
////public:
////	LRUCache(int capacity) {
////		this->size = capacity;  //当前内容
////	}
////
////	void MaintainList(list<int> &List, int key)
////	{
////		list<int>::iterator temp; //迭代器
////			//维护List
////		for (temp = List.begin(); temp != List.end(); temp++) if (*temp == key) break;
////		List.erase(temp);
////		List.push_back(key);
////	}
////
////	int get(int key) {
////		if (HashMap.count(key))
////		{
////			MaintainList(List, key);
////			return HashMap[key];
////		}
////		else return -1;
////	}
////
////	void put(int key, int value) {
////		//1.if key exits
////		if (HashMap.count(key))
////		{
////			HashMap[key] = value;
////			MaintainList(List, key);
////		}
////		else
////		{
////			//2.if not exits, if capacity is not full
////			if (HashMap.size() < size)
////			{
////				HashMap.insert({ key,value });
////				List.push_back(key);
////			}
////			//3. if not exits and capacity is full
////			else
////			{
////				HashMap.erase(List.front());
////				List.pop_front();
////				HashMap.insert({ key,value });
////				List.push_back(key);
////			}
////		}
////	}
////};
//
//
////Way2： 方法1中最耽误时间的地方在于Maintain部分，因此我们可以使用一个哈希表把每次List插入之后的key值和地址保存起来
//class LRUCache {
//private:
//	unordered_map<int, int> HashMap;  //存放数据
//	unordered_map<int, list<int>::iterator> HashListAddress;
//	list<int> List;  //每一次操作后，首元素一定是待删除的元素
//	int size;
//public:
//	LRUCache(int capacity) {
//		this->size = capacity;  //当前内容
//	}
//	void Maintain(unordered_map<int, int> &HashMap, unordered_map<int, list<int>::iterator> &HashListAddress, list<int> &List,int key)
//	{
//		List.erase(HashListAddress[key]);
//		HashListAddress.erase(key);
//		List.emplace_front(key);
//		HashListAddress.insert({ key,List.begin() });
//	}
//	void Insert(unordered_map<int, int> &HashMap, unordered_map<int, list<int>::iterator> &HashListAddress, list<int> &List, int key,int value)
//	{
//		HashMap.insert({ key,value });
//		List.emplace_front(key);
//		HashListAddress.insert({ key,List.begin() });
//	}
//
//	int get(int key) {
//		if (HashMap.count(key))
//		{
//			Maintain(HashMap, HashListAddress, List, key);
//			return HashMap[key];
//		}
//		else return -1;
//	}
//
//	void put(int key, int value) {
//		//1.if key exits
//		if (HashMap.count(key))
//		{
//			HashMap[key] = value;
//			Maintain(HashMap, HashListAddress, List, key);
//		}
//		else
//		{
//			//2.if not exits, if capacity is not full
//			if (HashMap.size() < size) Insert(HashMap, HashListAddress, List, key, value);
//			//3. if not exits and capacity is full
//			else
//			{
//				HashListAddress.erase(List.back());
//				HashMap.erase(List.back());
//				List.pop_back();
//				Insert(HashMap, HashListAddress, List, key, value);
//			}
//		}
//	}
//};
//
//int main()
//{
//	LRUCache cache = LRUCache(2 /* capacity */);
//
//	cache.put(1, 1);
//	cache.put(2, 2);
//	cache.get(1);       // returns 1
//	cache.put(3, 3);    // evicts key 2
//	cache.get(2);       // returns -1 (not found)
//	cache.put(4, 4);    // evicts key 1
//	cache.get(1);       // returns -1 (not found)
//	cache.get(3);       // returns 3
//	cache.get(4);       // returns 4
//
//	system("Pause");
//	return 0;
//}
