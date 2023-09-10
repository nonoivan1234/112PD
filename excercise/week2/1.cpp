#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

int min(int a, int b);

int min(int a, int b){
    return a < b ? a : b;
}

signed main(){
    nono_is_handsome

    int a, b;
    cin >> a >> b;

    cout << min(a, b) << '\n';

    return 0;
}