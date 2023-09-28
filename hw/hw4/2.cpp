#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 3;

signed main(){
    nono_is_handsome

    int v[3];
    for(int i = 0; i < 3; i++) cin >> v[i];
    sort(v, v + 3);

    cout<<v[1]<<"\n";
    return 0;
}