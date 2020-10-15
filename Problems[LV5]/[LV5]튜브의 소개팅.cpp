#include <vector>
#include <queue>
#include <iostream>
#define LLMAX (1LL << 60)

using namespace std;

typedef long long ll;
typedef struct {
    int row, col;
    int dist;
    ll cost;
} T;

bool inRange(int m, int n, int row, int col){
    return (row>=0)&&(row<m)&&(col>=0)&&(col<n);
}

int dr[] = {0,1,-1,0};
int dc[] = {1,0,0,-1};

vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
    vector<vector<vector<ll>>> mincost(m+1, vector<vector<ll>>(n+1, vector<ll>(2510, LLMAX)));
    
    mincost[0][0][0] = 0LL;
    for(int d = 0; d < m*n; d++){
        for(int row = 0; row < m && row <= d; row++){
            for(int col = 0; col < n && row+col <= d; col++){
                if(time_map[row][col] == -1) continue;
                for(int dir = 0; dir < 4; dir++){
                    int next_row = row + dr[dir];
                    int next_col = col + dc[dir];
                    if(!inRange(m,n,next_row,next_col)) continue;
                    if(time_map[next_row][next_col] == -1) continue;
                    if(mincost[row][col][d] + time_map[next_row][next_col] > s) continue;
                    
                    mincost[next_row][next_col][d+1] = min(mincost[next_row][next_col][d+1], mincost[row][col][d] + (ll)time_map[next_row][next_col]);              
                }
            }
        }
    }
    
    
    for(int i = 1; i <= m*n; i++){
        if(mincost[m-1][n-1][i] <= s) 
            return {i, (int)mincost[m-1][n-1][i]};
    }
    return {0,0};
}