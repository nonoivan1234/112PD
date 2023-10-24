#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome
    
    int x, y, c, p;
    cin >> x >> y >> c >> p;

    cout << p*min(x, y) - c*x << "\n";
}