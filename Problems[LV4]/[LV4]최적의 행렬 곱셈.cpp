#include <string>
#include <vector>

using namespace std;
typedef long long ll;

vector<vector<ll>> m(201, vector<ll>(201, (1LL << 60)));

int solution(vector<vector<int>> matrix_sizes) {
    int i, j, n = matrix_sizes.size();
    
    for(int d = 0; d < n; d++){
        for(i = 0, j = d; i<n && j<n; j++, i++){
            if(i == j){
                m[i][j] = 0;
            }
            else{
                for(int k = i; k < j; k++){
                    m[i][j] = min(
                        m[i][j], 
                        m[i][k]+m[k+1][j]+
                        (matrix_sizes[i][0]*matrix_sizes[k][1]*matrix_sizes[j][1])
                    );
                }   
            }
            
        }
    }    
    return m[0][n-1];
}