#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long answer, l, m, r, gap, tmp, remain;

long long solution(int n, vector<int> works) {
    priority_queue<long long> q;
    for(const auto w : works) q.push(w);
    
    while(!q.empty() && n){
        long long cur = q.top(); q.pop();
        cur--; n--;
        if(cur > 0) q.push(cur);
    }
    
    while(!q.empty()){
        answer += (q.top() * q.top());
        q.pop();
    }
    return answer;
}