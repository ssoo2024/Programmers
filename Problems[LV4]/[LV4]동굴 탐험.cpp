#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> biedge[200001], edge[200001], isVisit(200001);

void makeDirect(int cur){
    isVisit[cur] = 1;
    for(const auto &next : biedge[cur]){
        if(!isVisit[next]){
            edge[cur].push_back(next);
            makeDirect(next);
        }
    }
}

bool dfs(int cur){
    for(const auto &next : edge[cur]){
        if(isVisit[next]) 
            return false;
        else {
            isVisit[next] = 1;
            if(!dfs(next)) 
                return false;
            isVisit[next] = 0;
        }
    }
    //isVisit[cur] = 1;
    return true;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;

    for(const auto &e : path){
        biedge[e[0]].push_back(e[1]);
        biedge[e[1]].push_back(e[0]);
    }
    for(const auto &e : order){
        edge[e[0]].push_back(e[1]);
    }
    
    makeDirect(0);
    isVisit[0] = 1;
    fill(isVisit.begin(), isVisit.end(), 0);
    
    return dfs(0);
}