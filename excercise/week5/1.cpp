#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    char c;
    int cnt = 0;
    while(cin>>c){
        if (c==',' || c=='.' || c==':' || c==';' || c=='!' || c=='?'){
            cnt++;
        }
    }

    cout<<cnt<<'\n';
}