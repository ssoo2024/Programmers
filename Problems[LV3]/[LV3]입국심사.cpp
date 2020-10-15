#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer, tmp, mid, left = 0LL, right = LLONG_MAX;
    
    while(left <= right){
        mid = (left + right) / 2;
        tmp = 0LL;
        for(int i = 0; i < times.size(); i++){
            if(tmp + (mid / times[i]) < 0) tmp = LLONG_MAX;
            else tmp += (mid / times[i]);
        }
            
        
        if(tmp >= n) {
            right = mid - 1;
            answer = mid;
        }
        else left = mid + 1;
    }
    return answer;
}