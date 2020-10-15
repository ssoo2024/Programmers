#include <vector>
#include <iostream>
using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
	vector<vector<int>> pass(m + 1, vector<int>(n + 1));

	for (int i = 2; i <= n; i++) {
		if (city_map[0][i - 1] == 1) break;
		pass[1][i] = 1;
	}
	for (int i = 2; i <= m; i++) {
		if (city_map[i - 1][0] == 1) break;
		pass[i][1] = 1;
	}
	for (int i = 2; i <= m; i++) {
		for (int j = 2; j <= n; j++) {
			if (city_map[i - 1][j - 1] != 1) {
				// 위
				if (city_map[i - 2][j - 1] == 0) pass[i][j] += pass[i - 1][j];
				else if (city_map[i - 2][j - 1] == 2) {
					for (int k = i - 2; k >= 0; k--) {
						if (city_map[k][j - 1] != 2) {
							pass[i][j] += pass[k + 1][j];
                            break;
						}
					}
				}
				// 왼쪽
				if (city_map[i - 1][j - 2] == 0) pass[i][j] += pass[i][j - 1];
				else if (city_map[i - 1][j - 2] == 2) {
					for (int k = j - 2; k >= 0; k--) {
						if (city_map[i - 1][k] != 2) {
							pass[i][j] += pass[i][k + 1];
                            break;
						}
					}
				}
                pass[i][j] %= MOD;
			}
		} 
	}
	return pass[m][n];
}