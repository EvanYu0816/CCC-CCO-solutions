#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int l, t, bit[3001][3001], min1 = 1e9, min2=1e9;
bool ocp[2001][1001];
void upd (int r, int c, int v){
    while (c <= 3000){ bit[r][c] += v; c+=(c&-c); }
}
int qry (int r, int c){
    int ans = 0;
    while (c){ ans += bit[r][c]; c-=(c&-c); }
    return ans;
}
void upd2 (int r, int c, int v){
    while (r <= 3000){ upd(r, c, v); r+=(r&-r); }
}
int qry2 (int r, int c){
    int ans = 0;
    while (r){ ans += qry(r, c); r-=(r&-r); }
    return ans;
}
int main (){
    scanf("%i%i", &l, &t);
    for (int r, c, i = 0; i < t; ++i){
        char op; scanf(" %c%i%i", &op, &r, &c);
        if (op == 'E' && r <= 2000){
            ocp[r][c] = 1;
            upd2 (r-c+1000, r+c, 1);
        } else if (op == 'L' && r <= 2000){
            ocp[r][c] = 0;
            upd2 (r-c+1000, r+c, -1);
        } else if (op == 'S'){
            if (ocp[r][c]|| c+1 > 1000 || ocp[r][c+1]) printf("No\n");
            else printf("%i\n", qry2(r-c+1000, r+c)+qry2(r-c+999, r+c+1));
        }
    }
    for (int i = 1; i <= 1000; ++i){
        int cnt = 0;
        for (int j = l+1; j <= 2000 && cnt < 2; ++j){
            if (ocp[j][i]) continue;
            int tmp = qry2(j-i+1000, i+j);
            if (tmp <= min1){
                min2 = min1;
                min1 = tmp;
            } else min2 = min(tmp, min2);
            ++cnt;
        }
    }
    printf("%i", min1+min2);
}
