#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s < n) answer.push_back(-1);
    else{
        for(int i = 0; i < n; i++){
            if(i >= n - (s % n)) answer.push_back((s / n) + 1);
            else answer.push_back(s / n);
        }
    }
    return answer;
}