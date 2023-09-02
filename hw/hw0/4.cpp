#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    int tmp, n, x, ans=0;
    cin>>n>>x;
    while(n--){
        cin>>tmp;
        if (tmp>=x*12)    ans++;
    }
    cout<<ans<<"\n";
}