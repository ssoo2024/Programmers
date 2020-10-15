#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int ans = dist.size() + 1;
    vector<int> linear_weak(weak);
    
    do{
        for(int start = 0; start < weak.size(); start++){
            for(int i = 0; i < linear_weak.size(); i++){
                if(start + i >= linear_weak.size())
                    linear_weak[i] = weak[(start + i) % linear_weak.size()] + n;
                else
                    linear_weak[i] = weak[start + i];   
            }
            
            int from = 0, cnt = 0;          
            for(int i = 0; i < linear_weak.size(); i++){
                if((cnt < dist.size()) && (linear_weak[i] > linear_weak[from] + dist[cnt])){
                    from = i;
                    cnt++;
                }
            }
            ans = min(ans, cnt + 1);
        }
    }while(next_permutation(dist.begin(), dist.end()));
    
    return (ans > dist.size() ? -1 : ans);
}