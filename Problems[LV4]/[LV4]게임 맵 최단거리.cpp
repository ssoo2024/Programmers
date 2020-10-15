#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef struct {int row, col, dist;} T;
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

int solution(vector<vector<int>> maps){
    int n = maps.size(), m = maps.front().size();
    vector<vector<int>> mindist(n,vector<int>(m,987654321));
    queue<T> q; q.push({0,0,1});
    
    while(!q.empty()){
        for(int d = 0; d < 4; d++){
            int row = q.front().row + dr[d];
            int col = q.front().col + dc[d];
            int dist = q.front().dist + 1;
            if((row>=0&&col>=0&&row<n&&col<m) && maps[row][col] && dist < mindist[row][col]){
                mindist[row][col] = dist;
                q.push({row,col,dist});
            }
        }
        q.pop();
    }
    return mindist[n-1][m-1] == 987654321 ? -1 : mindist[n-1][m-1];
}