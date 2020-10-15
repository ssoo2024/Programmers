#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int isUsed[10];
set<vector<string>> ans;

bool mycomp(const string &s1, const string &s2){
    if(s1.size() != s2.size()) return false;
    for(int i = 0; i < s1.size(); i++){
        if(s2[i] == '*' || s1[i] == '*') continue;
        if(s1[i] != s2[i]) return false;
    }
    return true;
}

void find(vector<string> &user_id, vector<string> &banned_id, vector<string> curs, int ind){
    if(ind == banned_id.size()){
        sort(curs.begin(), curs.end());
        ans.insert(curs);
        return;
    }
    
    string src = banned_id[ind];
    auto pos = lower_bound(user_id.begin(), user_id.end(), src) - user_id.begin();
    for(int i = pos; i < user_id.size(); i++){
        if(!isUsed[i] && mycomp(user_id[i], src)){
            isUsed[i] = true;
            curs.push_back(user_id[i]);
            find(user_id, banned_id, curs, ind+1);
            curs.pop_back();
            isUsed[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<string> v;
    sort(user_id.begin(), user_id.end());
    find(user_id, banned_id, v, 0);
    return ans.size();
}