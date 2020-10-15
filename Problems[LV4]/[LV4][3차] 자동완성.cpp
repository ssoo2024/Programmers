#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef struct Tri{
    int cnt = 0;
    Tri* next[26];        
} Tri;

void insert(Tri* root, string &s, int ind){
    if(ind == s.size()) return;    
    if(root->next[s[ind]-'a'] == NULL){
        root->next[s[ind]-'a'] = new Tri();
    }
    root->next[s[ind]-'a']->cnt++;
    insert(root->next[s[ind]-'a'], s, ind + 1);
}

int remain(Tri* root, string &s, int ind){
    if(ind == s.size()) return 0;    
    if(ind == s.size() || root->cnt == 1) return 0;
    return remain(root->next[s[ind]-'a'], s, ind + 1) + 1;
}

int solution(vector<string> words) {
    int answer = 0;
    Tri* root = new Tri();
    
    for(auto w : words) {insert(root, w, 0);}
    for(auto w : words) {answer += remain(root, w, 0);}
    
    return answer;
}