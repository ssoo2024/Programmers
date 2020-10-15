#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int solution(vector<vector<int>> jobs) {
	int answer = 0, t = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q, start_q;

	for (int i = 0; i < jobs.size(); i++) 
		q.push({ jobs[i][1], jobs[i][0] });

	while (!q.empty()) {
		while (!q.empty() && q.top().second > t) {
			start_q.push({ q.top().second, q.top().first });
			q.pop();
		}
		if (q.empty()) {
			answer += start_q.top().second;
			t = (start_q.top().first + start_q.top().second);
			start_q.pop();
		}
		else {
			answer += (t - q.top().second + q.top().first);
			t += q.top().first;
			q.pop();
		}
		while (!start_q.empty()) {
			q.push({ start_q.top().second, start_q.top().first });
            start_q.pop();
		}
	}
	return answer / jobs.size();
}