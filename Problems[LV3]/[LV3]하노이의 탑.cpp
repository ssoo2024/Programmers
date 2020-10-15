#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int from, int by, int to){
    if(!n) return;
    hanoi(n - 1, from, to, by);
    answer.push_back(vector<int>{from,to});
    hanoi(n - 1, by, from, to);
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 2, 3);
    return answer;
}