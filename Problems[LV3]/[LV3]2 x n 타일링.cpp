#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long dp[60001];
    dp[1] = 1LL;
    dp[2] = 2LL;
    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007LL;
    }
    return dp[n];
}