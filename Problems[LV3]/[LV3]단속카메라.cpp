#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1, pos;
    
    sort(routes.begin(), routes.end(), [](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });
    
    pos = routes[0][1];
    for(int i = 1; i < routes.size(); i++){
        if(pos < routes[i][0]){
            answer++;
            pos = routes[i][1];
        }
    }
    
    return answer;
}