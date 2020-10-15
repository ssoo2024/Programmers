#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> cores) {
    int left = *min_element(cores.begin(),cores.end()) * (n-cores.size()) / cores.size();
    int right = *max_element(cores.begin(),cores.end()) * (n-cores.size()) / cores.size();
    int mid, newalloc, alloced;
    
    if(n <= cores.size()) return n;
    
    while(left <= right){
        mid = (left + right) / 2;
        newalloc = alloced = 0;
        for(auto core : cores){\
            alloced += ((mid / core) + !(mid % core == 0));
            newalloc += (mid % core == 0);
        }
              
        if(alloced + newalloc < n){
            left = mid + 1;
        }
        else if(n <= alloced){
            right = mid - 1;
        }
        else{
            for(int i = 0; i < cores.size(); i++){
                alloced += (mid % cores[i] == 0);
                if(alloced == n) return i+1;
            }
        }
    }
    return -1;
}