#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0, max = 0;
	vector<vector<int>> check(n + 1, vector<int>(n + 1));
	vector<int> isVisit(n + 1);
	queue<pair<int, int>> q;
	pair<int, int> cur;

	for (int i = 0; i < edge.size(); i++) {
		check[edge[i][0]][edge[i][1]] = 1;
		check[edge[i][1]][edge[i][0]] = 1;
	}
	q.push(make_pair(1, 0));
	isVisit[1] = 1;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		if (cur.second > max) {
			max = cur.second;
			answer = 0;
		}
		if(cur.second == max) answer++;
		
		for (int i = 1; i <= n; i++) {
			if (check[cur.first][i] && !isVisit[i]) {
				q.push(make_pair(i, cur.second + 1));
				check[cur.first][i] = 0;
				isVisit[i] = 1;
			}
		}

	}
	return answer;
}