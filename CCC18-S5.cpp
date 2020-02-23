#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, p, q, blk[2], a[200000], b[200000], c[200000], rep[2][100000]; //p connect col, q connect row
bool pq[200000]; //0 p 1 q;
ll ans;
vector <int> idx;
bool csort (int i1, int i2){ return c[i1] < c[i2]; }
int find (bool rc, int x){
    if (rep[rc][x] == x) return x;
    return rep[rc][x] = find(rc, rep[rc][x]);
}
void join (bool rc, int X, int Y){
    int x = find(rc, X);
    int y = find (rc, Y);
    rep[rc][x] = y;
}
int main (){
    scanf("%i%i%i%i", &n, &m, &p, &q);
    for (int i = 0; i < p+q; ++i){
        scanf("%i%i%i", &a[i], &b[i], &c[i]);
        --a[i];
        --b[i];
        pq[i] = i<p;
        idx.push_back(i);
        ans += (ll)c[i]*(ll)(pq[i]?n:m);
    }
    sort (idx.begin(), idx.end(), csort);
    for (int i = 0; i < max(m, n); ++i)
        rep[0][i] = rep[1][i] = i;
    blk[0] = n;
    blk[1]=m;
    for (int i : idx){
        if (find(pq[i], a[i]) == find(pq[i], b[i])) continue;
        join(pq[i], a[i], b[i]);
        --blk[pq[i]];
        ans -= (ll)c[i]*blk[!pq[i]];
    }
    printf("%lli", ans);
    return 0;
}
