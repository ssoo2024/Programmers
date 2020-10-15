#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> money) {
	vector<vector<int>> charge(money.size() + 1, vector<int>(n + 1));

	for (int row = 1; row <= money.size(); row++) {
		for (int col = 1; col <= n; col++) {
			if (col < money[row - 1]) 
                charge[row][col] = charge[row - 1][col];
			else if (col == money[row - 1]) 
                charge[row][col] = charge[row - 1][col] + 1;
			else 
                charge[row][col] += (charge[row][col - money[row - 1]] + charge[row - 1][col]);
		}
	}
	return charge[money.size()][n];
}