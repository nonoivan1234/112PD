#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    int q, a, b;
    cin>>q;
    while(q--){
        cin>>a>>b;
        if (a==1){
            cout<<b*12<<"\n";
        }
        else{
            cout<<b/12<<","<<b%12<<"\n";
        }
    }
}