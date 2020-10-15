#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	set<int> s;
	pair<priority_queue<int>, priority_queue<int, vector<int>, greater<int>>> q;
	int count = 0;

	for (auto o : operations) {
		if (o[0] == 'I') {
			int num = atoi(o.substr(2).c_str());
			q.first.push(num);
			q.second.push(num);
			count++;
		}
		else if (o == "D 1") {
			if (count) {
				q.first.pop();
				count--;
			}
		}
		else if (o == "D -1") {
			if (count) {
				q.second.pop();
				count--;
			}
		}
		if (!count) {
			while (!q.first.empty()) q.first.pop();
			while (!q.second.empty()) q.second.pop();
		}
	}
	if(!count) return vector<int>{ 0, 0 };

	for (int i = 0; i < q.first.size(); i++) {
		s.insert(q.first.top());
		q.first.pop();
	}
	for (int i = 0; i < q.second.size(); i++) {
		s.insert(q.second.top());
		q.second.pop();
	}
	for (auto i = s.begin(); i != s.end(); i++) {
		answer.push_back(*i);
	}
	return vector<int>{answer.back(), answer.front()};
}