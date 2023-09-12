#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int N = 25;
int x[N], y[N];

signed main(){
    nono_is_handsome

    int n, w, k;
    cin >> n >> w >> k;

    for(int i=1;i<n;i++)   cin>>x[i];
    for(int i=1;i<n;i++)   cin>>y[i];

    int now = w;

    for(int i=1;i<n;i++){
        bool ok1=0, ok2=0;
        if (now<y[i])   ok1=1;

        now += x[i]-y[i];
        if (now>k)  ok2=1;

        if (ok1 && ok2) return cout<<i<<",B\n", 0;
        if (ok1)    return cout<<i<<",N\n", 0;
        if (ok2)    return cout<<i<<",C\n", 0;
    }

    cout<<"0\n";

    return 0;
}