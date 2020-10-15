#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    auto iter = B.begin();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for(int i = 0; i < A.size(); i++){
        iter = upper_bound(iter, B.end(), A[i]);
        if(iter != B.end()){
            answer++;
            iter++;
        }
    }
    return answer;
}