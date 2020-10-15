#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;

int solution(vector<int> food_times, long long k) {
    priority_queue<ll, vector<ll>, greater<ll>> q;
    list<pair<ll,ll>> food;
    ll answer, m = 987654321, n = food_times.size();
    
    for(int i = 0; i < food_times.size(); i++){
        food.push_back({food_times[i], i});
        m = min(m, (ll)food_times[i]);
    }
    
    if(m * n > k) return k % n;
    
    while(k){
        ll eat = m;
        for(auto it = food.begin(); it != food.end();){
            it->first -= min(eat, k);
            k -= min(eat, k);
            
            if(k <= 0) {
                ++it;
                if(it == food.end()) it = food.begin();
                return it->second + 1;
            }

            if(it->first == 0){
                it = food.erase(it);
            }
            else{
                it++;
                m = min(m, it->first);
            }
        }
        if(food.size() == 0) break;
    }
    
    return -1;
}

/*

2 3 4 2 6, k=11
0 1 2 0 4


*/