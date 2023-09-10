#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

int gcd(int a, int b);

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

signed main(){
    nono_is_handsome

    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << '\n';

    return 0;
}