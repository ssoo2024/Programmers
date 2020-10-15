#include <string>
#include <vector>
#include <iostream>
using namespace std;

int top(vector<vector<int>> &b, int col){
    int row, n = b.size();
    for(row = 0; row < n; row++){
        if(b[row][col]) return row;
    }
    return n - 1;
}

int checkBlock(vector<vector<int>> &b, int r, int c){
    if(!b[r][c]) return 0;
    int n = b.size();
    if(r < n - 1 && c < n - 2){
        if(b[r][c]==b[r+1][c] && b[r][c]==b[r+1][c+1] && b[r][c]==b[r+1][c+2]){
            return 1;
        }
    }
    if(r > 1 && c < n - 1){
        if(b[r][c]==b[r][c+1] && b[r][c]==b[r-1][c+1] && b[r][c]==b[r-2][c+1]){
            return 2;
        }
    }
    if(r < n - 2 && c < n - 1){
        if(b[r][c]==b[r+1][c] && b[r][c]==b[r+2][c] && b[r][c]==b[r+2][c+1]){
            return 3;
        }
    }
    if(r > 0 && c < n - 2){
        if(b[r][c]==b[r][c+1] && b[r][c]==b[r][c+2] && b[r][c]==b[r-1][c+2]){
            return 4;
        }
    }
    if(r > 0 && c < n - 2){
        if(b[r][c]==b[r][c+1] && b[r][c]==b[r][c+2] && b[r][c]==b[r-1][c+1]){
            return 5;
        }
    }
    return 0;
}

int remove(vector<vector<int>> &b, int r, int c, int shape){
    switch(shape){
        case 1:
            b[r][c]=b[r+1][c]=b[r+1][c+1]=b[r+1][c+2]=0;
            break;
        case 2:
            b[r][c]=b[r][c+1]=b[r-1][c+1]=b[r-2][c+1]=0;
            break;
        case 3:
            b[r][c]=b[r+1][c]=b[r+2][c]=b[r+2][c+1]=0;
            break;
        case 4:
            b[r][c]=b[r][c+1]=b[r][c+2]=b[r-1][c+2]=0;
            break;
        case 5:
            b[r][c]=b[r][c+1]=b[r][c+2]=b[r-1][c+1]=0;
            break;
    }
    return 1;
}

int solution(vector<vector<int>> board) {
    int del, answer = 0, n = board.size();    
    do{
        del = 0;
        for(int col = 0; col < n; col++){
            int row = top(board, col);
            int shape = checkBlock(board, row, col);
            
            if(shape == 1 && top(board,col+1)==row+1 && top(board,col+2)==row+1){
                del += remove(board, row, col, shape);
            }
                
            else if(shape == 2){
                del += remove(board, row, col, shape);
            }
            
            else if(shape == 3 && top(board,col+1)==row+2){
                del += remove(board, row, col, shape);
            }
            
            else if(shape == 4 && top(board,col+1)==row){
                del += remove(board, row, col, shape);
            }
                
            else if(shape == 5 && top(board,col+2)==row){
                del += remove(board, row, col, shape);
            }
        }
        
        answer += del;
    }while(del);
    
    return answer;
}