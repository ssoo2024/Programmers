#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<int> isVisit(n);
    int answer = 0;
    
    for(int from = 0; from < n; from++){
        if(!isVisit[from]){
            isVisit[from] = 1;
            queue<int> q;
            q.push(from);
            while(!q.empty()){
                for(int to = 0; to < n; to++){
                    if(!isVisit[to] && computers[q.front()][to]){
                        isVisit[to] = 1;
                        q.push(to);
                    }
                }
                q.pop();
            }
            answer++;
        }
    }
	return answer;
}