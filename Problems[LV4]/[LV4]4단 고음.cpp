#include <string>
#include <iostream>
using namespace std;
typedef long long ll;

ll ans;

void find(ll cur, ll dst){
    cout << "cur:" << cur << " dst:" << dst << endl;
    if(cur == dst) ++ans;
    if(cur >= dst) return;
    
    find(cur*3, dst-2);
    find(cur*3+1, dst-1);
    find(cur*3+2, dst);
}

int solution(int n) {
    find(1LL, (ll)n);
    return (int)ans;
}