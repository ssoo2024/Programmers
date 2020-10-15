#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int answer = 100000;
vector<unordered_set<string>> v(26);

void find(string &t, int pos, int cnt){
    if(cnt > answer) return;
    if(pos == t.size()){
        answer = min(answer, cnt);
        return;
    }
    for(auto vv : v[t[pos]-'a']){
        if(t.substr(pos, vv.size()) == vv){
            find(t, pos + vv.size(), cnt + 1);
        }
    }
    
    
    // for(int len = t.size() - pos; len > 0; len--){
    //     if(v[t[pos]-'a'].find(t.substr(pos, len)) != v[t[pos]-'a'].end()){
    //         find(t, pos + len, cnt + 1);
    //         break;
    //     }
    // }
    
    
    
}

int solution(vector<string> strs, string t) {
    for(auto s : strs){
        v[s[0]-'a'].insert(s);
    }
    
    for(auto vv : v[t[0]-'a']){
        find(t, vv.size(), 1);
    }
    
    return answer == 100000 ? -1 : answer;
}