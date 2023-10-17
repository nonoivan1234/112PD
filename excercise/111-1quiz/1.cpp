#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome
    
    int x, y, z;
    cin >> x >> y >> z;

    if(x == y && y == z)    cout << 1 << "\n";
    else if(x != y && y != z && z != x) cout << 2 << "\n";
    else    cout << 3 << "\n";

    return 0;
}