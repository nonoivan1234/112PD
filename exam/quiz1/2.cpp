#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome
    
    int n, B;
    cin >> n >> B;

    int now = 0;
    for(int i = 0; i < n; i++){
        int x, y, c, p;
        cin >> x >> y >> c >> p;
        now += p*min(x, y) - c*x;
    }

    if(now >= B) cout << now << ",great\n";
    else cout << now << ",sad\n";
}