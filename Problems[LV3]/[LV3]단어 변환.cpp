#include <string>
#include <vector>
#include <queue>
using namespace std;
int answer = 100;

void find(string begin, string target, vector<pair<string, int>> words, int count) {
	queue<string> check;
	string cur;
	int diff;
	if (begin == target) {
		answer = count < answer ? count : answer;
		return;
	}
	for (int i = 0; i < words.size(); i++) {
		diff = 0;
		for (int j = 0; j < words[i].first.size(); j++) {
			if (begin[j] != words[i].first[j]) diff++;
			if (diff > 1) break;
		}
		if (diff == 1 && words[i].second) {
			check.push(words[i].first);
			words[i].second = 0;
		}
	}
	while (!check.empty()) {
		cur = check.front();
		check.pop();
		find(cur, target, words, count + 1);
	}
}
int solution(string begin, string target, vector<string> w) {
	vector<pair<string, int>> words;
	int no_target = 1;
	
	for (int i = 0; i < w.size(); i++) {
		if (w[i] == target) no_target = 0;
		words.push_back(pair<string, int>(w[i], 1));
	} 
	if (no_target) return 0;

	find(begin, target, words, 0);

	if (answer == 100) return 0;
	return answer;
}