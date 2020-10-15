#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>
#define INF 100000
#define RIGHT 0
#define DOWN 1
using namespace std;

typedef struct{
    int row, col; // 축
    int dir; // 0:오른쪽, 1:아래
    int cost; // 현재까지 이동거리
} Robot;

int dp[102][102][2]; //dp[i][j][k] i,j에서 (0:오른쪽,1:아래)로 위치할때의 최소 이동거리

int solution(vector<vector<int>> board) {
    int r,c,d,cost, N = board.size();
    fill(dp[0][0], dp[101][0], INF);
    dp[1][1][RIGHT] = 0;
    
    vector<vector<int>> v(N+2, vector<int>(N+2,1));
    for(int i = 1; i <= N; i++){
        copy(board[i-1].begin(),board[i-1].end(),v[i].begin()+1);
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << v[i][j] << " ";
        } cout << endl;
    } cout << endl;
    
    queue<Robot> q; 
    q.push({1,1,RIGHT,0});
    while(!q.empty()){
        Robot cur = q.front(); q.pop();
        tie(r,c,d,cost) = make_tuple(cur.row, cur.col, cur.dir, cur.cost+1);
        //cout << r << "," << c << "  " << (d==0?"RIGHT":"DOWN") << " cost:" << cost-1 << endl;
        if(d == RIGHT){ // 가로방향
            if(!v[r-1][c] && !v[r-1][c+1]){ // 위가 비었을 때
                if(cost < dp[r-1][c][RIGHT]){ // 위로 이동
                    dp[r-1][c][RIGHT] = cost;
                    q.push({r-1,c,RIGHT,cost});
                }
                if(cost < dp[r-1][c][DOWN]){ // 좌축 반시계
                    dp[r-1][c][DOWN] = cost;
                    q.push({r-1,c,DOWN,cost});
                }
                if(cost < dp[r-1][c+1][DOWN]){ // 우축 시계
                    dp[r-1][c+1][DOWN] = cost;
                    q.push({r-1,c+1,DOWN,cost});
                }
            }
            if(!v[r+1][c] && !v[r+1][c+1]){ // 아래가 비었을 때
                if(cost < dp[r+1][c][RIGHT]){ // 아래로 이동
                    dp[r+1][c][RIGHT] = cost;
                    q.push({r+1,c,RIGHT,cost});
                }
                if(cost < dp[r][c][DOWN]){ // 좌축 시계
                    dp[r][c][DOWN] = cost;
                    q.push({r,c,DOWN,cost});
                }
                if(cost < dp[r][c+1][DOWN]){ // 우축 반시계
                    dp[r][c+1][DOWN] = cost;
                    q.push({r,c+1,DOWN,cost});
                }
            }
            if(!v[r][c+2]){ // 오른쪽이 비었을때
                if(cost < dp[r][c+1][RIGHT]){
                    dp[r][c+1][RIGHT] = cost;
                    q.push({r,c+1,RIGHT,cost});
                }
            }
            if(!v[r][c-1]){ // 왼쪽이 비었을때
                if(cost < dp[r][c-1][RIGHT]){
                    dp[r][c-1][RIGHT] = cost;
                    q.push({r,c-1,RIGHT,cost});
                }
            }
        }
        else{ // 세로 방향
            if(!v[r][c-1] && !v[r+1][c-1]){ // 왼쪽이 비었을때
                if(cost < dp[r][c-1][DOWN]){ // 왼쪽 이동
                    dp[r][c-1][DOWN] = cost;
                    q.push({r,c-1,DOWN,cost});
                }
                if(cost < dp[r][c-1][RIGHT]){ // 위축 시계
                    dp[r][c-1][RIGHT] = cost;
                    q.push({r,c-1,RIGHT,cost});
                }
                if(cost < dp[r+1][c-1][RIGHT]){ // 아래축 반시계
                    dp[r+1][c-1][RIGHT] = cost;
                    q.push({r+1,c-1,RIGHT,cost});
                }
            }
            if(!v[r][c+1] && !v[r+1][c+1]){ // 오른쪽이 비었을때
                if(cost < dp[r][c+1][DOWN]){ // 오른쪽 이동
                    dp[r][c+1][DOWN] = cost;
                    q.push({r,c+1,DOWN,cost});
                }
                if(cost < dp[r][c][RIGHT]){ // 위축 반시계
                    dp[r][c][RIGHT] = cost;
                    q.push({r,c,RIGHT,cost});
                }
                if(cost < dp[r+1][c][RIGHT]){ // 아래축 시계
                    dp[r+1][c][RIGHT] = cost;
                    q.push({r+1,c,RIGHT,cost});
                }
            }
            if(!v[r-1][c]){ // 위가 비었을때
                if(cost < dp[r-1][c][DOWN]){
                    dp[r-1][c][DOWN] = cost;
                    q.push({r-1,c,DOWN,cost});
                }
            }
            if(!v[r+2][c]){ // 아래가 비었을때
                if(cost < dp[r+1][c][DOWN]){
                    dp[r+1][c][DOWN] = cost;
                    q.push({r+1,c,DOWN,cost});
                }
            }
        }
    }
    
    //cout << dp[N-1][N][DOWN] << " " << dp[N][N-1][RIGHT] << endl;
    return min(dp[N-1][N][DOWN],dp[N][N-1][RIGHT]);
}