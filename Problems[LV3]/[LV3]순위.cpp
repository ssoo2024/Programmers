#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> results) {
	vector<vector<int>> res(n + 1, vector<int>(n + 1));
	vector<pair<int, int>> score(n + 1);
	queue<int> q;
	int answer = 0;
	for (int i = 0; i < results.size(); i++) {
		res[results[i][0]][results[i][1]] = 1;
	}
	for (int i = 1; i <= n; i++) {
		vector<int> isVisit(n + 1);
		q.push(i);
		while (!q.empty()) {
			for (int j = 1; j <= n; j++) {
				if (res[q.front()][j] && !isVisit[j]) {
					q.push(j);
					isVisit[j] = 1;
					score[i].first++;
					score[j].second++;
				}
			}
			q.pop();
		}
	}
	for (int i = 1; i <= n; i++) {
		if (score[i].first + score[i].second == n - 1) answer++;
	}
	return answer;
}