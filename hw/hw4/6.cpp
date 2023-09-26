#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 1e3+5;
int a[N][N];

signed main(){
    nono_is_handsome

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        for(int j=0;j<d;j++){
            int x;
            cin>>x;
            a[i][x] = 1;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j];
            if(j!=n-1)  cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}