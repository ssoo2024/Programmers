#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0, n = money.size();
    
    vector<int> v0(n), v1(n);
    
    v0[1] = money[1];
    v1[0] = v1[1] = money[0];
    
    for(int i = 2; i < n - 1; i++){
        v0[i] = max(v0[i - 1], v0[i - 2] + money[i]);
        v1[i] = max(v1[i - 1], v1[i - 2] + money[i]);
    }
    v0[n - 1] = max(v0[n - 2], v0[n - 3] + money[n - 1]);
    v1[n - 1] = v1[n - 2];
    
    return max(v0[n - 1], v1[n - 1]);
}