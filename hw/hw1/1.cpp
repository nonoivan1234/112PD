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
    for(int i=0;i<n-1;i++){
        int tmp;
        cin>>tmp;
        w -= tmp;
    }

    cout<<w<<'\n';
    return 0;
}