#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int use[1321];

int solution(int n, int m, vector<vector<int>> timetable) {
    int answer = 0, cnt = 0;
    
    for(const auto &t : timetable){
        for(int i = t[0]; i <= t[1]; i++){
            use[i]++;
            cnt = max(use[i], cnt);
        }
    }
    
    cout << cnt << endl;
    
    return answer;
}