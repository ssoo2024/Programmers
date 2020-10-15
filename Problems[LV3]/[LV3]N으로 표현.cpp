// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int solution(int N, int number) {
    vector<unordered_set<int>> dp(9);
    vector<int> nums(9);
    for(int i = 1; i <= 8; i++){
        nums[i] = stoi(string(i, N+'0').substr(0,i));
        dp[i].insert(nums[i]);
    }
    for(int i = 1; i <= 8; i++){
        for(auto e : dp[i - 1]){
            if(e == number) return i - 1;
            dp[i].insert(e + N);
            dp[i].insert(e - N);
            dp[i].insert(e * N);
            dp[i].insert(e * (-N));
            dp[i].insert(e / N);
            dp[i].insert(e / (-N));
            for(int k = 2; k + i - 1 <= 8; k++){
                dp[k + i - 1].insert(e + nums[k]);
                dp[k + i - 1].insert(e - nums[k]);
                dp[k + i - 1].insert(e * nums[k]);
                dp[k + i - 1].insert(e / nums[k]);
            }
        }
    }
    for(auto e : dp[8]) if(e == number) return 8;
    return -1;
}