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
bool check(string s, vector<string> words, int base)//���뵱ǰ���ж�s�������б����ȫ��ƥ��ɹ� ����word����ȷ��˳��
//baseΪ��ǰ����
{
	int temp = base + words.size() * words[0].length();
	int wordlen = words[0].length();
	int lenth = s.length();
	int i = base;  //�����ַ���s�н��б���
	int j = 0; //����words�н��б���
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


	int wordlength = words[0].length(); //�洢��ÿ�����ʵĳ��ȶ������е��ʳ���һ��
	if (s.length() < wordlength * words.size()) return res; //���s�ĳ��ȱ�words���е����ܺͼ�������С ˵�������ڽ��
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


//ʹ�� left�� right�Ļ������ڣ���ÿһ�δε�Ƶ�ʽ���ͳ�ƣ�������ͳ�ƵĴʲ�������ôֱ��������¿�ʼ
//������ͳ�ƵĴʼ���Ƶ��֮�� ������word�еı�׼Ƶ�ʣ���ô�����ڵ���߽����ƶ���֪�����ڵ����
//��������Ҫ���Ƶ��֮��  leftֹͣ�ƶ���Ȼ��right�����ƶ�
//�����ѭ�������У���ǰ����left��right֮��ľ���պ����ˣ���ôֱ��push_back���������
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