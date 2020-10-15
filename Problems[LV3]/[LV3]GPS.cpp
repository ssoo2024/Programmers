#include <vector>
#include <algorithm>
using namespace std;

int g[201][201];

int dfs(int n, int pos, vector<int> &gps_log) {
	if (pos == 1) {
		return g[gps_log[pos]][1] ? 0 : 1000;
	}

	int ans = 1000;

	for (int i = pos; i > 0; i--) {
        if(i == 1) return g[gps_log[i]][gps_log[0]] ? 0 : 1000;
        else{
            if (!g[gps_log[i]][gps_log[i - 1]]) {
                for (int j = 1; j <= n; j++) {
                    if (g[gps_log[i]][j]) {
                        int tmp = gps_log[i - 1];
                        gps_log[i - 1] = j;
                        ans = min(ans, dfs(n, i - 1, gps_log) + 1);
                        if (ans == 1) return 1;
                        gps_log[i - 1] = tmp;
                    }
                }
                return ans;
            }            
        }

	}
	return 0;
}

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	int answer = 0;
	for (auto e : edge_list) 
		g[e[0]][e[1]] = g[e[1]][e[0]] = 1;
	
	answer = dfs(n, k - 1, gps_log);

	return answer >= 1000 ? -1 : answer;
}