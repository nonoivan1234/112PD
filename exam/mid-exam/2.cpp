#include<bits/stdc++.h>
using namespace std;
#define nono_is_handsome cin.tie(0); ios_base::sync_with_stdio(0);
#define int long long
const int INF = 1e9;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int diff(int m1, int d1, int m2, int d2){
    int tmp1 = d1, tmp2 = d2;
    for(int i = 1; i < m1; i++) tmp1 += days[i];
    for(int i = 1; i < m2; i++) tmp2 += days[i];
    
    return abs(tmp1 - tmp2) - 1;
}

signed main(){
    nono_is_handsome
    
    int n;
    cin >> n;
    int m[n], d[n];
    for(int i = 0; i < n; i++)  cin >> m[i] >> d[i];

    int mn = INF;
    for(int i = 0; i < n-1 ; i++){
        mn = min(mn, diff(m[i], d[i], m[i+1], d[i+1]));
    }

    cout << mn << '\n';
}