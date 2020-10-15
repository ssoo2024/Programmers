#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#define PD (1 << 0)
#define PU (1 << 1)
#define SL (1 << 2)
#define SR (1 << 3)
using namespace std;

int N, s[110][110];

bool canMakePillar(int x, int y){
    return (!y) || (s[x][y] & (SL|SR|PU)); 
}
bool canMakeStick(int x, int y){
    return (((s[x][y] & SR) && (s[x+1][y] & SL)) ||
        (s[x][y] & PU) || (s[x+1][y] & PU));
}
bool canDeletePillar(int x, int y){
    bool checkU = !(s[x][y+1] & PD) || (s[x][y+1] & ~(PU|PD));
    bool checkR = !(s[x][y+1] & SL) || (s[x+1][y+1] & PU) 
        || ((s[x][y+1] & SR) && (s[x+1][y+1] & SL));
    bool checkL = (!x) || !(s[x][y+1] & SR) 
        || (s[x-1][y+1] & PU) 
        || ((s[x][y+1] & SL) && (s[x-1][y+1] & SR));
    return checkU && checkR && checkL;
}
bool canDeleteStick(int x, int y){
    bool checkLU = !(s[x][y] & PD) || (s[x][y] & ~(SL|PD));
    bool checkRU = !(s[x+1][y] & PD) || (s[x+1][y] & ~(SR|PD));
    bool checkL = !x || !(s[x][y] & SR) || 
        (s[x][y] & PU) || (s[x-1][y] & PU);
    bool checkR = (x==N-1) || !(s[x+1][y] & SL) ||
        (s[x+1][y] & PU) || (s[x+2][y] & PU);
    return checkLU && checkRU && checkL && checkR;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    int x,y,a,b; N=n;
    for(const auto &order : build_frame){
        tie(x,y,a,b) = make_tuple(order[0],order[1],order[2],order[3]);
        //cout << x << "," << y << "에 ";
        if(a && b && canMakeStick(x,y)){ /*보 설치*/ //cout << "보 설치";
            s[x][y] |= SL;
            s[x+1][y] |= SR;
        }
        if(a && !b && canDeleteStick(x,y)){ /*보 삭제*/ //cout << "보 삭제";
            s[x][y] &= ~SL;
            s[x+1][y] &= ~SR;
        }
        if(!a && b && canMakePillar(x,y)){ /*기둥 설치*/ //cout << "기둥 설치";
            s[x][y] |= PD;
            s[x][y+1] |= PU;
        }
        if(!a && !b && canDeletePillar(x,y)){ /*기둥 삭제*/ //cout << "기둥 삭제";
            s[x][y] &= ~PD;
            s[x][y+1] &= ~PU;
        }
        //cout << endl;
    }
    
    for(x = 0; x <= n; x++){
        for(y = 0; y <= n; y++){
            if(s[x][y] & PD) answer.push_back({x,y,0}); 
            if(s[x][y] & SL) answer.push_back({x,y,1}); 
        }
    }
    
    return answer;
}