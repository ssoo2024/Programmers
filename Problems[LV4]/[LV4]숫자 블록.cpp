#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for(long long i = begin; i <= end; i++){
        int size = answer.size();
        for(long long j = 2; j <= sqrt(i); j++){
            if(i % j == 0 && i / j <= 10000000){
                answer.push_back(i / j);
                break;
            }    
        }
        if(size == answer.size())
            answer.push_back((i == 1 ? 0 : 1));
    }
    return answer;
}