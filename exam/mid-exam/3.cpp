#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 25;
int n, k;
int x[N], y[N], c[N], p[N];

int value(){
    int val = 0;
    for(int i = 0; i < n; i++){
        val += p[i]*min(x[i], y[i]) - c[i]*x[i];
    }

    return val;
}

signed main(){
    nono_is_handsome
    
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> c[i] >> p[i];

    int ans = value();
    for(int i = 0; i < n; i++){
        x[i] += k;
        ans = max(ans, value());
        x[i] -= k;
    }

    cout << ans << '\n';
}