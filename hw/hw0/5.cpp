#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    int n, x, a, b;
    int ans[3];
    memset(ans, 0, sizeof(ans));
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if (a>=x*12)    ans[b-1]++;
    }
    cout<<ans[0]<<","<<ans[1]<<","<<ans[2]<<"\n";
}