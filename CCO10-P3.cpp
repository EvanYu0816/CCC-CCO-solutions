#include <bits/stdc++.h>
using namespace std;

int n, xk[1000000], r[1000000], bit[1000001], xr[1000001];
char op[1000000];
vector <int> rt;
unordered_map<int, int> vc, rx;
void upd (int i, int val){
    while (i <= 1000000){ bit[i]+=val; i += (i&-i); }
}
int qry (int k){
    int sum = 0;
    int cur = 0;
    for (int i = 19; i >= 0; --i){
        if (sum + bit[cur+(1<<i)] < k){
            cur += (1<<i);
            sum += bit[cur];
        }
    }
    if (sum < k) ++cur;
    return cur;
}
int main(int argc, const char * argv[]) {
    scanf("%i", &n);
    for (int i = 0; i < n; ++i){
        scanf(" %c%i", &op[i], &xk[i]);
        if (op[i] != 'Q'){ scanf("%i", &r[i]); rt.push_back(r[i]); }
    }
    sort (rt.begin(), rt.end(), greater<int>());
    for (int i = 0; i < n; ++i) vc.insert({rt[i], i+1});
    for (int i = 0; i < n; ++i){
        if (op[i] == 'N'){
            xr[xk[i]] = r[i];
            rx.insert({r[i], xk[i]});
            upd (vc[r[i]], 1);
        } else if (op[i] == 'M'){
            rx.erase(xr[xk[i]]);
            upd (vc[xr[xk[i]]], -1);
            xr[xk[i]] = r[i];
            rx.insert({r[i], xk[i]});
            upd (vc[r[i]], 1);
        } else printf("%i\n", rx[rt[qry(xk[i])-1]]);
        
    }
    return 0;
}
