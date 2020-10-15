#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(triangle);
    
    for(int i = 1; i < dp.size(); i++){
        dp[i - 1].push_back(0);
        for(int j = 0; j < dp[i].size(); j++){
            dp[i][j] = max(dp[i-1][max(j-1,0)], dp[i-1][j]) + triangle[i][j];
            answer = max(answer, dp[i][j]);
        }
    }
    
    return answer;
}