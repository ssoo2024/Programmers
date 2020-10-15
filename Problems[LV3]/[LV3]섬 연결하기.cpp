#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

vector<vector<int>> check(101, vector<int>(101));

bool isCycle;
void dfs(int N, int root, int parent, int me) {
	for (int i = 0; i < N; i++) {
		if (check[me][i] && i != parent) {
			if (i == root) {
				isCycle = true;
				return;
			}
			dfs(N, root, me, i);
		}
		if (isCycle) return;
	}
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0, edgeNum = 0, from, to, cost;
	vector<int> isVisit(n + 1);

	sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b) { return a[2] < b[2]; });

	for (int i = 0; i < costs.size(); i++) {
		tie(from, to, cost) = tie(costs[i][0], costs[i][1], costs[i][2]);
		check[from][to] = check[to][from] = 1;

		if (isVisit[from] && isVisit[to]) {
			isCycle = false;
			dfs(n, from, from, from);
			if (isCycle) {
				check[from][to] = check[to][from] = 0;
				continue;
			}
		}
		answer += cost;
		if (++edgeNum == (n - 1)) break;
		isVisit[from] = isVisit[to] = 1;
	}
	return answer;
}