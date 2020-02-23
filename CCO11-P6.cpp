#include <bits/stdc++.h>
using namespace std;
int n, m, t, h[10001], ans;
bool tre [10001][10001];
stack <int> s;
int main(int argc, const char * argv[]) {
    scanf("%i%i%i", &n, &m, &t);
    ++n; ++m;
    for (int r, c, i = 0; i < t; ++i){
        scanf("%i%i", &r, &c);
        tre[r][c] = 1;
    }
    for (int i = 0; i < m; ++i) h[i] = -1;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) ++h[j];
        for (int j = 0; j < m; ++j){
            while (!s.empty()&&h[s.top()]>h[j]){
                int tmp = s.top();
                s.pop();
                int w = j-(s.empty()?0:s.top());
                ans = max(ans, h[tmp]*w);
            }
            s.push(j);
        }
        while (!s.empty()){
            int tmp = s.top();
            s.pop();
            int w = (m-1)-((s.empty())?0:s.top());
            ans = max(ans, h[tmp]*w);
        }
        for (int j = 0; j < m; ++j) if (tre[i][j]) h[j] = 0;
        
    }
    printf("%i\n", ans);
    return 0;
}
