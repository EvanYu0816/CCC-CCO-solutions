#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, w, p[201], mod = 1000000007;
ll ans[201][201][2], dp[201][201], tmp, tmp1, tmp2;
vector <int> c[201], df[201];
bool vis[201][2];
void dfs (int u, bool tp){ //1 = ww
    if (vis[u][tp]) return;
    vis[u][tp]=1;
    for (int i = 0; i < c[u].size(); ++i){
        if (tp) dfs(c[u][i], df[u][i]);
        else { dfs(c[u][i], 0); dfs(c[u][i], 1); }
    }
    dp[0][tp] = 1;
    for (int i = 1; i <= c[u].size(); ++i){
        for (int j = 0; j <= w; ++j){
            for (int k = 0; k <= j; ++k){
                if (tp) tmp = dp[i-1][j-k]*
                    ans[c[u][i-1]][k][df[u][i-1]];
                else tmp = dp[i-1][j-k]*
                    (ans[c[u][i-1]][k][0]+ans[c[u][i-1]][k][1]);
                dp[i][j] += tmp;
                dp[i][j]%=mod;
            }
        }
    }
    for (int i = 0; i <= w; ++i) ans[u][i][tp] = dp[c[u].size()][i];
    memset(dp, 0, sizeof(dp));
}
int main(int argc, const char * argv[]) {
    scanf("%i%i%i", &n, &w, &m);
    for (int u, v, i = 0; i < m; ++i){
        char ch; scanf(" %c%i%i", &ch, &u, &v);
        p[v]=u;
        c[u].push_back(v);
        df[u].push_back(ch=='D');
    }
    for (int i = 1; i <= n; ++i)
        if (!p[i]){ c[0].push_back(i); df[0].push_back(0); }
    dfs (0, 0);
    printf("%lli", ans[0][w][0]);
    return 0;
}
