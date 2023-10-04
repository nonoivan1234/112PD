#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    string a, b;
    getline(cin, a);
    getline(cin, b);
    for(int i=0;i<a.size();i++){
        if(a[i]>='A' && a[i]<='Z'){
            a[i] = a[i] - 'A' + 'a';
        }
    }

    for(int i=0;i<b.size();i++){
        if(b[i]>='A' && b[i]<='Z'){
            b[i] = b[i] - 'A' + 'a';
        }
    }

    int n = b.size();
    for(int i=0; i+n < a.size(); i++){
        if(a.substr(i, n) == b){
            cout<<1<<'\n';
            return 0;
        }
    }

    cout<<0<<'\n';
}