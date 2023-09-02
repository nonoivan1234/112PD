#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    int s, x;
    cin>>s>>x;
    if (s==1){
        cout<<x*12<<"\n";
    }
    else{
        cout<<x/12<<","<<x%12<<"\n";
    }
}