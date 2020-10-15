#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

pair<int,int> gettime(string s){
    int start=0, end=0, t=0;
    end += (stoi(s.substr(11,2)) * 3600000);
    end += (stoi(s.substr(14,2)) * 60000);
    end += (stoi(s.substr(17,2)) * 1000);
    end += (stoi(s.substr(20,3)));
    t = stof(s.substr(24)) * 1000;
    start = end - t + 1;
    return {max(start,0),end};
}

int solution(vector<string> lines) {
    int answer = 0, sum = 0;
    priority_queue<pii,vector<pii>,greater<pii>> start;
    priority_queue<int,vector<int>,greater<int>> end;
        
    for(const auto &s : lines){
        start.push(gettime(s));
    } 
    
    while(!start.empty()){
        int s = start.top().first;
        int e = start.top().second;
        while(!end.empty() && (s - end.top() >= 1000)){
            --sum;
            end.pop();
        }
        ++sum;
        answer = max(answer, sum);
        end.push(e);
        start.pop();
    }

    return answer;
}