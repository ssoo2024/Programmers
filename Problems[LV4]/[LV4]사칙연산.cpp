#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<vector<int>> M(202, vector<int>(202, -987654321));
vector<vector<int>> m(202, vector<int>(202, 987654321));

int solution(vector<string> arr) {
    int n = (arr.size() / 2) + 1; 
    
    for(int d = 1; d <= n; d++){
        int i, j;
        cout << d << " diag" << endl;
        for(i = 1, j = d; i<=n && j<=n; j++, i++){
            cout << "M[" << i << "][" << j << "]";
            if(i == j){
                M[i][j] = m[i][j] = stoi(arr[2*i-2]);
            }
            else{
                for(int k = i; k < j; k++){
                    //cout << "   M[" << i << "][" << k << "]" << " ";
                    //cout << "   M[" << k+1 << "][" << j << "]" << endl;
                    
                    if(arr[2*k-1] == "+"){
                        M[i][j] = max(M[i][j], M[i][k] + M[k + 1][j]);
                        m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j]);
                    }
                    else{
                        M[i][j] = max(M[i][j], M[i][k] - m[k + 1][j]);
                        m[i][j] = min(m[i][j], m[i][k] - M[k + 1][j]);
                    }
                }   
            }
            cout << "  " << M[i][j] << endl;
        }
    }
    return M[1][n];
}