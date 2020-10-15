#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	int pos, num;
	vector<int> answer;
	map<string, pair<int, priority_queue<int>>> q;
	map<int, pair<string, priority_queue<int>>, greater<int>> m;
	
	for (int i = 0; i < genres.size(); i++) {
		priority_queue<int> tmp;
		tmp.push(plays[i]);
		auto res = q.insert(make_pair(genres[i], make_pair(plays[i], tmp)));
		if (!res.second) {
			res.first->second.first += plays[i];
			res.first->second.second.push(plays[i]);
		}
	}
	for (auto it = q.begin(); it != q.end(); it++) {
		m.insert(make_pair(it->second.first, make_pair(it->first, it->second.second)));
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		num = min(2, (int)it->second.second.size());
		for (int i = 0; i < num; i++) {
			pos = find(plays.begin(), plays.end(), it->second.second.top()) - plays.begin();
			answer.push_back(pos);
			it->second.second.pop();
			plays[pos] = 0;
		}
	}
	return answer;
}