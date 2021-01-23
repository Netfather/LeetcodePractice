//#include <iostream>
//#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
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
////���������ṹ
//struct WordTree
//{
//	string content;
//	vector<WordTree*> index;
//	WordTree(string input) :content(input),index() {}
//};
////�ж������ַ�������Ծ����Ƿ�Ϊ1
////Ϊ1�򷵻�ture ���򷵻�false
//bool check(string a, string b)
//{
//	int cnt = 0;
//	for (int i = 0; i < a.size(); i++)	if (a[i] != b[i]) ++cnt;
//	if (cnt == 1) return true;
//	return false;
//}
//
////�������ṹ�������
////���룺 ��ʼ�ʣ��ֵ���ս�����ֵ��е��±�
////���أ� ���ṹ���ڵ�ָ������ĸ߶�
//WordTree* Construct(string beginWord, vector<string>& wordList, string endWord)
//{
//	WordTree* root = new WordTree(beginWord);
//	unordered_set<string> words(wordList.begin(), wordList.end()); //��ԭ����ת�Ƶ�words�������У����������ֱ��ͨ���±�����
//	unordered_map<string, int> dicindex; //�ֵ���� string ��Ӧ��ʹ���˶��ٴ�
//	//vector<int> eraseListIndex;
//	queue<WordTree*> Que;
//	int flag = 0;
//	int cnt = 0;
//	int upbound = 1;
//	Que.push(root);
//	WordTree* temp; //��������ָ��
//	while (!Que.empty())
//	{
//		++cnt;
//		auto temp = Que.front();
//		//���ɵ㣬ʹ�õ��ʱ�������ʹ��wordList��������ʡ�ռ�
//		for (int l = 0; l < temp->content.size(); l++)
//		{
//			for (char c = 'a'; c <= 'z'; c++)
//			{
//				if (temp->content.at(l) == c) continue;
//				char old = temp->content.at(l); //�ݴ�
//				temp->content.at(l) = c;
//				if (words.count(temp->content))
//				{
//					if (temp->content == endWord) flag =1;
//					temp->index.push_back(new WordTree(temp->content));
//					Que.push(temp->index.back());
//					++dicindex[temp->content];
//				}
//				temp->content.at(l) = old;
//			}
//		}
//		if (cnt == upbound)
//		{
//			if (flag == 1) break;
//			unordered_set<string>::iterator test;
//			for (test = words.begin();test != words.end();)
//			{
//				if (dicindex[*test] > 0)
//				{
//					test = words.erase(test); //�������ַ�������ֹ�ַ�����ô��ɾ��
//				}
//				else test++;
//			}
//			dicindex.clear();
//			upbound = Que.size() - 1;
//			cnt = 0;
//		}
//		Que.pop();
//	}
//	return root;
//}
//
////�����ṹ�в���Ŀ��endWord��
////���� ���ڵ㣬endWord����ǰ����i
////���ض�ά���� res
//void helper(WordTree *root, int step, string endWord, vector<vector<string>> &res,vector<string> &tempres)
//{
//	tempres.push_back(root->content);
//	if (root->index.size() == 0)
//	{
//		if (root->content != endWord) return;
//		else
//		{
//			res.push_back(tempres);
//			return;
//		}
//	}
//	else if (root->index.size() != 0)
//	{
//		for (auto &i : root->index)
//		{
//			helper(i, step + 1, endWord, res, tempres);
//			tempres.pop_back();
//		}
//	}
//	return;
//}
//
//
//vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//	vector<string>::iterator temp;
//	vector<vector<string>> res;
//	vector<string> tempres;
//	temp = find(wordList.begin(), wordList.end(), endWord);
//	if (temp == wordList.end()) return res;
//
//	//wordList.erase(temp);
//	if (check(beginWord, endWord))
//	{
//		tempres.push_back(beginWord);
//		tempres.push_back(endWord);
//		res.push_back(tempres);
//		return res;
//	}
//	temp = find(wordList.begin(), wordList.end(), beginWord);
//	if (temp != wordList.end()) wordList.erase(temp);
//	WordTree *root = Construct(beginWord, wordList, endWord);
//	helper(root, 0, endWord, res, tempres);
//	return res;
//}






//int main()
//{
//	//string beginWord = "hit";
//	//string endWord = "cog";
//	//vector<string>	wordList = { "cog", "dot", "dog", "lot", "log", "hot" };
//
//
//	//string beginWord = "dcg";
//	//string endWord = "ank";
//	//vector<string>	wordList = { "dog", "acg", "ang", "ank" };
//
//	//string beginWord = "red";
//	//string endWord = "tax";
//	//vector<string>	wordList = { "ted", "tex", "red", "tax", "tad", "den", "rex", "pee" };
//
//	//	string beginWord = "cet";
//	//string endWord = "ism";
//	//vector<string>	wordList = { "kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob"};
//
//
//	//string beginWord = "hot";
//	//string endWord = "dog";
//	//vector<string>	wordList = { "hot", "cog", "dog", "tot", "hog", "hop", "pot", "dot" };
//
//
//	vector<vector<string>> res;
//	res = findLadders(beginWord, endWord, wordList);
//	for (auto i : res)
//	{
//		for (auto j : i) cout << j << "  ";
//		cout << endl;
//	}
//	system("Pause");
//	return 0;
//}



