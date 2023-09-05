#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

signed main(){
    nono_is_handsome

    int n, w;
    cin>>n>>w;
    vector<int> x(n), y(n);
    for(int i=1;i<n;i++)   cin>>x[i];
    for(int i=1;i<n;i++)   cin>>y[i];

    int cur = w;
    for(int i=1;i<n;i++){
        cur += x[i-1];
        cur -= y[i-1];

        if (y[i]>cur){
            cout<<i<<'\n';
            return 0;
        }
    }

    cout<<0<<'\n';
    return 0;
}