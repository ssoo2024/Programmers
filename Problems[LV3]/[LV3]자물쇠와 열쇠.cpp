#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> lotate_cw(vector<vector<int>> mat){
    int n = mat.size();
    vector<vector<int>> res(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res[i][j] = mat[n - j - 1][i];
        }
    }
    return res;
}

bool in_range(int row, int col, int n){
    return (row>=0)&&(row<n)&&(col>=0)&&(col<n);
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key.size();
    int N = lock.size();
    int empty_num = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            empty_num += (!lock[i][j]);
        }
    }
    
    if(empty_num == 0) return true;
    
    // 회전
    for(int lotate = 1; lotate <= 4; lotate++){
        
        // 이동
        for(int row = -M + 1; row < N; row++){
            for(int col = -M + 1; col < N; col++){
                
                // 끼워맞춰보기
                int cnt = 0;
                for(int i = 0; i < M; i++){
                    for(int j = 0; j < M; j++){
                        if(in_range(row+i, col+j, N)){
                            cnt += (key[i][j] && !lock[row+i][col+j]);
                            cnt -= (key[i][j] && lock[row+i][col+j]);
                        }
                    }
                }
                if(cnt == empty_num) return true;   
                
            }
        }
        
        key = lotate_cw(key); 
    }
    
	return false;
}