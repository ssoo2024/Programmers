#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0, max = 400000001, min = 0, mid, tmp, interval;
    
    if(k == 1) return *min_element(stones.begin(), stones.end());
    
    while(min <= max){
        mid = (min + max) / 2;
        tmp = interval = 1;
        
        for(int i = 1; i < stones.size(); i++){
            if(stones[i] - (mid-1) <= 0){
                if(stones[i - 1] - (mid-1) <= 0)
                    tmp++;
                else
                    tmp = 1;
                interval = (tmp > interval ? tmp : interval);
            }
        }
        
        if(interval < k) {
            answer = mid;
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }
    }
    return answer;
}