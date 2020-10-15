#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int gettime(string s){
    return stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
}

string gettime(int t){
    string hour = t/60<10 ? "0"+to_string(t/60) : to_string(t/60);
    string min = t%60<10 ? "0"+to_string(t%60) : to_string(t%60);
    return hour + ":" + min;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    vector<int> v;
    for(auto s : timetable){
        v.push_back(gettime(s));
    }
    sort(v.begin(), v.end());
    
    vector<vector<int>> picked(3000);
    for(int cur=540, pos=0; n && cur < 1440; cur+=t, n--){
        while(pos<timetable.size() && v[pos]<=cur && picked[cur].size()<m){
            picked[cur].push_back(v[pos++]);
        }
        if(n == 1){
            if(picked[cur].size() == m){
                answer = gettime(picked[cur].back()-1);
            }
            else{
                answer = gettime(cur);
            }
        }
    }
    
    return answer;
}