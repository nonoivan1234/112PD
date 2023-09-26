#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long

int *maxPtr(int *a, int *b){
    return *a > *b ? a : b;
}

signed main(){
    nono_is_handsome

    int a = 0, b = 0;
    cin >> a >> b;

    cout << *maxPtr(&a, &b) << endl;
}