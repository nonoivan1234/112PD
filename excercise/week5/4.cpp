#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    int n;
    cin>>n;
    string c;
    cin>>c;
    for(int i = 0; i < c.size(); i++){
        if(c[i] >= 'A' && c[i] <= 'Z'){
            c[i] = c[i] - 'A' + 'a';
        }
    }

    int ok = 0;
    string s;
    while(n--){
        cin>>s;
        if(s==c)    ok = 1;
    }

    cout<<ok<<'\n';
}