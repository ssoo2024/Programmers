#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
typedef long long ll;

unordered_map<ll,ll> m;

ll find(ll me){
    return (m.find(me)==m.end()) ? (me) : (m[me] = find(m[me]));
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer(room_number);
    
    for(int i = 0; i < room_number.size(); i++){
        auto ret = m.insert({room_number[i],room_number[i]+1});
        if(!ret.second){
            answer[i] = find(room_number[i]);
            m.insert({answer[i],answer[i]+1});
        }
    }
    
    return answer;
}