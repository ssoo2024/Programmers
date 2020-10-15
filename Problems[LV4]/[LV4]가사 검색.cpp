#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef struct Tri{
    int cnt = 0;
    Tri* next[26];
} Tri;

Tri* t[10010];
Tri* rt[10010];

void insert(Tri* root, string &s, int ind){
    if(ind == s.size()) return;
    root->cnt++;
    if(root->next[s[ind] - 'a'] == NULL)
        root->next[s[ind] - 'a'] = new Tri();
    insert(root->next[s[ind] - 'a'], s, ind + 1);
}

void rinsert(Tri* root, string &s, int ind){
    if(ind < 0) return;
    root->cnt++;
    if(root->next[s[ind] - 'a'] == NULL)
        root->next[s[ind] - 'a'] = new Tri();
    rinsert(root->next[s[ind] - 'a'], s, ind - 1);
}

int find(Tri* root, string &s, int ind){
    if(ind == s.size()) return 1;
    if(s[ind] == '?') return root->cnt;
    if(root->next == NULL) return 0;
    if(root->next[s[ind] - 'a'] == NULL) return 0;
    return find(root->next[s[ind] - 'a'], s, ind + 1);
}

int rfind(Tri* root, string &s, int ind){
    if(ind < 0) return 1;
    if(s[ind] == '?') return root->cnt;
    if(root->next == NULL) return 0;
    if(root->next[s[ind] - 'a'] == NULL) return 0;
    return rfind(root->next[s[ind] - 'a'], s, ind - 1);
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    for(string w : words){
        if(t[(int)w.size()] == NULL) t[(int)w.size()] = new Tri();
        if(rt[(int)w.size()] == NULL) rt[(int)w.size()] = new Tri();
        
        insert(t[(int)w.size()], w, 0);
        rinsert(rt[(int)w.size()], w, w.size() - 1);
    }
    
    for(string q : queries){
        if(t[q.size()] == NULL) answer.push_back(0);
        
        else if(q.front() == '?'){
            answer.push_back(rfind(rt[(int)q.size()], q, q.size() - 1));
        }
        else{
            answer.push_back(find(t[(int)q.size()], q, 0));   
        }
    }
    return answer;
}