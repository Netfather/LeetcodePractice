/*

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <list>
#include <stdlib.h>
#include <math.h>
using namespace std;

bool checkfirst(char c, vector<string> & words)
{
	for (string s : words)
	{
		if (s.at(0) == c) return true;
	}
	return false;
}
bool check(string s, vector<string> words, int base)//传入当前待判定s，单词列表，如果全部匹配成功 返回word中正确的顺序
//base为当前基底
{
	int temp = base + words.size() * words[0].length();
	int wordlen = words[0].length();
	int lenth = s.length();
	int i = base;  //用于字符串s中进行遍历
	int j = 0; //用于words中进行遍历
	for (; i < min(temp, lenth);)
	{
		for (j = 0; j < words.size(); j++)
		{
			if (s.substr(i, words[0].length()) == words[j])
			{
				words.erase(words.begin() + j);
				break;
			}
			if (j == words.size() - 1) return false;
		}
		i = i + wordlen;
	}
	if (words.empty()) return true;
	else return false;
}

vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> res;
	if (s.empty()) return res;
	if (words.size() == 0) return res;


	int wordlength = words[0].length(); //存储的每个单词的长度而且所有单词长度一致
	if (s.length() < wordlength * words.size()) return res; //如果s的长度比words所有单词总和加起来都小 说明不存在结果
	else if (s.length() >= wordlength * words.size())
	{
		int i = 0;
		int cnt = 0;
		for (; i <= s.length() - wordlength * words.size(); i++)
		{
			if (checkfirst(s.at(i), words) && check(s, words, i))
			{
				res.push_back(i);
				continue;
			}
		}
	}
	return res;

}


//使用 left和 right的滑动窗口，对每一次次的频率进行统计，如果这个统计的词不存在那么直接清空重新开始
//如果这个统计的词加上频率之后， 超过了word中的标准频率，那么将窗口的左边进行移动，知道窗口的左边
//到达满足要求的频率之后  left停止移动，然后right继续移动
//在这个循环过程中，当前仅当left和right之间的距离刚好是了，那么直接push_back到最后结果中
vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> allPos;
	map<string, int> wordsFreq;
	for (auto& word : words) ++wordsFreq[word];
	int len = words.empty() ? 0 : words[0].size();

	for (int pos = 0; pos < len; ++pos) {
		// tokenize all the words in s starting from pos s, only len pos needed
		vector<string> tokens;
		for (int i = pos; i < s.size(); i += len) tokens.push_back(s.substr(i, len));
		// naive sliding window algorithm, the window contains tokens in tokens(left, right]
		map<string, int> windowFreq;
		for (int left = -1, right = 0; right < tokens.size(); ++right) {
			if (wordsFreq.find(tokens[right]) != wordsFreq.end()) {
				// slide the left side of the window when too many words are found
				if (++windowFreq[tokens[right]] > wordsFreq[tokens[right]])
					while (windowFreq[tokens[right]] > wordsFreq[tokens[right]]) --windowFreq[tokens[++left]];
			}
			else {
				// reset the window if a word not in vector words is found
				windowFreq.clear();
				left = right;
			}
			// check if the sliding window contains all words in vector words
			if (right - left == words.size()) allPos.push_back(pos + (left + 1) * len);
		}
	}

	return allPos;
}
int main()
{

	vector<int> res;
//	string s = "baauxdthqwzuleorburxbkrksgpgchndjqygttnmsnidtwuutotwylhqtwyvfoboebvxukjozrssqonjcifctmsmktkphlelmbkinwxnnrhfhwokfwmaihptazkjmowargifchusybxgyosfkgfupunpvyahowhgdsnhbhbakziipcpzivtyrjpnjqwxogftaubbbcdmdnwspmtajpaayrpjjogyworwiszmxfacswxkkqkthmwhdnqnbzlzncxxxxjwclywixguosoxemfizvxduicjmajlzujbgizofgivyytdmanmxkrsuvdixmwwjfzpnzfvhpsfqnkcnxqljjfffkoezkbircxfdecktwslkcozceklqrrvchzdtclkhkrmotzjqrvctlbvrojhfcejjgmcizmrjgezzdlrwgvptxnknyssawejcsnnsbgdhmdjroanwyfpvuzistcssidwbqjvrsyzediytklpisgfminebsyvabsdtdylvzmccuaygnnrgwwsemzhezdgbvkuykhwltyqpaoyndptzlodxnndmqkplwmlivjwpjmgjcexftshhgmgvzkkpwbcupqelzacloiuqptwkofrurasrkegiflcvbgichknvuiojdmwrrpoipizbmijrtlouuwydimadwoozamtrcjatrbvdjewcsnymjxrujrxhgniiabaemcxddugnzfrtsqfdnyxypwfvmpgorgsdkrjpmrclwwgomnublrbaqiycxeqqmkwwbflnwqatmijavfdgzehpmhtlljcxvyvwdgmbyowmximsnrzmvidjpwvchxbcxwzaenbfbyraggtvxuivelevkbxryauvwvxcibhlbbmjhfeebozfcgamhzdizxfxsdzcgjohkasrhwxinzpphpboogwpeemyjnbpwryirqzaozibazshotveautgyhgjuhytyybrodtecdgccalqugwwcrecykltujoujpmzsfewlmanmleiscewukzsvknpwbjftxflfliqxkdlwjuqmamglnagyoxwrgdkgkwlvgbuqggoqaeeatkngktgascszicfsasqivkbbqprswvvphivueeuwgoxotejvwzerjhtcwmuukrjtahnelkctyaktgtpduvwdcrhaeevqvgjvnzbajgujggfmzurtroyvfivlmsdhznfomipxolgwrllshcnysnvavrnjlrtmgadsisrzfxvylgqslftfsohqhxzvoshuskodefclexjrgbmtgfabvirffscvnjrfwhkcomqumzmudypjfpmczdjgwlbjxuqvdbxrpnmdpyxsyoddeqfdvpmtcpczkvunyuhpjvtytssthywnqdqlscfvsjweertelauuxnvqhpjonhbdlurfywcshzymqsqdumzszukhkwxzdbdqxuwxsaqzzonrigufswxssjbcfaeldhdadzyxaqwbgmtpspwkntegc";
//	vector<string> words = {"aayrpjjogyworwiszmxfacsw", "jvrsyzediytklpisgfminebs", "wxogftaubbbcdmdnwspmtajp", "nhbhbakziipcpzivtyrjpnjq", "nmxkrsuvdixmwwjfzpnzfvhp", "cjmajlzujbgizofgivyytdma", "vptxnknyssawejcsnnsbgdhm", "sfqnkcnxqljjfffkoezkbirc", "kphlelmbkinwxnnrhfhwokfw", "zdtclkhkrmotzjqrvctlbvro", "jwclywixguosoxemfizvxdui", "vxukjozrssqonjcifctmsmkt", "djroanwyfpvuzistcssidwbq", "idtwuutotwylhqtwyvfoboeb", "wsemzhezdgbvkuykhwltyqpa", "xfdecktwslkcozceklqrrvch", "bcupqelzacloiuqptwkofrur", "xgyosfkgfupunpvyahowhgds", "jhfcejjgmcizmrjgezzdlrwg", "rxbkrksgpgchndjqygttnmsn", "maihptazkjmowargifchusyb", "oyndptzlodxnndmqkplwmliv", "jwpjmgjcexftshhgmgvzkkpw", "yvabsdtdylvzmccuaygnnrgw", "xkkqkthmwhdnqnbzlzncxxxx"};
	string s = "barfoofoobarthefoobarman";
	vector<string> words = { "bar", "foo", "the" };
	res = findSubstring(s, words);
	int i = 0;
	system("Pause");
	return 0;
}


*/