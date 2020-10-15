#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int answer, from, to, ind = 1;

int solution(int n, vector<int> stations, int w) {
    vector<pair<int, int>> interval;
    stations.push_back(n+w+1);
    stations.insert(stations.begin(), -w);
    
    while(ind < stations.size()){
        from = stations[ind - 1]+w+1;
        to = stations[ind++]-w-1;
        answer += max(0, (int)ceil(double(to-from+1)/double(w+w+1)));
    }

    return answer;
}