#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map <int, ll> hm;
int n;
ll dp (int x){
    if (hm.find(x) != hm.end()) return hm[x];
    ll ans = 0;
    int pre = x;
    for (int i = 2; i <= (int)sqrt(x); ++i){
        int cur = x/i;
        ans += dp(i-1)*(ll)(pre-cur);
        pre=cur;
    }
    for (int i = x/(int)sqrt(x); i >= 2; --i)  ans += dp(x/i);
    hm.insert(make_pair(x, ans));
    return ans;
}
int main (){
    scanf("%i", &n);
    hm.insert(make_pair(1, 1));
    hm.insert(make_pair(2, 1));
    hm.insert(make_pair(3, 2));
    printf("%lli\n", dp(n));
}
