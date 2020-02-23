#include <bits/stdc++.h>
using namespace std;
int tc,n,b,w, pin[30001], dp[30001][501], s[30001];
int main(int argc, const char * argv[]) {
    scanf("%i", &tc);
    for (int h = 0; h < tc; ++h){
        scanf("%i%i%i", &n, &b, &w);
        for (int i = 1; i <= n; ++i) scanf("%i", &pin[i]);
        for (int i = 1; i <= n; ++i)
            s[i] = s[i-1]+pin[i]-pin[max(i-w, 0)];
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= b; ++j){
                dp[i][j] =
                max(dp[i-1][j], dp[max(i-w, 0)][j-1]+s[i]);
            }
        }
        printf("%i\n", dp[n][b]);
        
    }
    return 0;
}
