#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[500];
bool dp [500][24403];
bool gsort (int x, int y){ return x>y; }
int main() {
    scanf("%i", &n);
    for (int i = 0; i < n; i++) scanf("%i", &a[i]);
    dp[0][0] = dp[1][0] = 1;
    sort(a, a+n, gsort);
    for (int i = 2; i < n; i++){
        ll x = 1;
        ll y = 0;
        for (int j = 1; j < i; j++){
            ll z = a[j]-a[i];
            if ((x&((ll)1<<z))==0) x += (ll)1<<z;
        }
        for (int j = 0; j < 24403; j++){
            y<<=1;
            y%=((ll)1<<(ll)51);
            y+=dp[i-1][j];
            dp[i][j] = ((y&x)!=0);
        }
    }
    for (int i = 0; i < 24403; i++){
        if (dp[n-1][i]) printf("%i ", i);
    }
    return 0;
}
