#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#define INF 2100000000
using namespace std;
typedef pair<int,pair<int,int>> T;


int isVisit[310][310], area[310][310], root[100000], family[100000];
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

int find(int x){
    return x==root[x] ? x : root[x]=find(root[x]);
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0, n = land.size(), cnt = 0;
    priority_queue<T,vector<T>,greater<T>> pq;
    
    // 영역 구분
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!isVisit[i][j]){
                isVisit[i][j] = 1;
                area[i][j] = ++cnt;
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    int row = q.front().first;
                    int col = q.front().second;
                    for(int d = 0; d < 4; d++){
                        int tr = row + dr[d];
                        int tc = col + dc[d];
                        if(tr<0 || tc<0 || tr>=n || tc>=n) continue;
                        int diff = abs(land[row][col]-land[tr][tc]);
                        if(!isVisit[tr][tc] && diff <= height) {
                            isVisit[tr][tc] = 1;
                            area[tr][tc] = cnt;
                            q.push({tr,tc});                                
                        }
                        else if(isVisit[tr][tc] && area[row][col] != area[tr][tc]){
                            pq.push({diff, {area[row][col], area[tr][tc]}});
                        }
                    }
                    q.pop();
                }
                
            }
        }
    }
    
    // MST
    for(int i = 1; i <= cnt; i++){
        root[i] = i;
        family[i] = 1;
    }
    
    int size = 1;
    while(size < cnt){
        int cost = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        int A = find(a);
        int B = find(b);
        if(A != B){
            if(family[A] > family[B]) swap(A, B);
            family[B] += family[A];
            root[A] = B;
            answer += cost;
            ++size;
        }
        pq.pop();
    }
    
    return answer;
}