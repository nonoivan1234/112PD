#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

int Gcd(int a, int b){
    return b ? Gcd(b, a % b) : a;
}

int gcd(int a, int b, int c){
    return Gcd(Gcd(a, b), c);
}

signed main(){
    nono_is_handsome

    int a, b, c;
    cin >> a >> b >> c;

    cout << gcd(a, b, c) << '\n';

    return 0;
}