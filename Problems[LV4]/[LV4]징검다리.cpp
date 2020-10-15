#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int cnt, mid, answer = 0, left = 1, right = 1000000000;
    bool chk = false;
    sort(rocks.begin(), rocks.end());
    
    while(left <= right){
        deque<int> deq(rocks.begin(), rocks.end());
        deq.push_front(0);
        deq.push_back(distance);
        
        mid = (left + right) / 2;
        chk = cnt = 0;
        
        for(int i = 1; i < deq.size(); i++){
            if(deq[i] - deq[i - 1] < mid){
                deq.erase(deq.begin() + i);
                i--;
                cnt++;
            }
        }
        
        cnt <= n ? (left = mid + 1, chk = true) : (right = mid - 1);
    }
    
    return chk ? mid : mid - 1;
}