#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

int *maxAddr(int *a, int *b){
    int *c = a;
    if (*b > *a)  c = b;

    return c;
}

signed main(){
    nono_is_handsome

    int a, b;
    cin >> a >> b;

    cout << *maxAddr(&a, &b) << endl;
}