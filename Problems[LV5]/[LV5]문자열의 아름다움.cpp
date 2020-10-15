#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll tree[27][300001], dp[300001], pos[27];

ll sum(char a, ll i){
    ll ans = 0;
    while(i > 0){
        ans += tree[a-'a'][i];
        i -= (i & -i);
    }
    return ans;
}

void update(ll n, char a, ll i, ll plus){
    while(i <= n){
        tree[a-'a'][i] += plus;
        i += (i & -i);
    }
}

ll solution(string s) {
    ll answer = 0, n = s.size();
    
    s = ("0"+s);
    for(ll i = 1; i <= n; i++){
        ll tmp = (i*pos[s[i]-'a'])-sum(s[i], pos[s[i]-'a']);
        dp[i] = max(dp[i-1], tmp);
        answer += dp[i];
        
        //cout << dp[i] << " ";
        
        for(char a = 'a'; a <= 'z'; a++){
            if(a != s[i]){
                while(++pos[a-'a'] <= i){
                    update(n, a, pos[a-'a'], i);
                } pos[a-'a']--;
            }
        }
    } 
    //cout << endl;
    
//     for(char a = 'a'; a <= 'b'; a++){
//         for(int i = 1; i <= n; i++){
//             cout << sum(a, i)-sum(a, i-1) << " ";
//         } cout << endl;
//     }
    
    return answer;
}