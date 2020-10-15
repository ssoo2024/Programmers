#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

bool inRange(int R, int C, int r, int c){
    return (r>=0)&&(c>=0)&&(r<R)&&(c<C);
}

bool isPossible(vector<string> &board, int r1, int c1, int r2, int c2){
    int R = board.size();
    int C = board.front().size();
    vector<vector<int>> v(R,vector<int>(C));
    
    for(int d = 0; d < 4; d++){
        int row = r1 + dr[d];
        int col = c1 + dc[d];
        if(row == r2 && col == c2) return true;
        while(inRange(R,C,row,col) && board[row][col] == '.'){
            v[row][col] = 1;
            row += dr[d];
            col += dc[d];
        }
    }
    
    for(int d = 0; d < 4; d++){
        int row = r2 + dr[d];
        int col = c2 + dc[d];
        while(inRange(R,C,row,col) && board[row][col] == '.'){
            if(v[row][col]) return true;
            v[row][col] = 1;
            row += dr[d];
            col += dc[d];
        }
    }
    
    return false;
}

string solution(int m, int n, vector<string> board) {
    string answer = "";
    vector<vector<pair<int, int>>> point(26);
    set<char> s;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if('A' <= board[i][j] && board[i][j] <= 'Z'){
                point[board[i][j] - 'A'].push_back({i,j});
                s.insert(board[i][j] - 'A');
            }
        }
    }
    
    
    bool changed = true;
    while(changed){
        changed = false;
        for(auto alpha : s){
            int r1 = point[alpha][0].first;
            int c1 = point[alpha][0].second;
            int r2 = point[alpha][1].first;
            int c2 = point[alpha][1].second;            
            if(isPossible(board,r1,c1,r2,c2)){
                changed = true;
                s.erase(alpha);
                answer += (alpha+'A');
                board[r1][c1] = '.';
                board[r2][c2] = '.';
                break;
            }
        }
    }    
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] != '.' && board[i][j] != '*') return "IMPOSSIBLE";
        }
    }
    
    return answer == "" ? "IMPOSSIBLE" : answer;
}