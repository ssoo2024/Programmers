#include <iostream>
#include <vector>
using namespace std;

int dp[2][100001];

int solution(vector<int> sticker) {
    int n=sticker.size();
    
    dp[0][0] = 0;
    dp[1][0] = sticker[0];
    if(n > 1){
        dp[0][1] = sticker[1];
        dp[1][1] = dp[1][0];
        for(int i = 2; i < n - 1; i++){
            dp[1][i] = max(dp[1][i-1], dp[1][i-2]+sticker[i]);
            dp[0][i] = max(dp[0][i-1], dp[0][i-2]+sticker[i]);
        } 
        dp[1][n - 1] = dp[1][n - 2];
        dp[0][n - 1] = max(dp[0][n - 2], dp[0][n - 3]+sticker[n-1]);
    }
    
    return max(dp[1][n-1], dp[0][n-1]);
}