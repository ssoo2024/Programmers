#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
    int s, e, left = 0, right = gems.size();
    unordered_map<string, int> m;
    unordered_set<string> us;
    
    for(auto g : gems) us.insert(g);
    
    for(e = s = 0; e < gems.size(); e++){
        if((m.size() == us.size()) && (e - s < right - left)){
            left = s;
            right = e;
        }
        auto ret = m.insert({gems[e], 1});
        if(!ret.second) ret.first->second++;
        for(; m[gems[s]] > 1; s++) m[gems[s]]--;
    }
    
    return vector<int>{left + 1, right};
}