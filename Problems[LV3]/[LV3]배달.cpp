#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<pair<int, int>>> from(51);
	vector<int> dist(51, INT32_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	for (int i = 0; i < road.size(); i++) {
		from[road[i][0]].push_back({ road[i][1], road[i][2] });
        from[road[i][1]].push_back({ road[i][0], road[i][2] });
	}

	q.push({ (dist[1] = 0), 1 });

	while (!q.empty()) {
		for (auto to : from[q.top().second]) {
			if (dist[to.first] > q.top().first + to.second) {
				dist[to.first] = min(dist[to.first], q.top().first + to.second);
				q.push({ dist[to.first] ,  to.first });
			}
		}
		q.pop();
	}

    for(int i = 1; i <= N; i++)
        answer += (dist[i] <= K);
    
    return answer;
}